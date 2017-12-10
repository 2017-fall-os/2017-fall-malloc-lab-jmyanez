#MALLOC LAB

For this lab i implemented NextFit  implementation and impleneted wat Dr Freudenthal asked us to modify (Resize Function).

For this lab i collaborated with:
Ulised Martinez who helped me to get an idea of how prefixes and sufixes worked.
Elsa Gonzalez in debugging purposses
Danner Pacheco debugging  purposses

Dr Freudenthal Code was really useful to implement what we were asked to do.

#ATTENTION!!! CHANGES DONE IN 12/10/2017
Hello Adrian!

I used the feedback from the excel spreadsheet to fix the issues with my lab
1- I was calling last alloc in resize region, now i am calling
NextAllocRegion
2- I did not modify the test for my program, now i am allocating 4 chunks of memory after allocating the 4 i change the value of lastAlloc to p1, and
mark it as not allocated, then i do malloc again to p1 and its allocated.
Also here what i did was in malloc change firstFit(The default) to
NextFit so i did not had to modify all the malloc calls.

os-malloc
This directory contains:

myAllocator.c: a first-fit allocator
myAllocator.h: its header file

myAllocatorTest1.c: a test program for my allocator 

malloc.c: a replacement for malloc that uses my allocator
test1.c: a test program that uses this replacement malloc

There are two different testers as some implementations of printf
call malloc to allocate buffer space. This causes test1 to behave
improperly as it uses myAllocator as a malloc replacement. In this
case myAllocatorTest1 will function correctly. The only difference
between the programs is that test1 uses myAllocator as a malloc
replacement and myAllocatorTest1 uses myAllocator directly.

Makefile: a fairly portable "makefile", targets "all" and "clean"

To compile: 
 $ make 
To clean:
 $ make clean

The cygwin runtime uses malloc() and brk() extensively.  It is
interesting to compare the output of test1 & myAllocatorTest1.  All
those extra allocated regions are being used by cygwin's libraries!

