// Create a zombie process that
// must be reparented at exit.

#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"

int
main(void)
{
  if(fork(DEFAULT_PROC_TICKETS) > 0)
    sleep(5);  // Let child exit before parent.
  exit();
}
