#include "types.h"
#include "stat.h"
#include "user.h"
#include "traps.h"
#include "param.h"

#define N 10

unsigned long next=1;

unsigned int lcg_rand()
{
    return ((unsigned long)next++ * 279470273UL) % 4294967291UL;
}

void 
wait_(unsigned int  seed)
{
  if(seed<=0)
    return;
  seed--;
  wait_(seed);
}

int counter = 0;

void new_fork(unsigned int tickets){
   
    if(counter >=  N)
      return;

    counter++;
    int pid = fork(tickets);

    if(pid == 0){
      new_fork(lcg_rand());
    }

    if(pid > 0){

        for(int i = 0; i < 2; i++){
          for(int j = 0; j < lcg_rand(); j++)
             for(int k = 0; k < j; k++)
                  wait_(lcg_rand());
          printf(1, "%d\n", pid);
        }
    }

    wait();
    exit();
}

void
test(void)
{
 
}

int
main(void)
{
  printf(1, "test\n");
  new_fork(lcg_rand());
  printf(1, "finished!\n");
  exit();
}
