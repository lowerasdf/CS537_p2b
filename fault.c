#include "types.h"
#include "stat.h"
#include "fcntl.h"
#include "user.h"

int main(int argc, char *argv[]) {
   int *p = (int *) atoi(argv[1]);
   printf(2, "Address at p has value: %x\n", *p);
   exit();
}