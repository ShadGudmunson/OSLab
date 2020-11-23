typedef unsigned int   uint;
typedef unsigned short ushort;
typedef unsigned char  uchar;
typedef uint pde_t;
typedef struct _lock_t {
	unsigned int lock;
}lock_t;

#define UNLOCKED 0
#define LOCKED 1
