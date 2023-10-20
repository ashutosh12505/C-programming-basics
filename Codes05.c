#include<stdio.h>
int main()
{// WAP to calculate the perimeter of different shapes
int sideOne,sideTwo,shapeNumber,radius;
float pi=3.14;
printf("Enter the shape of which perimeter is to be calculated\n1 => square\n2 => rectangle\n3 => circle\nEnter the shape number here ");
scanf("%d",&shapeNumber);
switch(shapeNumber)
{
    case 1:
    printf("Enter the length of one side of the square ");
    scanf("%d",&sideOne);
    if(sideOne>=0)
    printf("The surface area of the square is %d",4*sideOne);
    else
    printf("Please enter non-negative integers only");
    break;

    case 2:
    printf("Enter the length of the rectangle ");
    scanf("%d",&sideOne);
    printf("Enter the breadth of the rectangle ");
    scanf("%d",&sideTwo);
    if(sideOne>=0 && sideTwo>=0)
    printf("The perimeter of the rectangle is %d",((2*sideOne)+(2*sideTwo)));
    else
    printf("Please enter non-negative integers only");
    break;

    case 3:
    printf("Enter the radius of the circle ");
    scanf("%d",&radius);
    if(radius>=0)
    printf("The perimeter/circumference of the circle is %.2f",2*pi*radius);
    else
    printf("Please enter non-negative integers only");
    break;

    default:
    printf("Please enter any number from 1 to 3 only");
    break;
}
/*
Rules for switch

# case test label :
            must be unique
            end with colon (:)
            not floating point
            can be x
            can be 1
            can be 1+1
            cannot be 1+x

# default can be placed anywhere in the switch

# multiple cases cannot use same expression

# nesting is allowed -- switch inside switch

# variables are not allowed in switch case label
                    example >> int x = 4;
                            case x : (error)
                            case x + 1: (error)

# case 3>2 : ==> means case 1: because 3>2 returns true which means 1 in C language

# if default is not present and no case matches then there is blank output
*/ 
int x = 97;
switch(x)
{
    case 'a':
    printf("Hello\n"); // "Hello" is printed because ASCII value of 'a' is 97
    break;
    case 'b':
    printf("World\n");
    break;
    default:
    printf("Hello World\n");
}

/*
#   Loops
Iterative statements/repetitive statements/looping statements
                                   
Three types -> while loop, for loop, do while loop

'while' and 'for while' loops are entry controlled loops, or pre-test loops where the condition is checked before operating the body
'do while' is a exit controlled loop, or post test loop where the loops operates for the first time, then the condition is checked and if found true, then loop operates till it is true

# if the condition is true then all these loops show the same behaviour

# three components of a looping statement ->    [1] looping variable initialization - before the loop starts
                                                [2] condition checking - after each iteration
                                                [3] looping variable updation

WAP to write 'Hello World' 5 times
*/
// forward loop
int x = 1;
while(x<=5)
{
    printf("Hello Wolrd\n");
    x = x + 1;
}
// reverse loop
int y=5;
while(y>=1)
{
    printf("Hello World\n");
    y = y - 1;
}
// WAP to display first n natural numbers, where n is an input from the user
int inputNumber,x=1;
printf("Enter the number ");
scanf("%d",&inputNumber);
while (x<=inputNumber)
{
    printf("%d\n",x);
    x = x + 1;

}
// WAP to display the sum of first n natural numbers, where n is the input from the user
int x = 0,inputNumber,sum = 0;
printf("Enter the number ");
scanf("%d",&inputNumber);
while(x<=inputNumber)
{
    sum = sum + x;
    x = x + 1;
}
printf("The sum is %d",sum);
// WAP to display factorial of a number
long long int factorial=1;
int i = 1,inputNumber;
printf("Enter the number ");
scanf("%d",&inputNumber);
if(inputNumber<0)
{
    printf("Factorial is not possible");
}
else if(inputNumber==0)
{
    printf("Factorial is 1");
}
else
{
    while (i<=inputNumber)
    {
    factorial = i*factorial;
    i = i+1;
    }
    printf("%lld",factorial);
}
// WAP to count the length of a number
long long int number;
int length=0,container;
printf("Enter the number ");
scanf("%lld",&number);
while (number != 0)
{
number = number / 10;
length++;
}
printf("The length is %d",length);
// WAP to display the sum of digits of a number
long long int inputNumber ;
int i,sum=0,rem ;
printf("Enter the number ");
scanf("%lld",&inputNumber);
while(inputNumber != 0)
{
    rem = inputNumber % 10 ;
    sum = sum + rem ;
    inputNumber = inputNumber / 10 ;
}
printf("The sum is %d",sum);
// WAP to display the reverse of a number
long long int container=0,x;
printf("Enter the number ");
scanf("%lld",&x);
while (x!=0)
{
    container = container*10 + x % 10;
    x = x/10;
}
printf("The reverse is %lld",container);
// WAP to check whether a number is pallindrome or not
int containerOne,containerTwo,inputNumber,reverseNumber = 0;
printf("Enter the number ");
scanf("%d",&inputNumber);
containerTwo = inputNumber;
while(inputNumber != 0)
{
    containerOne = inputNumber % 10 ;
    reverseNumber = reverseNumber*10 + containerOne;
    inputNumber = inputNumber / 10;
}
if(reverseNumber == containerTwo)
{
    printf("Yes the number %d is palindrome",containerTwo);
}
else
{
    printf("No, the given number is not palindrome");
}
return 0;
}