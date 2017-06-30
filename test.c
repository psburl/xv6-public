#include "types.h"
#include "stat.h"
#include "user.h"
#include "traps.h"
#include "param.h"

#define N 4

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

    int g;
     for( g = 0; g < 3; g++)
        tickets = tickets*counter;

    int pid = fork(tickets);

    int i,j, k ;

    if(pid == 0){
      new_fork(lcg_rand()%1000);
    }

    if(pid > 0){
        printf(1, "start process %d tickets : %d\n", pid, tickets);
        for( i = 0; i < 20; i++){
             for( j = 0; j < 10; j++){
             for( k = 0; k < 2000000; k++){
               printf(1, "");
             }
        }
            printf(1, "running process %d tickets : %d\n", pid, tickets);
        }
         printf(1, "fiished process %d tickets : %d\n", pid, tickets);
    }

    wait();
    exit();
}

int
main(void)
{
  printf(1, "test\n");
  new_fork(lcg_rand()%1000);
  exit();
}
