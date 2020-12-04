Task 1:
	*syscall.h: Added syscall definition for getNumFreePages
        *defs.h: numFreePages() under kalloc.c
        *kalloc.c: Functional code for syscall (added uint free_pages to kmem structure)
        *user.h: getNumFreePages()
        *sysproc.c: int sys_getNumFreePages()
        *usys.S: SYSCALL(getNumFreePages)
        *syscall.c: Added functional code for syscalls

