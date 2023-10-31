/*
(b) insertion sort : simple sorting algorithm working similar to the sorting of playing cards in our hands. The array is virtually split into a sorted and an unsorted part. Values from the unsorted part are picked and placed at the correct position in the sorted part.

characteristics : 

>>> stable by default
>>> one of the simplest algorithm with simple implementation
>>> efficient for small data values
>>> adaptive in nature, i.e. it is appropriate for data sets which are already partially sorted.

pseudo code : 

procedure insertionSort(A: list of sortable items)
   n = length(A)
   for i = 1 to n - 1 do
       j = i
       while j > 0 and A[j-1] > A[j] do
           swap(A[j], A[j-1])
           j = j - 1
       end while
   end for
end procedure

example : array[]: {12, 11, 13, 5, 6}

pass 1 :  12	   11  	   13   	   5   	    6

pass 2 :  11   	   12  	   13   	   5   	    6

pass 3 :  11   	   12  	    5   	  13   	    6

          11   	    5  	   12         13   	    6

           5   	   11  	   12         13   	    6

pass 4 :   5   	   11  	   12   	   6   	   13
           
           5   	   11  	    6   	  12   	   13
          
           5   	    6  	   11         12   	   13

(c) selection sort : works by repeatedly selecting the smallest (or largest) element from the unsorted portion of the list and moving it to the sorted portion of the list. this algorithm is not stable by default

example: array[] = {64, 25, 12, 22, 11}

pass 1 :   11   	   25   	   12   	   22   	   64   
pass 2 :   11   	   12   	   25   	   22   	   64   
pass 3 :   11   	   12   	   22   	   25   	   64   
pass 4 :   11   	   12   	   22   	   25   	   64   
pass 5 :   11   	   12   	   22   	   25   	   64

algorithm : 
>> Initialize minimum value(min_idx) to location 0.
>> Traverse the array to find the minimum element in the array.
>> While traversing if any element smaller than min_idx is found then swap both values.
>> Then, increment min_idx to point to the next element.
>> Repeat until the array is sorted.

Coding part of bubble sorting :

nested loops -- outer loop for number of passes, inner loop for inner comparision of two elements in a pass
*/
#include<stdio.h>
int main()
{
int size,i,j,hold,array[20];
printf("Enter the size of the array ");
scanf("%d",&size);
printf("Enter the elements ");
for(i=0 ; i<size ; i++)
{
    scanf("%d",&array[i]);
}
for(i=0 ; i<size-1 ; i++)
{
    for(j=0 ; j<size-i-1 ; j++)
    {
        if (array[j] > array[j+1])
        {
            hold = array[j];
            array[j] = array[j+1];
            array[j+1] = hold;
        }
    }
}
printf("The sorted elements are : ");
for(i=0 ; i<size ; i++)
{
    printf("%d, ",array[i]);
}
return 0;
}
// descending order sorting of an array

#include<stdio.h>
int main()
{
int i,j,size,hold,array[50];
printf("Enter the size of the array ");
scanf("%d",&size);
printf("Enter the array elements : ");
for(i=0 ; i<size ; i++)
{
    scanf("%d",&array[i]);
}
printf("The sorted array is : ");
for(i=0 ; i<size-1 ; i++)
{
    for(j=0 ; j<size-i-1 ; j++)
    {
        if(array[j] < array[j+1])
        {
            hold = array[j];
            array[j] = array[j+1];
            array[j+1] = hold;
        }
    }
}
for(i=0;i<size;i++)
{
    printf("%d, ",array[i]);
}
return 0;
}
/*
Insertion : Any value is not overwritten, there is just repositioning of elements

main code :

for(c=n-1 ; c>=position-1 ; c--)
{
    array[c+1] = array[c];
}
array[position-1] = value ;

// printing

for(c=0 ; c<=n ; c++) ------ one increased iteration to accomodate the increased element
{
    printf("%d, ",array[c]);
}

// dry running with example

array[] = {1, 2, 3, 4, 5}

c = looping variable
n = 5 (number of elements)
position = 2 (value should be at 2nd position or first index)
value = 55 (to be inserted in the array)

Iteration 1 : 

c=n-1 => c=4 => c>=1 == true
array[c+1] = array[c]
array[5] = array[4]
array[] = {1, 2, 3, 4, 5, 5}

Iteration 2 :

c=4-- => c=3 => c>=1 == true
array[4] = array[3]
array[] = {1, 2, 3, 4, 4, 5}

Iteration 3 :

c=3-- => c=2 => c>=1 == true
array[3] = array[2]
array[] = {1, 2, 3, 3, 4, 5}

Iteration 4 :

c=2-- => c=1 => c>=1 == true
array[2] = array[1]
array[] = {1, 2, 2, 3, 4, 5}

Iteration 5 :

c=1-- => c=0 => c>=1 == false
loop over

array[position-1] = value => {1, 2, 2, 3, 4, 5} => {1, 55, 2, 3, 4, 5}
the final array is {1, 55, 2, 3, 4, 5}

# Note : Position variable is the exact position (index+1)

Example : */
#include<stdio.h>
int main()
{
int i,position,value,array[] = {1,4,2,78,96,35};
printf("Original array is ");
for(i=0;i<6;i++)
{
    printf("%d, ",array[i]);
}
printf("\nEnter position : ");
scanf("%d",&position);
printf("Enter value : ");
scanf("%d",&value);
for(i=5;i>=position-1;i--)
{
    array[i+1] = array[i];
}
array[position-1] = value;
printf("The final array is ");
for(i=0;i<=6;i++)
{
    printf("%d, ",array[i]);
}
printf("\n\n%d\n\n",value);

return 0;
}