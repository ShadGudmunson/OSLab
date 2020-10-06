/* File: lab2test.c */
/* Author: Casey Haynes */
/* User-level driver program to test new syscalls set_priority and get_priority */

#include "types.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "x86.h"
#include "proc.h"
#include "spinlock.h"

int main (int argc, char *argv[]) {

	int pid = 1;
	int priority = 13;


	set_priority(pid, priority);
	int check = get_priority(pid); //Call get_priority and make a check for out-of-bounds errors

	if (check < 0 || check > 39) { //Check to see if nice value is in range.
		return -1; //Throw error if priority is out of range
	}
	exit();
}
