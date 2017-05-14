#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"

enum procstate { UNUSED, EMBRYO, SLEEPING, RUNNABLE, RUNNING, ZOMBIE };

// Per-process state
struct proc {
  uint sz;                     // Size of process memory (bytes)
  pde_t* pgdir;                // Page table
  char *kstack;                // Bottom of kernel stack for this process
  enum procstate state;        // Process state
  int pid;                     // Process ID
  struct proc *parent;         // Parent process
  struct trapframe *tf;        // Trap frame for current syscall
  struct context *context;     // swtch() here to run process
  void *chan;                  // If non-zero, sleeping on chan
  int killed;                  // If non-zero, have been killed
  struct file *ofile[NOFILE];  // Open files
  struct inode *cwd;           // Current directory
  char name[16];               // Process name (debugging)
  int tickets;                 // the number of tickets of proccess
};

int
main(int argc, char *argv[])
{  
  struct proc ptable[NPROC];
  struct proc *p;  

  
  p = &ptable[0];
  printf(1, " PID  PPID  STATE  CMD \n");
  while(p != &ptable[NPROC-1] && p->state != UNUSED){
  	printf(1,"%d  %d ",p->pid,p->parent->pid);
  	switch(p->state){
  	case UNUSED:
  		printf(1," %s ", "UNUSED");
  		break;
  	case EMBRYO:
  		printf(1," %s ", "EMBRYO");
  		break;
  	case SLEEPING:
  		printf(1," %s ", "SLEEPING");
  		break;
  	case RUNNABLE:
  		printf(1," %s ", "RUNNABLE");
  		break;
  	case RUNNING:
  		printf(1," %s ", "RUNNABLE");
  		break;
  	case ZOMBIE:
  		printf(1," %s ", "RUNNABLE");
  		break;
  	} 
  	printf(1," %s \n", p->name);
  	p++;
  }
  	  
  exit();
}