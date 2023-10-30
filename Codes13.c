// WAP to count multiples of 5 in any input array
#include<stdio.h>
int main()
{
int array[50],i,count = 0,n,num;
printf("Enter the number of elements in the array ");
scanf("%d",&n);
printf("Enter array elements ");
for(i=0 ; i<n ; i++)
{
    scanf("%d",&array[i]);
}
printf("Enter the value frequency of whose multiple you want to check in the array ");
scanf("%d",&num);
for(i=0 ; i<n ; i++)
{
    if(array[i] % num == 0)
    count++ ;
}
printf("The entered elements has its multiple %d times in the array ",count);
return 0;
}
// WAP to take an array as an input and replace all multiples of 7 in it by -99 then display it.
#include<stdio.h>
int main()
{
int i,length,array[50];
printf("Enter the number of elements in the array ");
scanf("%d",&length);
printf("Enter the array elements ");
for(i=0 ; i<length ; i++)
{
    scanf("%d",&array[i]);
}
printf("The original array is: ");
for(i=0 ; i<length ; i++)
{
    printf("%d ",array[i]);
}
for(i=0 ; i<length ; i++)
{
    if(array[i] % 7 == 0)
    array[i] = -99 ;
}
printf("\nThe modified array is: ");
for(i=0 ; i<length ; i++)
{
    printf("%d ",array[i]);
}
return 0;
}
// WAP to find largest and smallest element from an array
#include<stdio.h>
int main()
{
int array[50],i,maximum,minimum,length;
printf("Enter the number of elements in the array ");
scanf("%d",&length);
printf("Enter the array elements ");
for(i=0 ; i<length ; i++ )
{
    scanf("%d",&array[i]);
}
maximum = array[0];
minimum = array[0];
for(i=0 ; i<length; i++)
{
    if(maximum < array[i])
    maximum = array[i];
    else if(minimum > array[i])
    minimum = array[i];
}
printf("The minimum and maximum entered values are %d and %d respectively",minimum,maximum);
return 0;
}
/*
Searching elements in an array :

(a) linear search : simple, takes more time, checks at every index
application : to check how many times any element is present in any array.

WAP to take input for an array, and display the frequency of any input number
*/
#include<stdio.h>
int main()
{
int i,count=0,check,length,array[50];
printf("Enter the length of the array ");
scanf("%d",&length);
printf("Enter the array elements : ");
for(i=0 ; i<length ; i++)
{
    scanf("%d",&array[i]);
}
printf("Enter the element whose frequency is to be counted : ");
scanf("%d",&check);
for(i=0 ; i<length ; i++)
{
    if (array[i] == check)
    count++ ;
}
printf("%d is %d times in the array",check,count);
return 0;
}
/*
(b) binary search : 

condition : elements should be sorted

main logic :

beginning == 0 == first index
last == last index == number of elements - 1
mid == middle index
key == the element whose position is being searched
location == the index at which key is present

while (beginning <= last)
{
    mid = (beginning + last) / 2;
    if (array[mid] == key)
    {
        location = mid; // save the location
        break ; // exit the loop
    }
    else if (array[mid] > key) // middle element is greater than the key
    {
        last = mid - 1; // if the middle element is greater than the key then we need to search in the left sub-array
    }
    else if (array[mid] < key) // middle element is less than the key
    {
        beginning = mid + 1; // if the middle element is less than the key then we need to search in the right sub-array
    }
}
Example :
*/
// WAP to find out the position of 11 in the array (using binary search) : 5 8 11 13 19 55 77 100 102
#include<stdio.h>
int main()
{
int loc = -1, mid, beg=0, last=8; // no of elements - 1 or the last index
int key = 19,array[] = {5, 8, 11, 13, 19, 55, 77, 100, 102};
while(beg <= last)
{
    mid = (beg + last) /2;
    if(array[mid]==key)
    {
        loc = mid;
        break;
    }
    else if(array[mid] < key)
    beg = mid + 1;
    else if(array[mid] > key)
    last = mid - 1;
}
if(loc != -1)
printf("Element found at position %d",loc + 1);
else
printf("Element not found");

return 0;
}
/*
sorting the array elements (integers) :

(a) bubble sort/ sinking sort : smaller/larger elements (depending on ascending or descending order of sorting) come at the top like water bubbles

=> this whole sorting is done in multiple passes, maximum number of passes == (n-1), where n is the number of elements

=> while sorting in ascending order, worst possible case can be that all elements are in descending order initially. in such a case, (n-1) passes will be used in sorting.

Example - sort in ascending order : 15, 6, 10, 2, 1, 3, 11, 9

pass 1 :

'15'    '6'    10      2      1      3      11      9
 6     '15'   '10'     2      1      3      11      9
 6      10    '15'    '2'     1      3      11      9
 6      10      2    '15'    '1'     3      11      9
 6      10      2      1    '15'    '3'     11      9
 6      10      2      1      3    '15'    '11'     9
 6      10      2      1      3     11     '15'    '9'
 6      10      2      1      3     11   ,   9     15 ==>> 15 is fixed at it's place

# number of steps decreases after each pass.
# this is comparision of adjacent elements.

pass 2 :

'6'    '10'     2      1      3      11      9      15
 6     '10'    '2'     1      3      11      9      15
 6       2    '10'    '1'     3      11      9      15
 6       2      1    '10'    '3'     11      9      15
 6       2      1      3    '10'    '11'     9      15
 6       2      1      3     10     '11'    '9'     15
 6       2      1      3     10       9     11      15 ==>> 11 and 15 fixed at their places

pass 3 :

'6'     '2'     1      3     10       9     11      15
 2      '6'    '1'     3     10       9     11      15
 2       1     '6'    '3'    10       9     11      15
 2       1      3     '6'   '10'      9     11      15
 2       1      3      6    '10'     '9'    11      15
 2       1      3      6      9      10     11      15 ==>> 10, 11 and 15 fixed at their places

pass 4 :

'2'     '1'     3      6      9      10     11      15
 1      '2'    '3'     6      9      10     11      15
 1       2     '3'    '6'     9      10     11      15
 1       2      3     '6'    '9'     10     11      15
 1       2      3      6      9      10     11      15 ==>> 9, 10, 11 and 15 fixed at their places

pass 5 :

'1'     '2'     3      6      9      10     11      15
 1      '2'    '3'     6      9      10     11      15
 1       2     '3'    '6'     9      10     11      15
 1       2      3      6      9      10     11      15 ==>> 6, 9, 10, 11 and 15 fixed at their places

pass 6 :

'1'     '2'     3      6      9      10     11      15
 1      '2'    '3'     6      9      10     11      15
 1       2      3      6      9      10     11      15 ==>> 3, 6, 9, 10, 11 and 15 fixed at their places

pass 7 :

'1'     '2'     3      6      9      10     11      15
 1       2      3      6      9      10     11      15 ==>> all the elements fixed at their places
*/