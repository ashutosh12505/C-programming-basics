#include<stdio.h>
int main()
{
/*
Precedence and associativity of operators :

   left     Parenthesis ()
    to      Brackets  []
   right    Postfix increment/decrement ++--
          
    

            Prefix increment/decrement ++--
            Unary plus/minus + -
   right    Logical negation/bitwise compliment ! ~
    to      (type) => cast
   left     & => address of operand
            sizeof()


            * / %
            + - 
            << >> left/right shift
            < <= less than/less than or equal to
            > >= greater than/greater than or equal to
   left     == !=
    to      &   Bitwise AND
   right    ^   Bitwise XOR
            |   Bitwise OR
            &&  Logical AND
            ||  Logical OR
            ?:  Ternary conditional
Examples =>
*/
double b = 5 % 3 & 4 + 5 * 6;
printf("%lf",b); // prints 2.000000, order of operators is : %  *  +  &
//  15 & 34 means 1111 & 100010 == 000010 means 2

double a = 3 && 5 & 4 % 3 ;
printf("%lf\n",a); // 1.000000

double c = 5 & 3 && 4 || 5 | 6; // order of operators => & | && ||
printf("%lf\n",c); // 1.000000

int d = 5 + 7 * 4 - 9 * (3,2); // (,) * * + - => 5+7*4-9*2 => 5+28-18 => 5 + 10 == 15
printf("%d\n",d); // 15

int e = 4 * 6 + 3 * 4 < 3 ? 4 : 3 ; // 24 + 12 < 3 ? 4 : 3 => 36<3?4:3 => 3
printf("%d\n",e); // 3

int f = -1, g = 4, h = 1, i ;
i = ++f&&++g||++h ; // ++f == 0 hence ++g doesn't operate, 0 || ++h => 0 || 2 => non-zero => 1 = true
// f becomes 0, g remains same, i.e. 4, h becomes 2, i is 1
printf("%d %d %d %d",f,g,h,i); // 0 4 2 1
/*
>>    if-else

syntax : 
if ( condition )
{
    body of if
}
else
{
    body of else
}

# on putting ; after if, it will give compile time error
# nested if-else => one if-else inside another if-else statement
# nested if-else statements save time because when the primary condition is false then the body/instruction is not checked/calculated.
# having else in the last is not compulsory but is recommended
*/
int age;
printf("Enter the age ");
scanf("%d",&age);
if(age<0)
{
    printf("Please enter the correct value of age. Negative value of age is nt possible");
}
else if (age > 0 && age <=18)
{
    printf("Youngster\n");
}
else if(age>18 && age<=40)
{
    printf("Adult\n");
}
else if(age>40 && age<=60)
{
    printf("Middle aged\n");
}
else if(age>60)
{
    printf("Senior citizen\n");
}
// Note =>
int x;
printf("Enter the number here ");
scanf("%d",&x);
if (x<0) // if we put ; then condition is void/null --> logical error
{
printf("%d",x*x);
printf("Hello");
}
/*
Switch statements

# driven by options,options are either character or integers e.g. 1,2,3,a,b,c...

syntax : 

switch(testingVariable)
{
    case <constant1>:
        body of this case
    break;

    case <constant2>:
        body of this case
    break;
    ------------------
    ------------------
    ------------------
    default:
        body of this case
    (no need to break here as this is the last case)

}

# 'default' case can be put anywhere in the program, but it is recommended to put it in the last

# from the matching case the operation will start, and will stop when any 'break;' statement is encountered or the body of switch statement is over.

# fall through => when 'break' statement is not used then all the cases are operated.

# no two cases can be same/any case cannot be repeated
*/
// WAP to display the day name when day number is entered
int dayNumber;
printf("Enter the day number here ");
scanf("%d",&dayNumber);
switch (dayNumber)
{
case 1:
    printf("The day is Sunday\n");
    break;
case 2:
    printf("The day is Monday\n");
    break;
case 3:
    printf("The day is Tuesday\n");
    break;
case 4:
    printf("The day is Wednesday\n");
    break;
case 5:
    printf("The day is Thursday\n");
    break;
case 6:
    printf("The day is Friday\n");
    break;
case 7:
    printf("The day is Saturday\n");
    break;
default:
    printf("Please any number from 1 to 7\n");
    break;
}
// Clubbing of cases == like logical OR operator, works when any single case is true.
// WAP to check whether the entered alphabet is vowel or consonant
char inputCharacter ;
printf("Enter any alphabet ");
scanf("%c",&inputCharacter);
switch(inputCharacter)
{
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    printf("Entered character is a vowel ");
    break;
    default:
    printf("Entered character is not a vowel");
}
// WAP to calculate area of different shapes
int sideOne,sideTwo,shapeNumber,radius,heightOfCylinder;
float pi=3.14;
printf("Enter the shape of which area is to be calculated\n1 => square\n2 => rectangle\n3 => circle\n4 => cylinder\n5 => sphere\n6 => hemi-sphere\nEnter the shape number here ");
scanf("%d",&shapeNumber);
switch(shapeNumber)
{
    case 1:
    printf("Enter the length of one side of the square ");
    scanf("%d",&sideOne);
    if(sideOne>=0)
    printf("The surface area of the square is %d",sideOne*sideOne);
    else
    printf("Please enter non-negative integers only");
    break;

    case 2:
    printf("Enter the length of the rectangle ");
    scanf("%d",&sideOne);
    printf("Enter the breadth of the rectangle ");
    scanf("%d",&sideTwo);
    if(sideOne>=0 && sideTwo>=0)
    printf("The surface area of the rectangle is %d",sideOne*sideTwo);
    else
    printf("Please enter non-negative integers only");
    break;

    case 3:
    printf("Enter the radius of the circle ");
    scanf("%d",&radius);
    if(radius>=0)
    printf("The surface area of the circle is %.2f",pi*radius*radius);
    else
    printf("Please enter non-negative integers only");
    break;

    case 4:
    printf("Enter the height of the cylinder ");
    scanf("%d",&heightOfCylinder);
    printf("Enter the radius of the cylinder ");
    scanf("%d",&radius);
    if(heightOfCylinder>=0 && radius>=0)
    {printf("The curved surface area of the cylinder is %.2f\n",2*pi*radius*heightOfCylinder);
    printf("The total surface area of the cylinder is %.2f",((2*pi*radius*radius) + (2*pi*radius*radius)));}
    else
    printf("Please enter non-negative integers only");
    break;

    case 5:
    printf("Enter the radius of the sphere ");
    scanf("%d",&radius);
    if(radius>=0)
    printf("The surface area of the sphere is %.2f",4*pi*radius*radius);
    else
    printf("Please enter non-negative integers only");
    break;

    case 6:
    printf("Enter the radius of the hemi-sphere ");
    scanf("%d",&radius);
    if(radius>=0)
    {
    printf("The curved surface area of the hemi-sphere is %.2f\n",2*pi*radius*radius);
    printf("The total surface area of the hemi-sphere is %.2f",((pi*radius*radius) +( 2*pi*radius*radius)));
    }
    else
    printf("Please enter non-negative integers only");
    break;

    default:
    printf("Please enter any number from 1 to 6 only");
    break;
}
return 0;
}