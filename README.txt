MALLOC LAB

For this lab i implemented NextFit  implementation and impleneted wat Dr Freudenthal asked us to modify (Resize Function).

For this lab i collaborated with:
Ulised Martinez who helped me to get an idea of how prefixes and sufixes worked.
Elsa Gonzalez in debugging purposses
Danner Pacheco debugging  purposses

Dr Freudenthal Code was really useful to implement what we were asked to do.

This directory contains:

myAllocator.c: a first-fit allocator
myAllocator.h: its header file

myAllocatorTest1.c: a test program for my allocator 

malloc.c: a replacement for malloc that uses my allocator
test1.c: a test program that uses this replacement malloc

Makefile: a fairly portable "makefile", targets "all" and "clean"

To compile: 
 $ make 
To clean:
 $ make clean

The cygwin runtime uses malloc() and brk() extensively.  It is
interesting to compare the output of test1 & myAllocatorTest1.  All
those extra allocated regions are being used by cygwin's libraries!


