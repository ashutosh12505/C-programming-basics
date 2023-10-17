#include<stdio.h>
int main()
{
// operators 

// unary operators --> operate on single operand

int x1 = -10,y1;
y1 = -x1; // reverses the sign and assigns the reversed value to y1
printf("%d and %d\n",x1,y1);

int x2 = 10 , y2;
y2 = -x2;
printf("%d and %d\n",x2,y2);

// increment and decrement

// ++x and x++ have same meaning if the value is not assigned, i.e. if only x is present in the equation then both x++ and ++x means x = x+1.

// x++ means print the value and then increase by 1
// ++x means increase the value and then print it
int p=15,q=15;
p++,++q; // both become 16
printf("%d %d\n",p,q);

int a = 10,b,c=20,d;
b = a++; // b = a and after that a = a+1, i.e. a=11,b=10
d = ++c; // c = c+1 and after that d = c, i.e. c=21,d=21
printf(" a is %d \n b is %d \n c is %d \n d is %d \n",a,b,c,d);

int a1=5,b1=10,c1;
++a1,b1++,c1=a1--,c1++;
printf("%d %d %d\n",a1,b1,c1); // prints 5, 11, 7

// <<-------------------------------------------------------------------->>

/*
Priority :
unary operator > binary operator
*/
int x=2,y=3,z;
z=x + y++; // x=2, then z = x + 3 (original y), then y=y+1
printf("%d %d %d\n",x,y,z); // prints 2, 4, 5

int a2=1,b2=1,c2;
c2=a2++ + b2; // c2 = b2 + 1 (original a2), then a2=a2+1, then b2=1 as original
printf("%d %d %d \n",a2,b2,c2); // prints 2, 1, 2

int a3=1, b3=2,c3;
c3 = a3++ + ++b3 ;
printf("%d %d %d\n",c3,a3,b3); // prints 4, 2, 3

/*
Arithmetic operators -> These are binary operators -> two operands required
These are : +, -, *, /, %

% is modulus --> Gives remainder.

Sign of result when % is used -->

-a % b => negative result
a % -b => positive result
-a % -b => negative result

when numerator < denominator then the result is numerator itself, i.e.

if a < b then, a % b = a
*/

int y2=2, z2=1 ;
printf("%d\n",y2%z2); // prints 0

int w = -4, v = 3;
printf("%d\n",w%v); // prints -1

int p3 = 10, q3 = -3;
printf("%d\n",p3 % q3); // prints 1

int p = -4, q = -3;
printf("%d\n",p%q); // prints -1

int s = 20, t = 25;
printf("%d\n",s%t) ; // prints 20

int g2 = -20, h2 = 25 ;
printf("%d\n",g2 % h2); // prints -20

/* 
When either numerator or denominator or both in a % operation are float then compiler gives error.

int t=5.3 % 2; --> compiler error
printf("%d",t);

"/" => division operator
result of division operator -->

int/int = int (Integral part of mathematical result)
int/float = float
float/int = float
float/float = float
*/
int a = 1, b = 2;
printf("%d\n",a / b); // prints 0 as fractional part (0.5) gets truncated by the compiler. Result of int/int can be an int only.

/*
Sign of result when divion operator is used -->

-a /  b = negative
 a / -b = negative
-a / -b = positive
*/
int p=-2, q=2, r=-1, s=1 ;

printf("%d\n",p/q); // negative
printf("%d\n",p/r); // positive
printf("%d\n",q/r); // negative
printf("%d\n",q/s); // positive

/*
When more than one operators are used in the same equation, then two rules are used to decide the order of priority.

[1] Precedence/priority

[*, /, %] --> 1st order ( higher priority)
[+, -]    --> 2nd order ( lower priority)

>> All operators of same order have same priority among themselves.

[2] Associativity

>> When two or more operators have same priority, direction (Left to Right or Right to Left) decides their use.

>> In most of the cases it is Left to Right, except few cases like assignment operators where it is Right to Left

For arithmetic operators, its Left to Right
*/
int a=10,b=6,c=1,d=4,e=5,f=25;
printf("%d\n",a%b/c*d); // 16 >> Since all of these have same priority, Left to Right will be the order of operation.
printf("%d\n",a+b-c+d); // 19 >> Since all of these have same priority, Left to Right will be the order of operation.
printf("%d\n",a/b+c-d*e%f); // -18 >> Operate all first order operatives from left to right, after that all second order operatives from left to right
// if there is any brackets are present, then use all the above rules for that part and after solving the brackets follow the same steps for the whole equation.
printf("%d\n",a/(b+c-d)*e%f); // 15
/*
Relational Operators or Comparision operators --> returns true or false

>    -->> Greater than
<    -->> Less than
>=   -->> Greater than or equals to
<=   -->> Less than or equals to
==   -->> Equality
!=   -->> Not equals to

In C language,
false -> 0
true  -> 1

3>2 true,
3>=3 true,
2<3 true,
3>=2 true,
2==2 true,
3 != 3 false,
2 != 3 true
*/

printf("%d\n",2 == 2);
printf("%d\n",2 != 2);
printf("%d\n",2 != 3);
printf("%d\n",2 >= 3);
printf("%d\n",3 >= 2);

/*
Logical Operators ->

Logical AND -->> Binary -->> &&
Logical OR  -->> Binary -->> ||
Logical NOT -->> Unary  -->> !

Short Circuit Property -> If the first operand in logical AND is false or the first operand in logical OR is true then the second operand will not be checked and the result will be false or true respectively

Negative or positive integer >>>> true
Zero >>>> false

Priority order ->

(1) arithmetic > relational > assignment
(2) arithmetic > logical AND > logical OR
(3) unary > binary
*/
int a=10,b=0,c=2,d;
d=a&&b||c-2; // c=0 then a&&b = 0 then 0 || 0 => 0
printf("%d\n",d);

int x=1,y=0,z=5;
int a1 = x&&y||z++; // z=5 and increment then x AND y = 0 then 0 or 5 >> true and then z=z+1 means z=6
printf("%d\n",z);  // z=6
printf("%d\n",a1); // 0 || 5 means true so output is 1

int a,x=1,y=0,z=5;
a = x&&y&&z++; // z=5 then x AND y which is 0 so y AND z will not be operated due to short-circuit property. So z=5.
printf("%d\n",z);
return 0;
}