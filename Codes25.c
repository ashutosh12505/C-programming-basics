/*Miscellaneous programs
WAP to copy data from one file to another*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
FILE *fs,*ft;
char ch;
fs=fopen("Poem.txt","r");
if(fs==NULL)
{
puts("Cannot open source file");
exit(1);
}
ft=fopen("Copy1.txt","w");
if(ft==NULL)
{
puts("Cannot open target file");
fclose(fs);
exit(2);
}
ch=fgetc(fs);
while(ch!=EOF)
{
fputc(ch,ft);
ch=fgetc(fs);
}
fclose(fs);
fclose(ft);
}
/* after the execution of the above program, there is no output on the console. it just copies the data from one file to another
WAP to count number of lines, blank spaces, characters and tabs in a file */
#include<stdio.h>
int main()
{
FILE *fp;
char ch;
int nol=1,not=0,nob=0,noc=0;
// no_of_lines 'nol' is initialised as 1, not 0 because it is counted by number of '\n' encountered, and for the first line, any '\n' is not encountered
fp=fopen("Blanks_Spaces_Characters_Tabs.txt","r");
ch=fgetc(fp);
while(ch!=EOF)
{
noc++;

if(ch==' ')
{
nob++;
}
else if(ch=='\n')
{
nol++;
}
else if(ch=='\t')
{
not++;
}
ch=fgetc(fp);
}
fclose(fp);
printf("\n Number of characters = %d",noc);
printf("\n Number of blanks = %d",nob);
printf("\n Number of tabs = %d",not);
printf("\n Number of lines = %d",nol);
return 0;
}

/*
Pointers

Definition : A pointer is a variable which stores the address of another variable

Applications :

[1] Call by reference
[2] Dynamic memory allocation (DMA)
    in C/C++, by default there is compile time memory allocation which results in wastage of memory. In C,we can achieve dynamic memory allocation by the functions - malloc();, calloc() and realloc().
[3] Pointer to structure => e.g. link lists
[4] Passing array to a function
[5] Implementation of data structures

DSA - Data Structures and Algorithm
DAA - Design Analysis and Algorithm

DSA and DAA are two major components of competitive coding
Major topics : link lists, crease, graph, stack, queue

Declaration of a pointer :

<data_type> * <pointer_name>;

e.g.
int *ptr; >> means ptr is a integer pointer, or pointer to an integer. this pointer can store the address of an integer

Initialisation of a pointer :

on assigning any address of a variable to a pointer variable, the pointer variable is said to be initialised
*/
#include<stdio.h>
int main()
{
int a = 10;
int *ptr = &a;// declaration and initialisation in the same line
printf("%d",*ptr); // 10
return 0;
}
/*
here *ptr is the indirection / dereferencing / value at address operation on the pointer 'ptr'. it is used for displaying/accessing value of a variable through pointer
*ptr == *&a == a (*& are anti-operators of each other)
at one time, more than one pointer can access the same memory location
*/
#include<stdio.h>
int main()
{
int a = 10;
int *ptr = &a;// declaration and initialisation in the same line
printf("%d\n",*ptr); // 10
printf("%d\n",ptr); // prints the address
printf("%d\n",&a); // prints the same address
printf("%d\n",&ptr); // prints the address of the pointer variable
int *p2;
p2 = ptr;
printf("%d\n",p2); // same as printf("%d\n",ptr);
printf("%d\n",*p2); // 10
printf("%d\n",&p2); // prints the address of p2, different from the address of ptr
return 0;
}
/*
p2 = ptr;
printf("%d\n",p2); >>> prints address of a

*p2 = *ptr;
printf("%d\n",p2); >>> prints garbage value
*/