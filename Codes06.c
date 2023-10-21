#include<stdio.h>
int main()
{
// WAP to check whether any number is prime or not
int x=2,inputNumber,containerOne,halfNumber ;
printf("Enter the number ");
scanf("%d",&inputNumber);
halfNumber = inputNumber / 2;
while (x<=halfNumber)
{
    if(inputNumber % x == 0)
    {
        containerOne = 1;
        break;
    }
    else
    {
        containerOne = 2;
    }
    x = x+1;
}
if(containerOne==1)
printf("The given number %d is not prime",inputNumber);
else
printf("The given number %d is prime",inputNumber);
// WAP to print first n prime numbers, where n is an input from the user
int x,lastNumber,count=2,currentNumber,containerOne,containerTwo;
printf("Enter the number ");
scanf("%d",&lastNumber);

if(lastNumber <= 0)
printf("Please enter any positive number");

else if(lastNumber == 1)
printf("2");

else if(lastNumber == 2)
printf("2\n3");
else
{   printf("2\n3\n");
    for(currentNumber=4;count < lastNumber;currentNumber++)
    {
        for (x=2;x<=currentNumber/2;x++)
        {
            if(currentNumber%x == 0)
            {containerOne = 1;
            break;}
            else
            {containerOne = 2;}
        }
        if(containerOne == 2)
        {printf("%d\n",currentNumber);
        count += 1;}
    }
}
// WAP to display first n terms of a fibonacci series
int inputNumber,a=0,b=1,c,count;
printf("Enter the length here ");
scanf("%d",&inputNumber);
for(count=1;count<=inputNumber;count++)
{   
    c = a + b;
    a = b;
    b = c;
    printf("%d\n",c);
}
// WAP to check whether any number is Armstrong number or not
int inputNumber,x,length=0,remainder,result=0,input2,reverseRemainder;
printf("Enter the number here ");
scanf("%d",&inputNumber);
x = input2 = inputNumber;
while(inputNumber != 0)
{
    inputNumber = inputNumber/10;
    length = length + 1;
}
if (x == 0)
{
    printf("Yes, %d is an Armstrong number",x);
}
else if(length == 1)
{
    printf("Yes, %d is an Armstrong number",x);
}
else if(length == 2)
{
    while(x != 0)
    {reverseRemainder = x%10;
    result = result + reverseRemainder*reverseRemainder;
    x = x/10;}
    if (input2 == result)
    printf("Yes, %d is an Armstrong number",input2);
    else
    printf("No, %d is not an Armstrong number",input2);
}
else if(length == 3)
{
    while(x != 0)
    {reverseRemainder = x%10;
    result = result + reverseRemainder*reverseRemainder*reverseRemainder;
    x = x/10;}
    if (input2 == result)
    printf("Yes, %d is an Armstrong number",input2);
    else
    printf("No, %d is not an Armstrong number",input2);
}
else if(length == 4)
{
    while(x != 0)
    {reverseRemainder = x%10;
    result = result + reverseRemainder*reverseRemainder*reverseRemainder*reverseRemainder;
    x = x/10;}
    if (input2 == result)
    printf("Yes, %d is an Armstrong number",input2);
    else
    printf("No, %d is not an Armstrong number",input2);
}
else if(length >= 5)
{
    printf("Please enter zero or any positive integer of length less than 5 digits");
}
else
{
    printf("No, it is not an Armstrong number");
}
/*
For loop => all the three components are at the same place

Syntax :
for (<initialization>;<condition_checking>;<value_upgradation>)
{
    Body of the loop
}

Example: to print "Hello World" 10 times
*/
int i;
for (i=1;i<=10;i++)
{
    printf("Hello World\n");
}
/*
This loop is used primarily when the end is known, i.e.
for loop = definite
while loop = indefinite
Comparision:
for ( ; n!=0 ; n/10 )                while(n != 0)
{                                    {
Body                     ======       Body
                                      n = n/10;
}                                    }

Examlple:
WAP to write the multiplication table of any input number using for loop
*/
int n,inputNumber;
printf("Enter the number ");
scanf("%d",&inputNumber);
for (n=1;n<=10;n++)
{
    printf("%d\n",n*inputNumber);
}
/*
Variations of for loop

(1) Normal : for(<initialization> ; <condtion_checking> ; <variable_updation>)
             {
                Body
             }

(2) Similar to while loop : for( ; <condition> ; )
            {
                Body
                <Variable_updation>
            }

(3) Infinite loop : for( ; ; )
                    {
                        Body
                        <Variable_updation>
                    }
*/
int i;
for(i=1;i<=5;i++); // due to semi-colon, body of the loop will be skipped but the value of i will keep on modifying itself;
printf("%d",i); // prints 6, the first loop breaking condition


int i=3,sum=0;
for(;;)
{
    sum = sum + i;
    if (i==2)
    break;
    i--;
}
printf("%d\n",i); // 2
printf("%d",sum); // 5 ( 2 + 3 )

/*
do-while loop

syntax:

do
{
    Body of the loop
    <updation>
}while(<condition>)

example: print "Hello" 5 times using do-while loop
*/
int i;
do
{
    printf("Hello World\n");
    i++; // removing the updation part will make this loop an infinite loop
} while (i<=5);
// condition is at the last thats why even if the condition is false then also the loop operates for once, before condition checking
return 0;
}