struct {
  struct spinlock lock;
  int use_lock;
  struct run *freelist;
  uint free_pages; //stores number of free pages (CH)
  uint pg_recount[PHYSTOP >> PTXSHIFT]; // Stores reference count (SG)
} kmem;

void inc_count(uint *);
void dec_count(uint *);
uint get_count(uint *);
