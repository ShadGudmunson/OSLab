#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int 
sys_set_priority(void)
{
  int pid;
  int priority;
  argint(0, &pid);
  argint(1, &priority);

  if(pid < 0){
    return -1;
  }
  if(priority < 0 && priority >= 40){
    return -1;
  }
  
  return set_priority(pid, priority);

}
int 
sys_get_priority(void)
{
  int pid; 
  argint(0, &pid);

  return get_priority(pid);
}

int sys_cps(void)
{
  return cps();
}

int sys_thread_create(void (*fn)(void *), void *stack, void *arg)
{
  return thread_create(fn, stack, arg);
}

int sys_thread_join(void)
{
  return thread_join();
}

int sys_thread_exit(void)
{
  return thread_exit();
}

int sys_lock_acquire(struct lock_t *lk)
{
  return lock_acquire(lk);
}

int sys_lock_release(struct lock_t *lk)
{
  return lock_release(lk);
}

int sys_lock_init(struct lock_t *lk)
{
  return lock_init(lk);
}
