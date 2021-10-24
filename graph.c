#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "pstat.h"

int main(int argc, char *argv[]) {
    int pid1 = fork();
    if (pid1 < 0) {
        printf(2, "Fork child process 1 failed\n");
    } else if (pid1 == 0) { // child process 1
        settickets(3);
        int x = 0;
        while(1)
            x += 1;
        exit();
    } 
  
    int pid2 = fork();
    if (pid2 < 0) {
        printf(2, "Fork child process 2 failed\n");
        exit();
    } else if (pid2 == 0) { // child process 2
        settickets(2);
        int x = 0;
        while(1)
            x += 1;
        exit();
    }
    
    int pid3 = fork();
    if (pid2 < 0) {
        printf(2, "Fork child process 3 failed\n");
        exit();
    } else if (pid2 == 0) { // child process 3
        int x = 0;
        while(1)
            x += 1;
        exit();
    }

    sleep(1000);
    
    struct pstat p;
    getpinfo(&p);

    kill(pid1);
    kill(pid2);
    kill(pid3);

    wait();
    wait();
    wait();

    printf(2, "child 1 pid: %d, child 2 pid: %d, child 3 pid: %d\n", pid1, pid2, pid3);

    // int size = NPROC;
    int size = 10;
    for(int i = 0; i < size; i++) {
        printf(2, "Process pid=%d, used=%d, ticket=%d, tick=%d\n", p.pid[i], p.inuse[i], p.tickets[i], p.ticks[i]);
    }

    printf(2, "Done\n");
}