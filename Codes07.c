#include<stdio.h>
int mainOne()
{
/*
Jump statements =>
                    [1] break
                    [2] continue
                    [3] goto
                    [4] return

[1] break => used to terminate the loop in loops and to come out of the case in the switch case statements
Example :
*/
int i;
for(i=1;i<=10;i++)
{
    if(i==5)
    break;
    printf("Hello\n"); // prints 'Hello' four times
}
printf("%d\n",i); // 5 is printed,before breaking i++ is implemented
// value which causes the loop to break is the last value
for(i=1;i<=10;i++)
{
    printf("Hello World\n"); // 'Hello' once
    break;
}
printf("%d\n",i); // 1 because the break statement operates before increment

int i=1,count=10;
while(i)
{
    if(i%3 ==0)
    break;
    count-- ;
    i = i+1;
}
printf("%d",count); // two times the loop works, count-2 == 8 is printed

int i=1;
do
{
    printf("Hello\n");
    if(i==3)
    break;
    else
    i++ ;
} while (i<=10); // prints 'Hello' 3 times, i==3 will break the loop but this is checked after the execution of the code in the body
/*
[2] continue statement => doesn't terminate, rather skips.

#Note : in while loop, avoid putting increment/decrement/any_other_update after continue statement

Example-
*/
int i;
for(i=1;i<=10;i++)
{
    if(i==5)
    continue;
    else
    printf("%d",i); // prints 1234678910
}

int i;
for(i=1;i<=10;i++)
{
    if(i%2 == 0 || i%3 == 0)
    continue;
    printf("%d\n",i); // prints 1, 5, 7
}
printf("%d\n",i); // prints 11, as the loop is terminated when i is incremented to 11

int i;
for(i=1;i<=10;i++)
{
    continue;
    printf("%d",i); // does nothing as after continue statement the code is skipped every time
}
printf("%d",i); // prints 11 as the loop terminates at i == 11

/*
[3] goto statements => unconditional jump, to move to any section of the code/program, jump can be forward or backward

break : loops and switch
continue : loops only
syntax :
goto <label_name>

# to name label, rules of naming identifiers (like variables) will be followed.
# we cannot have duplicate label names
# to define labels, syntax:

label:
<label_name>

Example:
*/
int x;
label1:
printf("Enter any positive number ");
scanf("%d",&x);

if(x<0)
goto label1; // again the same message is displayed
else
goto label2;
label2:
printf("The value is fine"); // when the entered number is actually greater than 0

/*
[4] return statement => convention => zero == successful execution
                                  non-zero == unsuccessful execution

# used to return any value from the funtion
# statements written after the return statement in a function will never be executed, as the function terminates after returning the value
# syntax:
return <constant/variable/expression> ;
    or
return (<constant/variable/expression>) ;

# usually the last statement of the function body
# can return one value at a time
# process: any program in execution
Example:
*/
return (0);
printf("Hello World\n"); // nothing is printed, process returns 0

int a=2,b=3;
return a+b; // process returns 5
// depending on the conditions only one return statement can work at a time

/*
Nested loops =>

# for one iteration of outer loop, inner loop runs for all of its iterations
# loop runs till the outer loop is not terminated
Example:
*/
int i,j;
for(i=1;i<=3;i++)
{
    for(j=1;j<=5;j++)
    {
        printf("Hello %d\n",j); // prints hello 15 times
    }
    printf("Next outer loop\n"); // printed after each inner loop is completed
}

/*
for inside for : somewhat easy
for inside while : somewhat tricky
while inside for : somewhat tricky
while inside while : somewhat tricky
*/

// Pattern printing
int i,j;
for(i=1;i<=5;i++)// forward direction
{
    for(j=1;j<=i;j++)
    {
        printf("%d",j);
    }
}

int i,j;
for(i=5;i>=1;i--)// backward direction
{
    for(j=1;j<=i;j++)
    {
        printf("*");
    }
    printf("\n");
}

return 0;
}
/*
Functions => Set of instructions bundled together to use again when required.

Calling functions : which calls any other function, example : main(),any other is also possible during nesting
Called functions  : which gets called.

Types of functions => Pre-defined and User-defined.

Pre-defined functions are contained in header files.

Any user-defined function has 3 main components.
                                => Function declaration/prototype/signature
                                => Function calling
                                => Function definition

User-defined functions have four types
                                => [1] Function not returning any value and not taking any arguments/parameters
                                => [2] Function returning value but not taking any argument/parameter
                                => [3] Function not returning any value but taking arguments/parameters
                                => [4] Function returning value as well as taking arguments/parameters
*/
//---------------------------------------------------------------------------------------------//
/* Type [1], function not taking any argument and not returning any value

input          }
implementation } ==>>> in the user-defined function
output         }

calling        } ==>>> in main

{1} function declaration
Syntax:
        <return_type> <function_name>();
Example: void example();

declaration can be ignored if the definition of the function of the function is known in the beginning.

{2} function calling => can be done anywhere
Syntax:
        <function_name>();
Example: example();

{3} function definition => function header + function body
Syntax:
        <return_type> <function_name>()
        {
            // body of the function
        }

header part should match with the prototype part

no ';' is used after declaring the header part
*/
// Example: addtion of two numbers using functions taking no parameters and returning nothing

#include<stdio.h> // including the header file
void addition(); // or void addition(void); >>> declaration
int main()
{
addition(); // calling
return 0;
}
void addition()// definition
{
    int a,b,sum ;
    printf("Enter the two numbers ");
    scanf("%d %d",&a,&b);
    sum = a + b;
    printf("The sum is %d",sum);
}
// After calling the user-defined function in main, the control is transferred to the user-defined function from main
// After the execution, the control goes back to main.