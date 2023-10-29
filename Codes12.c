/*
            Arrays - 1D

>>> Collection of homogeneous elements in contegeous(sequential) memory locations
>>> array of integers, floats and characters
>>> for collecting data of same type, arrays are created
>>> 1D array, simple like a list
>>> 2D array, like matrix, collection of 1D arrays
>>> 3D array, collection of 2D arrays
syntax : 

<datatype> <array_name>[n];

where n is the maximum number of elements that can be stored in the array,
n is the size, and is constant
Examples :
*/
int arrayOne[100]; // max 100 items of type int can be stored in the array
/*
>> Initialisation : assigning value at the time of declaration
>> on declaration : memory is allocated but the assigned value depends on the compiler

>> old compilers =>> garbage value to all the memory locations
>> some new compilers =>> zero
>> still, the default value is always answered as garbage, when asked

Memory representation:

int a[5];

starting index = lower bound
last index = upper bound

no of elemets = ub - lb + 1

If we create an array of integers, then the first memory location is random and afterwards the next locations are the previous location + 4. This is because size of an int is 4 bits, so at the time of declaration the compiler gives each location a memory of 4 bits.
For example :
*/
#include<stdio.h>
int main()
{
int i,array[3];

for(i=0;i<3;i++)
{
printf("%d  ",&array[i]); // printing the addresses of the memory locations assigned
}
return 0;
}
/* output is : 6422288  6422292  6422296

starting address == base address == address pf the array

python - modern concept of negative indexing
c/cpp/java - no negative indexing

Linked lists : A sequence of data structures which are connected together via links. They are the most sought-after data structure used in handling dynamic data elements.
A linked list consists of a data element known as node. Each node consists of two fields : one field has data and in the second field the node has an address that keeps a reference to the next node. The are often used due to their efficient insertion and deletion.
A linked list is called a dynamic data structure because it can be used with a data collection that grows and shrinks during program execution.

Stack : A container of objects that are inserted and removed according to the last-in-first-out (LIFO) principle.

Queue : A container of objects (a linear collection) that are inserted and removed according to the first-in-first-out (FIFO) principle.

python/java : dynamic memory allocation (expandable)
c/cpp : compile time memory allocation

#define : used in giving size to an array

for arrays :

starting index == 0
last index == n-1

initialisation : assigning values to the array elements
*/
int a[3] = {1}; // on printing, the elements are 1, 0, 0 (partial initialization)
int b[3];       // on printing, the elements are garbage values
int c[3] = {};  // on printing, the elements are 0, 0, 0
/*
In partial initialization, the un-initialized values are zero. when the complete array is un-initialized then all the values are garbage.

for character arrays, the un-initialized values are null characters (nothing)
*/
char array1[5];         // garbage values along with spaces
char array2[5] = {};    // nothing (null character)
char array3[5] = {'a','b'}; // (a b ) and then nothing (null character)
/*
int array[3] = {7}; means three spaces are created and 7 is at the first place and rest two are 0, 0

# another type of initialization : size can be skipped when value is assigned at the same time
*/
int a[] = {21,324,31,1,5};  // correct
int b[] ;                   // wrong
//accessing elements after initialization : using indexing
#include<stdio.h>
int main()
{
int z[] = {1,2,3,4,5};
printf("%d\n",z[0]); // first element, i.e. 1
printf("%d\n",z);    // if we pass only name of the array then the base address (address of the array), i.e. the address of the first element is printed

// other ways to get base address

printf("%u\n",z);     // %u is used  because address cannot be negative
printf("%d\n",&z);    // same output
printf("%d\n",&z[0]); // same output
printf("%i\n",&z);    // same output
printf("%x\n",z);     // prints in hexadecimal form
printf("%x\n",&z);    // same output as of line 108
return 0;
}
/*
long, short etc are also called sub-type qualifiers

%o == octal integer
%d == signed decimal integer
%i == integer, base is automatically detected
%u == unsigned integer
%x == hexadecimal value
%p == void pointer      // to show an address which a pointer is using

%d and %i behave same with printf() but difference arises when they are used in scanf()

%d takes signed decimal integers as input. that means both negative as well as positive values can be given but that value should be decimal otherwise garbage will be printed. if input is in octal format like 012 then %d will ignore 0 and will take input as 12

%i takes integral values with octal, decimal or hexadecimal base type.

012 == 12 in decimal
012 == 10 in octal
0x12 == 18 in hexadecimal
*/
#include<stdio.h>
int main()
{
int a;
printf("Enter the value ");
scanf("%i",&a); // to provide value in octal type, value should be given by preceding '0' and to provide value in hexadecimal  type, value should be provided preceding '0x'
printf("%i",a);
return 0;
}
// %p, %x, %d etc are used to print addresses

#include<stdio.h>
int main()
{
int a = 5;
int *p = &a;
printf("%d %u %p \n",a,a,p); // 5 5 (address in hexadecimal format)
printf("%d %u %p \n",p,p,p); // address adress (address in hexadecimal format)
return 0;
}

#include<stdio.h>
int main()
{
// printing memory address
int a = 5;
printf("Memory address = %d\n",&a);
printf("Memory address = %u\n",&a);
printf("Memory address = %p\n",(void*)&a);
return 0;
}
//( &arrayName[1] = &arrayName[0] + 4 ) for any integer array 'arrayName'

/*
Other formula to calculate number of elemnts in an array ( ub - lb + 1 )

n = sizeof(array)/sizeof(array[i]), where i can be any index

this formula helps in looping as we can decide how many times to run the loop

# initialising by taking input from the user == by using scanf() in a loop

WAP to read and display all elements of a 1D array
*/
#include<stdio.h>
int main()
{
int arrayName[5],i;
printf("Enter array elements ");
for(i = 0; i < 5; i++)
{
    scanf("%d",&arrayName[i]); // either press 'enter' after entering each element or give space between two elements and press enter at once to differntiate between two elements
}
printf("The array elements are : "); // if we enter more than 5 elements, then also no error is there. but while printing, only first 5 elements are printed as per the for loop conditions
for(i=0;i<5;i++)
{
    printf("%d, ",arrayName[i]);
}
return 0;
}
// WAP to enter and display marks of 5 students. Alsso display the average marks
#include<stdio.h>
int main()
{
int marks[5],i;
float average = 0.0f;
for (i = 0; i<5;i++)
{
    scanf("%d",&marks[i]);
}
printf("The entered marks are ");
for (i=0;i<5;i++)
{
    printf("%d, ",marks[i]);
    average = average + marks[i];
}
printf("\nThe average marks is %.2f",average/5);
return 0;
}