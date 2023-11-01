/*
Deletion : The value to be deleted is over-written by its next value. all onwards values are over-written by their next values and the array is printed till the second last element.

main code :

for(i=position-1 ; i<size-1 ; i++)
{
    array[i] = array[i+1];
}
for(i=0 ; i<n-1 ; i++)
{
    printf("%d",array[i]);
}
Example : */
#include<stdio.h>
int main()
{
int i,array[]={1,2,3,4,5},position,size=5;
printf("The original array is ");
for(i=0 ; i<size ; i++)
{
    printf("%d, ",array[i]);
}
printf("Enter the position of the value to be deleted ");
scanf("%d",&position);
for(i=position-1 ; i<size-1 ; i++)
{
    array[i] = array[i+1];
}
for(i=0 ; i<size-1 ; i++)
{
    printf("%d, ",array[i]);
}
return 0;
}
// arrays and functions
#include<stdio.h>
void reference(int[],int);
int main()
{
int i,array[] = {1, 2, 3, 4, 5};
printf("Printing from main : ");
printf("\n");
for(i=0 ; i<5 ; i++)
{
    printf("%d, ",array[i]); // 1, 2, 3, 4, 5,
}
printf("\n\n");
printf("Elements by reference : ");
reference(array,5); // 5 is the size of array, passed for deciding number of loops
printf("\n\n");
printf("Printing from main : ");
printf("\n");
for(i=0 ; i<5 ; i++)
{
    printf("%d, ",array[i]); // 100, 100, 100, 100, 100,
}
return 0;
}
void reference(int x[],int size)
{
    int i;
    printf("\n");
    for(i=0 ; i<size ; i++)
    {
        printf("%d, ",x[i]); // 1, 2, 3, 4, 5,
        x[i] = 100; // array is passed by reference so the elements of original array are also modified
    }
    printf("\n\n");
    for(i=0 ; i<size ; i++)
    {
        printf("%d, ",x[i]); // 100, 100, 100, 100, 100,
    }
}
// WAP to print largest element of an array by passing the array to a user defined function
#include<stdio.h>
int largest(int[],int);
int main()
{
int result,size,array[] = {132,149,224,293,678,567};
// size can be determined by dividing the total size of the array by the size of any individual element
size = sizeof(array)/sizeof(array[0]);
printf("There are %d elements in the array\n",size);
result = largest(array,size);
printf("The largest element in the array is %d",result);
return 0;
}
int largest(int x[],int size)
{
    int i,maximum=x[0];
    for(i=0 ; i<size ; i++)
    {
        if(maximum<x[i])
        maximum = x[i];
    }
return maximum;
}
// WAP to print an array where a user defined function is called every time to print each value
#include<stdio.h>
void value(int);
int main()
{
int i, array[]={1, 2, 3, 4, 5};
printf("The array elements are : ");
for(i=0 ; i<5 ; i++)
{
    value(array[i]);
}
return 0;
}
void value(int x)
{
    printf("%d ",x);
}
// WAP to swap the largest and the smallest elements of an input array, where all other elements remain at their original place
#include<stdio.h>
int main()
{
int i,j,size,min,max,minLoc,maxLoc,array[100];
printf("Enter the size of the array ");
scanf("%d",&size);
printf("Enter the array elements ");
for(i=0;i<size;i++)
{
    scanf("%d",&array[i]);
}
min = array[0];
max = array[0];
for(i=0;i<size;i++)
{
    if(min < array[i])
    {
        min = array[i];
        minLoc = i;
    }
    else if(max > array[i])
    {
        max = array[i];
        maxLoc = i;
    }
}
j = array[minLoc];
array[minLoc] = array[maxLoc];
array[maxLoc] = j;
printf("The processed array is ");
for(i=0;i<size;i++)
{
    printf("%d ",array[i]);
}
return 0;
}

/*
            Arrays - 2D

>> Declaration : <data_type> <array_name> [no. of rows][no. of columns]

example : int a[2][3];
>> last element is a[1][2];
>> 2 rows and 3 columns, gives representation in the form of matrix, but the structure is linear

>> a[0][0]  a[0][1]  a[0][2]  a[1][0]  a[1][1]  a[1][2] 
>>  [   ]    [   ]    [   ]    [   ]    [   ]    [   ]
>> elements with a[0][i] are in the first row while elements with a[1][i] are in the second row

>> there are two approaches for memory representation
(1) row major, and 
(2) column major

>>  matrix  =   [X][Y][Z]
                [P][Q][R]

>> row major representation : [X][Y][Z][P][Q][R]
>> column major representation : [X][P][Y][Q][Z][R]
>> row major representation is the default approach, simple, used in most cases and is easy to understand

un-initialized elements in a partially initialized array are zero
un-initialized elements in an un-initialized array are garbage

examples :

>> a[2][3] = {{1, 2, 3},{4, 5, 6}};
all values assigned

>> a[2][3] = {1,2,3,4,5,6}
all values assigned, 1,2,3 are in the first row by default, row major approach

>> a[2][3] = {{1},{7,8,9}}
elements are : 1 0 0 7 8 9

>> array[2][3] = {1,{7,8,9}};
compiler dependent, in some compilers error (VS Code), in some 1 7 0 0 0 0 (CodeBlocks)

>> int array[2][3] = {1,2};
elements are : 1 2 0 0 0 0

when we give elements at the time of declaration, row size can be skipped
int a[][3] = {1, 2, 3, 4, 5, 6}; // here column size is 3. so automatically row is changing after 3 elements are assigned in a particular row. {1, 2, 3} are in the first row and {4, 5, 6} are in the second row by default.

>> int array[][3] = {1,2,3,4};
elements are : 1 2 3 4 0 0

row size = no of elements / column size

column size can never be skipped, because it can't be decided using row size and number of elements. fixed number of elements can't be placed in any row logically.

on skipping column size, 'incomplete type is not allowed' error is generated

we can give more number of elements than (rows * columns). There won't be any error as there is not any bound checking in C/C++

in java/python this error is called 'array index out of range'

Accessing 2D array elements
*/
#include<stdio.h>
int main()
{
int array[3][3] = {1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 };
/*
    1  2  3
    4  5  6
    7  8  9
*/
printf("%d",array[2][2]); // answer is 9
return 0;
}