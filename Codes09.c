/*
 Recursion => A function calls itself again and again upto the base case.

 ->> an alternative of iteration,
 ->> takes more time, space and is more complex than normal iteration
 ->> less codes than iteration
 ->> data-type is stack
 ->> based on the principle of LIFO == Last In First Out

Base case: Stopping point of the recursion
Recursive Case: Case which keeps on repeating till the base case is reached

Example: WAP to display factorial of any input number
*/
#include<stdio.h>
long long int factorial(int); // return type and function name
int main()
{
    int inputNumber;
    printf("Enter the number here ");
    scanf("%d",&inputNumber);
    printf("Factorial is %d",factorial(inputNumber));

    return 0;
}
long long int factorial(int x)
{
    if(x == 0 || x == 1) // base case
    return 1;
    else
    return x*factorial(x-1);
}
// WAP to display sum of first n natural numbers using recursion
#include<stdio.h>
int sum(int);
int main()
{
int inputNumber;
printf("Enter the number ");
scanf("%d",&inputNumber);
printf("The sum is %d",sum(inputNumber));

return 0;
}
int sum(int x)
{
    if(x==0)
    return x; // base case
    else
    return x + sum(x-1);
}
// WAP to display n terms of fibonacci series using recursion
#include<stdio.h>
int fibonacciSeries(int);
int main()
{
int i,n;
printf("Enter the number ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
    printf("%d\n",fibonacciSeries(i));
}

return 0;
}
int fibonacciSeries(int a)
{// there are two base cases in this program

    if(a==0) // base case
    return 0;

    else if(a==1) // another base case
    return 1;

    else
    return fibonacciSeries(a-1) + fibonacciSeries(a-2);

}
// Memoisation : Storing computed results to use again when needed
/*

{} is called block in C programming

<<---------------------------------------------------------------------------------->>

Scope rules

[1] Local variables => variables created inside any block

accessibility : inside the block in which they are created
default value : garbage value
scope         : block of their creation
lifetime      : till the execution of the block

once the block is over, they are destroyed
they are unseen out of their block

example:
#include<stdio.h>
int main()
{
    int x = 12,y = 10;

return 0;
}
int main2()
{
    printf("%d %d",x,y); ---->>>>>> gives error that x and y are undefined
    
    return 0;
}


[2] Global variables => variables created out of blocks

accessibility : in all functions available in the entire program
default value : zero
scope         : throughout the program
lifetime      : till the execution of the program

once updated, they are updated for rest of the program
they always take the most recently updated value

if variable name is same, it is overwritten
example:
*/
#include<stdio.h>
int main()
{
    int p = 20;
    printf("%d\n",p); // prints 10

    p = 30;
    printf("%d\n",p); // prints 30

    /*
    # Note: variable should not be declared again in its scope, it will give error
    example:
    */
    int p =50;   // error: redefinition of 'p'
    printf("%d",p);
}
/*
priority:
        local > global
*/
#include<stdio.h>
int x = 25;
int main()
{
    int x=10;
    printf("%d",x); // prints 10

    return 0;
}

// but assignment to any global operator can be done in any block also.
#include<stdio.h>

int x=20;
void secondmain(int);
int main()
{
x = 25;
secondmain(x); // prints 25

return 0;
}
void secondmain(int x)
{
    printf("%d",x);
}

//If any local variable with same name is defined then that local variable is assigned, otherwise the global variable gets a new value assigned
int x=10;
int main()
{
    x = 2;
    return 0;
}
// printf("%d",x); ----->>>> prints 2 because assignment operator is working in the block of main function

// <<----------------------------------------------------------------------------------------------------->> //

/*
RAM is also called the main memory

Storage Class => Tells four things about any variable

                            -->> default value
                            -->> storage location
                            -->> scope/accessibility
                            -->> life-time

There are four storage classes: 
                               {1} auto
                               {2} register
                               {3} static
                               {4} extern

[1] auto:

--> default storage class of any local variable
--> default value : garbage value
--> scope         : local to the block of definition
--> life-time     : till the control remains in that block

Example:
*/
#include<stdio.h>
int main()
{
    auto int x = 10; // same as 'int x = 10;'
    printf("%d\n",x);     // gives 10

    {
        int y = 15;
        printf("%d\n",y); // gives 15
    }
//  printf("%d",y);     >>>> gives error
}