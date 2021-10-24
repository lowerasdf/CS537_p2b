#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "pstat.h"

int main(int argc, char *argv[]) {
    // int i;
    int x = 0;
    
    if (argc != 2) {
        exit();
    }

    // for (i=1; i < atoi(argv[1]); i++) {
    //     x += i;
    //     printf(2, "printing x=%d\n", x);
    // }

    int n = atoi(argv[1]);
    int setticketsStatus = settickets(n);
    printf(2, "settickets called with n = %d returns %d\n", n, setticketsStatus);

    // struct pstat p = {};
    // int getpinfoStatus = getpinfo(&p);
    // printf(2, "getpinfo called with returns %d\n", getpinfoStatus);

    // // int size = NPROC;
    // int size = 10;
    // for(int i = 0; i < size; i++) {
    //     printf(2, "Process pid=%d, used=%d, ticket=%d, tick=%d\n", p.pid[i], p.inuse[i], p.tickets[i], p.ticks[i]);
    // }

    exit();
    return x;
}