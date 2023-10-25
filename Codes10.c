/*
[2] register

--> storage location : cpu register
--> default value    : garbage value
--> scope            : local to the block of definition
--> life-time        : till the control remains in that block

--> on giving the storage class as register, the compiler tries to put variable into high speed registers

declaration syntax:
                register <data-type> <variable_name> = <variable_value>

                example:
                register int x = 12;

--> registers are close to the CPU, so the computation/execution is fast. So only those values which are needed frequently are stored in registers. examples - looping variables.
--> very few number of registers are available
--> only small values can be stored in registers.

register long long int x; ---->>> not recommended

--> if register is not available then the compiler automatically shifts the storage class to auto

## NOTE : input cannot be taken for register

in scanf("_ _",&x); address of the variable x can only be RAM, not CPU

example:
        register int input;
        scanf("%d",&input); ==>> error: address of register variable 'input' requested

## NOTE : address of the register cannot be printed

example:
        register int x=100;
        printf("%d",x);   // prints 100
        printf("%d",&x);  ==>> error: address of register variable 'x' requested

--> giving address of CPU register directly is of security risk
*/
#include<stdio.h>
int main()
{
register int x=100;
printf("%d",x);   // prints 100
printf("%d",&x);  // error: address of register variable 'x' requested

return 0;
}
/*
[3] static

--> storage : RAM
--> default value : zero
--> scope : local to its definition block
--> life-time : throughout the program

--> used when tracking of the previous value is needed
--> any static variable can be initialized only once in its life-time
--> the variable will not be destroyed after its block, and will be accessible throughout the program in its block
--> only first intialization statement will be executed, after that all the statements of initialization will be ignored.

example:
*/
#include<stdio.h>
void function();
int main()
{
    function();
    function();
    function();
    return 0;
}
void function()
{
    int a = 10;
    static int b = 10;
    printf("%d %d\n",a,b);
    a++ ;
    b++ ;
/*
the output is:
                        10 10
                        10 11
                        10 12
explanation: the value of 'a' is 10 every time the function 'function' is called. but the declaration statement for static int 'b' is ignored after the intialisation. so 'b' carries its incremented value each time the function is called.
*/
}
// another example:
#include<stdio.h>

int incr(int i)
{
    static int count = 0; // for only 'int count' , the previous value gets omitted and count = 0 for each iteration. so the output in that case would be the last value of for loop, i.e. 3
    count = count + i;
    return count;
}
int main()
{
    int i,j;
    for(i=0;i<=3;i++)
    {
        j = incr(i);
    }
    printf("%d\n",j); // 6 because 'count' carries its previous value in each iteration, its declaration(count = 0) being skipped
    return 0;
}
// another example:
#include<stdio.h>
void update();
int main()
{
    update();// 2, 2
    update();// 2, 3 static int b skips its declaration in the second call and carries its previous value i.e. 2

    return 0;
}
void update()
{
    auto int a = 1;
    static int b = 1;
    a++ ;
    b++ ;
    printf("%d, %d\n",a,b);
}
/*
[4] extern

--> storage : RAM
--> default value : zero
--> scope : global
--> life-time : throughout the program

--> global variable which may be defined in the same or any other file
--> on giving any local variable this class : error ==>>  'an initializer is not allowed on a local declaration of an extern variable'

--> we can use the variable before assigning any value

--> extern int x; === similar to telling the compiler that "search for x"
--> extern int x; === not creation of any variable, only reference statement
--> extern int x; === variable is defined once, but used multiple times

--> storage class is used with datatypes mostly
--> extern int x = 15; === error

// Mathematical functions

#include<math.h>
--> ceil funtion : integral part + 1
--> take parameter as double (lf) and return value as double
--> floor function : integral part
--> default input for angles is in redians
--> fmod(2.0, 1.5) == 0.5 [remainder]
*/
#include<stdio.h>
int functionNew(int, int);
int main()
{
printf("%d",functionNew(4,3));
return 0;
}
int functionNew(int x, int y)
{
    if(x == 0)
    return y;
    return functionNew(x-1,x+y); // (3, 7) is passed again => (2, 10) is passed again => (1, 12) is passed again => (0, 13) is passed => x == 0 so y (13) is returned
}
/*
Formatted and unformatted functions


formatted : printf(); and scanf();

printf() => int printf(char*str,_,_,_,_) => returns integer, takes arbitrary(variable) number of arguments
*/
#include<stdio.h>
int main()
{
int x;
x = printf("Hello"); // prints 'Hello'
printf("%d",x); // prints 5, number of characters in the string

return 0;
}

#include<stdio.h>
int main()
{
int x;
x = printf("Hello\n"); // prints 'Hello'
printf("%d",x); // prints 6, number of characters in the string, \n is a single character
return 0;
}

#include<stdio.h>
int main()
{
int x;
x = printf(" He llo "); // prints 'He llo'
printf("%d",x); // prints 8, number of characters in the string, each spaces is also counted
return 0;
}

// printf(); can be used to return any value also
#include<stdio.h>
int main()
{
int x=4, y=6, z;
z = printf("%d %d",x,y); // prints '4 6'
printf("%d",z); // prints 3, %d is a single character and space is also present
return 0;
}

#include<stdio.h>
int main()
{
printf("%d",printf("Hello"));  // Hello5 is printed, the inner printf() returns 5, the outer printf() displays it
return 0;
}