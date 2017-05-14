#include "types.h"
#include "stat.h"
#include "user.h"
#include "traps.h"

#define N 3

unsigned long next=1;
int randomGen(int rand_max){
   next = next * 1103515245 + 12345;
   int rand=((unsigned)(next/65536) % 32768);
   //above are the default implemenation of random generator with random max value 32768
   //need to map it to the 
   int result =rand % rand_max+1;
   return result;
}

void
test(void)
{
  int n, pid;
  int c = 0;

  printf(1, "test\n");

  for(n=0; n<N; n++){
    pid = fork();
    if(pid < 0){
      
    }
    if(pid == 0){
      exit();
    }
    if(pid > 0){

      if(c < N){
        int pid2 =fork();
        if(pid2 == 0){
          exit();
        }
        if(pid2> 0){
          sleep(randomGen(randomGen(300)));
          printf(1, "%d\n", pid2);
        }
        c++;
      }
      sleep(randomGen(randomGen(300)));
      printf(1, "%d\n", pid);
    }
  }
}

int
main(void)
{
  test();
  printf(1, "finished!\n");
  exit();
}
