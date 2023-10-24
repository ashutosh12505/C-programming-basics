// Type [2], function returning a value but not taking any parameter
/*
input          => user-defined function
implementation => user-defined function
output         => main
calling        => main

When the user defined function returns the value, there are two ways to catch it.

(1) by directly printing the output -->>

# the output cannot be reused by this method
*/
#include<stdio.h>
int addition1();
int main()
{
    printf("The sum is %d",addition1());
    return 0;
}
int addition1()
{
    int a,b,sum ;
    printf("Enter the two numbers ");
    scanf("%d %d",&a,&b);
    sum = a + b;
    return sum ;
}
/*
(2) by storing the returned value {so that the output can be re-used} -->>
*/
#include<stdio.h>
int addition2();
int main()
{
    int result;
    result = addition2();
    printf("The sum is %d",result);
    return 0;
}
int addition2()
{
    int a,b,sum ;
    printf("Enter the two numbers ");
    scanf("%d %d",&a,&b);
    sum = a + b;
    return sum ;
}
// ---------------------------------------------------------------------------- //

// Type [3], function not returning any value but taking arguments/parameters

/*
input          =>> main
calling        =>> main
implementation =>> user-defined function
output         =>> user-defined function

header contains => datatype of the variables needed
Example:
*/
#include<stdio.h>
void addition_void(int,int);
int main()
{
    int a,b;
    printf("Enter the numbers ");
    scanf("%d %d",&a,&b);
    addition_void(a,b); // actual arguments (or formal arguments)
    
    return 0;
}
void addition_void(int x,int y) // x and y are the duplicate values
{
    int z;
    z = x + y;
    printf("The sum is %d",z);
}
/*
Note: a,b are visible only inside the main function.

This process of transferring argument from the main function to the user-defined function is called Parameter Passing Mechanism.
*/
// ---------------------------------------------------------------------------- //

// Type [4], function taking parameters/arguments as well as returning value
/*
user-defined function contains logic, almost all other work is done by main

input          =>
output         => main
calling        =>

implementation => user-defined function
Example:
*/
#include<stdio.h>
int additionLast(int,int);
int main()
{
    int a,b,result;
    printf("Enter the values ");
    scanf("%d %d",&a,&b);
    result = additionLast(a,b);
    printf("The sum is %d",result);

    return 0;
}
int additionLast(int x,int y)
{
    int z;
    z = x + y ;
    return z;
}
#include<stdio.h>
int main()
{
/*
Pointer => Variable which stores the address of another variable

# value of original variable can be chanaged also using pointer
Example:
*/
int a=10;
printf("%d\n",a); // prints 10

int *anyName = &a;
*anyName = 20;
printf("%d\n",a); // prints 20


return 0;
}
/*
Parameter passing mechanisms in C

(1) call-by-value [default] -->> takes more memory and time because duplicate copies are created

Example: WAP for swapping of two numbers
*/
#include<stdio.h>
void swap(int, int);
int main()
{
    int a=1,b=2;
    printf("%d %d is the original number\n",a,b); // original value
    swap(a,b);

    return 0 ;
}
void swap(int x, int y)
{
    int container;
    container = x;
    x = y;
    y = container;
    printf("%d %d is the swapped number\n",x,y); // swapped value
}
/*
(2) call-by-reference/pointer/address -->> fast, less memory consumption

# limitation: it can only accept address, and is not secure
Example: WAP for swapping of two numbers
*/
#include<stdio.h>
void swapTwo(int*,int*);
int main()
{
    int a=1,b=2;
    printf("%d %d is the original number\n",a,b);
    swapTwo(&a,&b);

    return 0;
}
void swapTwo(int *anyName1, int *anyName2)
{
    int container;
    container = *anyName1;
    *anyName1 = *anyName2;
    *anyName2 = container;
    printf("%d %d is the swapped number",*anyName1,*anyName2);
}
// call-by-value and call-by-reference, both can be used in the same program also
// example:
#include<stdio.h>
void example(int,int*);
int main()
{
int x=10,y=20;
printf("%d %d",x,y);

example(x,&y); // address of the second argument is passed in accordance with the definition of the function
printf("%d %d",x,y);

return 0;
}
void example(int a,int *b)
{
    a = a + 10;  // x = 10 <<<===>>> The value of x remains unchanged since x is passed to 'example' by value, meaning that any changes made to a inside the 'example' function do not affect x in the main function.
    *b = *b + 5; // y = y+5 => y == 25
}