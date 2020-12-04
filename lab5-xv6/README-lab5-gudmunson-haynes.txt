Task 1:
	*syscall.h: Added syscall definition for getNumFreePages
        *defs.h: numFreePages() under kalloc.c
        *kalloc.c: Functional code for syscall (added uint free_pages to kmem structure)
        *user.h: getNumFreePages()
        *sysproc.c: int sys_getNumFreePages()
        *usys.S: SYSCALL(getNumFreePages)
        *syscall.c: Added functional code for syscalls

Task 2: 
        defs.h: added inc_count() and dec_count() under kalloc.c
        kalloc.c: added code for inc_count and dec_count
        syscall.h: definitions
        sysproc.c: varible passing
        user.h: definitions
        usys.S: syscalls

Task 4: 
        defs.h: changing definition of inc_count and dec_count 
        kalloc.c changed pg_count implementation
        kalloc.h added definitions
        Makefile: testcow
        testcow.c: added file
        vm.c: added functional code

Task 5: 
        Makefile: testcow
        testcow.c: added file