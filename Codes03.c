#include<stdio.h>
int main()
{
/*
Logical NOT

Reverses Value

true -> false, and vice-versa

a!=b is same as !(a==b)

!(a==b) is a negative condition

program to check if b>a,

printf("%d",!(a>b));
*/
printf("Enter the number here ");
int a;
scanf("%d",&a);
printf("%d",!(a==5)); // returns true(1) when a is not 5
// program to check whether q>=p,

// printf("%d",!(q>p));

/*
Ternary operators (or conditional operators) -> denoted with "?:"

--> Alternative of if-else
--> Three operands
--> OP1 ? OP2 : OP3  => OP1 is condition. If OP1 is true then OP2 is operated otherwise OP3 is operated.

Write a program to check whether a given number is even or odd using ternary operator (?:).
*/
int num;
printf("Enter the number ");
scanf("%d",&num);
num%2==0 /*Condition*/ ? printf("Is even") /* If condition is true then */ : printf("Is odd") /*If condition is false then*/;
// Program to check the greater of two numbers
int a,b,x;
printf("\nEnter the numbers ");
scanf("%d %d",&a,&b);
x = a>b ? a : b ;
printf("%d",x);
// voting system eligibility
int age;
printf("Enter the age ");
scanf("%d",&age);
age>18?printf("Is eligible"):printf("Is not eligible");
// greatest of three numbers
int a, b, c, g, x;
printf("Enter the three numbers ");
scanf("%d %d %d",&a,&b,&c);
g=a>b?a:b ;
x=g>c?g:c ;
printf("The greatest integer is %d",x);
//  using nested condition
a>b ? (a>c?printf("%d is greatest\n",a):printf("%d is greatest\n",c)) : (b>c?printf("b is greatest\n"):printf("c is greatest\n"));
/*
Bitwise operators =>

&   -  Bitwise 'and'
|   -  Bitwise Inclusive OR (OR)
^   -  Bitwise Exclusive OR (XOR)
~   -  Bitwise one's compliment operator
>>  -  Right shift
<<  -  Left shift

Uses -
[1] In competitive coding to reduce complexity
[2] In cryptographic security (encryption/decryption)
[3] In compressors also

Examples -

[1] Bitwise 'and' ( & )

    A   B   A & B
    0   0     0
    0   1     0
    1   0     0
    1   1     1

[2] Bitwise 'or' ( | )

    A   B   A | B
    0   0     0
    0   1     1
    1   0     1
    1   1     1

[3] Bitwise 'XOR' ( ^ )

    A   B   A ^ B
    0   0     0
    0   1     1
    1   0     1
    1   1     0

[4] Bitwise one's compliment ( ~ ) #formula =>  -(n+1), e.g. for 5, one's compliment = -(5+1) = -6, output is decimal.

    A   ~A
    0    1
    1    0

[5] Right shift ( >> )

    Division
    # formula : number >> no_of_bits  => number/2^no_of_bits
    # example : 8>>2 = 8/2^2 = 8/4 = 2.
    # logic :
            for 8>>2,
            8 = 00001000 (binary notation)
            right shift 2 means remove the right-most 2 digits(0 or 1, whatever is present) and place 2 zeros at the left-most part, so that the number of bits remains the same.

    # few more examples :
        36 >> 4 => 100100 right shift 4 => 000010 = 2
                by formula, 36>>4 = 36/2^4 = 36/16 = 2 complete bits.

        23 >> 3 => 10111  right shift 3 => 00010  = 2 
                by formula, 23>>3 = 23/2^3 = 23/8  = 2 complete bits.

[6] Left shift ( << )

    Multiplication
    # formula : number << no_of_bits => number*2^no_of_bits
    # example : 4<<2 = 4*2^2 = 4*4 = 16.
    # logic :
            for 4<<2,
            4 = 00000100 (binary notation)
            left shift 2 means remove the left-most 2 digits(0 or 1, whatever is present) and place 2 zeros at the right most part, so that the number of bits remains the same.

    # few more examples :
        9 << 3 => 00001001 left shift 3 => 01001000 = 72
               by formula, 9<<3 = 9*2^3 = 9*8 = 72
*/
int a = 10, b = 5;
printf("%d\n",a & b); // 0 because 5 = 0101 and 10 = 1010, so 1010 AND 0101 = 0000 = 0
printf("%d\n",a | b); // 0101 OR 1010 = 1111 = 15
printf("%d\n",a ^ b); // 0101 XOR 1010 = 1111 = 15
printf("%d\n",~a); // -(10+1) = -11
printf("%d\n",~b); // -(5+1) = -6

int a =12, b = -20, c=0;
printf("%d\n",~a);
printf("%d\n",~b);
printf("%d\n",~c);

/*
Priority :

assignement operator > comma operator
compact/shorthand notation => x+=1

Special Operators :

[1] typecast operator.
    example => float x = 12.5f;
               int a;
               a = (int)x;
    */
float float1 = 12.5f;
int integer1;
integer1 = (int)float1 ;
printf("%d\n",integer1); // prints 12
/*
[2] sizeof() => output is always int
[3] comma (,) operator => used when declaring related/same type of variables

*/
int a=2,b=3,c;
c = a,b ; // then c = a = 2 because comma operator is not being operated and assignment operator is working
c = (a,b); // then c = b = 3 because comma operator is working (assigning right-most value to c) due to the presence of bracket operator
printf("%d",c);
//    <<-------------------------------------------------------------------->>
int a=4,b=2,c;
c = (a++,a+=b);
printf("%d",c); // prints 7 because a++ is operated,a = a+1 => a = 5, then a=a+b is also operated due to brackets being present.
int x=1, y=2, z=3, output ;
output = x,y,z ;    // then output = x = 1
output = (x,y,z) ;  // then output = z = 3
/*Type conversion

Two types -> Implicit and Explicit conversion

[1] Implicit Conversion
>> Done by compiler, always automatic
>> May include promotion or demotion
   # Promotion : Conversion from lower type to higher type. No loss of data
   # Demotion  : Conversion from higher type to lower type. Data may be lost

[2] Explicit Conversion
>> Forceful conversion, done by operator using cast operator
>> syntax : (type)

Example :
*/
int a = 2, result1;
float b = 3.4f, result2 ;
result1 = a + (int)b ;
result2 = a + b ;
printf("%d\n",result1); // prints 5
printf("%f\n",result1); // prints -1.#QNAN0
printf("%.2f\n",result2); // prints 5.40
/*
Internally,
result1 (int) = int + float,
3.4 (float) => 3 (int)  (loss of data)
result1 = 3 + 2 = 5

all the typecasting changes are temporarily in this method, for example :
*/
printf("%d\n",a);
printf("%d\n",b); // gives random garbage value as b is not an integer and the format specifier %d is for integers
printf("%.1f\n",b); // gives original b, 3.40
return 0;
}