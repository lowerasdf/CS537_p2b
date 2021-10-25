# CS537 P2B: Scheduling and Virtual Memory in xv6
This is a modification of xv6 scheduler to utilize a stride scheduling policy, where each process is given a ticket as their weight such that it will be prioritized by the CPU scheduler in xv6. There is also an implementation of a null pointer dereference to enable a more robust debugging. The visualized graph of what the scheduler is doing can be found here: [graph.pdf](graph.pdf).

##### Table of Contents
* [Installation](#installation)
* [Implementation](#implementation)
  * [Scheduler](#scheduler)
  * [Null Pointer Dereference](#null-pointer-dereference)
* [Acknowledgement](#acknowledgement)

## Installation
To compile and run the program, run:
<pre><code>make qemu</code></pre>
Then:
<pre><code>graph</code></pre>
To run a user program that tests the scheduler implementation.

Or:
<pre><code>fault 0</code></pre>
To run a user program that tests the null pointer dereference implementation.

## Implementation
### Scheduler
First, <code>ticket</code> and <code>tick</code> are added to the struct <code>proc</code> in <code>proc.h</code> and their default values are set when a process is created with their parent's ticket. There are two system calls, <code>int settickets(int number)</code> and <code>int getpinfo(struct pstat *)</code>, to support the implementation of the scheduler as well as acting as debuggers (see [acknowledgement](#acknowledgement) for details). These user calls will call the kernel for both setting the number or getting the process info respectively. For getting the process info, there is a new function that handles this inside <code>proc.c</code>.

To implement the scheduler, the <code>scheduler</code> function was modified such that it repeats the same process until <code>p->tick % p->ticket == 0</code>, such that all processes will run <code>n</code> times according to their tickets.

### Null Pointer Dereference
The null pointer dereference is implemented by making sure that the user code does not go to the first address in the address space. This is also done by shifting all allocations of page table when <code>exec()</code> or <code>fork()</code> is called as well as making sure that any user program does not go to the first page (except for the xv6).

## Acknowledgement
This is an assignment for a class [Comp Sci. 537: Introduction to Operating Systems](https://pages.cs.wisc.edu/~remzi/Classes/537/Fall2021/) by [Remzi Arpaci-Dusseau](https://pages.cs.wisc.edu/~remzi/). Please refer to [this repo](https://github.com/remzi-arpacidusseau/ostep-projects/tree/master/scheduling-xv6-lottery) and [this repo](https://github.com/remzi-arpacidusseau/ostep-projects/tree/master/vm-xv6-intro) for more details about the assignment.
