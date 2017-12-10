#include "stdio.h"
#include "stdlib.h"
#include "myAllocator.h"
#include "sys/time.h"
#include <sys/resource.h>
#include <unistd.h>

double diffTimeval(struct timeval *t1, struct timeval *t2) {
  double d = (t1->tv_sec - t2->tv_sec) + (1.0e-6 * (t1->tv_usec - t2->tv_usec));
  return d;
}

void getutime(struct timeval *t)
{
  struct rusage usage;
  getrusage(RUSAGE_SELF, &usage);
  *t = usage.ru_utime;
}



int main() 
{
  
  void *p1, *p2, *p3,*p4;
  arenaCheck();
  p1 = malloc(50000);
  arenaCheck();
  p2 = malloc(800);
  arenaCheck();
  p3 = malloc(40);
  arenaCheck();
  p4= malloc(1200);
  printf("%8zx %8zx %8zx %8zx\n", p1, p2, p3, p4);
  printf("Changing last alloc to p1!\n");
  lastAlloc= regionToPrefix(p1);
  printf("Changin status of lastAlloc p1 to not allocated\n");
  lastAlloc->allocated=0;
  printf("Allocating a new quantity of memory to p1\n");
  printf("This Arena check shows the value of p1 before changing it\n");
  arenaCheck();
  p1=malloc(500);
  printf("Now this arena check shows the new value for p1!\n");
  arenaCheck();
  free(p1);
  arenaCheck();
  free(p2);
  arenaCheck();
  free(p3);
  arenaCheck();
  free(p4);
  arenaCheck();
  {				/* measure time for 10000 mallocs */
    struct timeval t1, t2;
    int i;
    getutime(&t1);
    for(i = 0; i < 10000; i++)
      if (malloc(4) == 0) 
	break;
    getutime(&t2);
    printf("%d malloc(4) required %f seconds\n", i, diffTimeval(&t2, &t1));
  }
  return 0;
}



