// Test that fork fails gracefully.
// Tiny executable so that the limit can be filling the proc table.

#include "types.h"
#include "stat.h"
#include "user.h"

#define N  1000


void
testcow(void)
{
  int n, pid, var;

  var = 0;

  printf(1, "fork test\n");

  for(n=0; n<N; n++){
    pid = fork();
    if(pid < 0)
      break;
    if(pid == 0){
      printf(1, "var address: %d", &var);
      printf(1, "number of free pages before write: %d", getNumFreePages());
      var++;
      printf(1,"var:%d\n", var);
      printf(1, "number of free pages after write: %d", getNumFreePages());

      exit();

    }
  }

  if(n == N){
    printf(1, "fork claimed to work N times!\n", N);
    exit();
  }

  for(; n > 0; n--){
    if(wait() < 0){
      printf(1, "wait stopped early\n");
      exit();
    }
  }

  if(wait() != -1){
    printf(1, "wait got too many\n");
    exit();
  }

  printf(1, "fork test OK\n");
}

int
main(void)
{
  testcow();
  exit();
}