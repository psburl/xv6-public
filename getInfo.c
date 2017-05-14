#include "types.h"
#include "user.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "x86.h"
#include "proc.h"
#include "spinlock.h"
#include "pstat.h"


struct {
  struct spinlock lock;
  struct proc proc[NPROC];
} ptable;


void
getInfo()
{   
     struct pstat ap;
     getpinfo(&ap);

    // printf(1, "%d\t\n", ap.inuse[0]);
}


int
main(int argc, char *argv[])
{
    getInfo();
    exit();
}