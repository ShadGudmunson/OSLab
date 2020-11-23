README -- LAB4 -- Casey Haynes

*syscall.h: Defined: 
		SYS_thread_create, 
		SYS_thread_join, 
		SYS_thread_exit, 
		SYS_lock_acquire, 
		SYS_lock_release, 
		SYS_lock_init

*defs.h: Added function definitions for:
		int thread_create(void (*fn)(void*), void*, void*),
		int thread_join(void),
		int thread_exit(void),
		int lock_acquire(struct lock_t *),
		int lock_release(struct lock_t *),
		int lock_init(struct lock_t *)

*user.h: Added functions the same as defs.h

*sysproc.c: Added function behaviors for the above functions like so...
	int
	sys_thread_create(void (*fn)(void*), void *stack, void *arg)
	{
		return thread_create(fn, stack, arg);
	}
	etc...

*usys.S: Added syscalls:
		SYSCALL(thread_create),
		SYSCALL(thread_join),
		SYSCALL(thread_exit),
		SYSCALL(lock_acquire),
		SYSCALL(lock_release),
		SYSCALL(lock_init)

*syscall.c: Added real functions:
		extern int sys_thread_create(void),
		extern int sys_thread_join(void),
		extern int sys_thread_exit(void),
		extern int sys_lock_acquire(void),
		extern int sys_lock_release(void),
		extern int sys_lock_init(void)

		AND

		[SYS_thread_create]  sys_thread_create,
		[SYS_thread_join]    sys_thread_join,
		[SYS_thread_exit]    sys_thread_exit,
		[SYS_lock_acquire]   sys_lock_acquire,
		[SYS_lock_release]   sys_lock_release,
		[SYS_lock_init]      sys_lock_init

*proc.h
	Added stack attribute to proc structure (for thread_create()). 

*proc.c
	Added code for all 6 of the above syscalls in proc.c (all at the end of the file)

*types.h
	Defined lock_t structure
	Defined LOCKED 
	Defined UNLOCKED		

*threads_nosync.c
	Added mutex lock init, acquire, and release in do_work()
	Changed name to threads_sync.c

*Makefile
	Added _threads_sync\ to UPROGS
	Added threads_sync.c to EXTRA section
