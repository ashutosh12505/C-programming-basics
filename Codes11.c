/*
Field width and field precision
*/
#include<stdio.h>
int main()
{
    int x = 123, y=265;
    printf("%d\n",x);// simply prints 123, in the left side of the output screen, left justified
    printf("%15d\n",y);// total 15 blocks are created, and from the right 5 => 6 => 2 is printed, right justified
    printf("%015d\n",y); // all the empty space is replaced by zero

    return 0;
}

#include<stdio.h>
int main()
{
int x = 1, y = 12, z = 123, p = 1234, q = 12345;
printf("%4d\n",x);
printf("%4d\n",y);
printf("%4d\n",z);
printf("%4d\n",p);
// all of the above outputs are right justified
// if number of digits is more than the given field width, then the field width will be simply ignored
printf("%2d\n",q);

return 0;
}

#include<stdio.h>
int main()
{
int a = 125;
printf("\n%5d",a);  // right justified
printf("\n%-5d",a); // default appearance

printf("%05d",a); // 00125 because 5 spaces are created, value is assigned from the right, empty spaces are replaced by zero
return 0;
}
// Field width and precision for floats : rounding off also happens
#include<stdio.h>
int main()
{
float x = 12.424, y = 15.675;

printf("%7f\n",x); // 12.424000
printf("%5f\n",x); // 12.424000
printf("%3f\n",x); // 12.424000
printf("%1f\n",x); // 12.424000
printf("%7.2f\n",x); // creates 7 spaces, assigns from right from two places of decimal, prints 12.42 right aligned
printf("%07.2f\n",x); // creates 7 spaces, assigns from right from two places of decimal, prints 0012.42
printf("%03.3f\n",y); // prints 15.675
printf("%02.2f\n",y); // first rounding off, prints 15.68
printf("%02.1f\n",y); // again rounding off, prints 15.7
printf("%02.0f\n",y); // again rounding off, prints 16
printf("%01.0f\n",y); // prints 16
printf("%02f\n",y); // prints 15.675000
return 0;
}

// if field width is less than original number's width, the given width is ignored, but when the field precision is less than the original number's precision, then rounding off takes place

#include<stdio.h>
int main()
{
float x = 12.424;

printf("%-2f\n",x); // prints 12.424000
printf("%-2.2f\n",x); // prints 12.42
printf("%-02.2f\n",x); // prints 12.42
printf("%-5.2f\n",x); // prints 12.42
printf("%-012.1f\n",x); // prints 12.4

return 0;
}

// string formatting

// --> space is created for null character also, but never takes part in printf();
// --> string : array of characters ending with null character

#include<stdio.h>
int main()
{
char x[] = "Hello";
printf("%7s\n",x); // 7 spaces are created and o > l > l > e > H is printed from the right side.
printf("%6s\n",x); // one space at the left
printf("%5s\n",x); // no space at the left

printf("%5.5s\n",x); // prints Hello, no space left at the left
printf("%5.4s\n",x); // creates 5 spaces, prints 'Hell' from the right
printf("%-5.3s\n",x); // creates 5 spaces, prints 'Hel' from the left
printf("%5.2s\n",x); // creates 5 spaces, prints 'He' from the right
printf("%-5.1s",x); // creates 5 spaces, prints H on the left
printf("Hello World"); // to show the created space

char x[2] = "Hello"; // gives error ==>> warning: initializer-string for array of chars is too long
printf("%s",x);
return 0;
}
/*
scanf();

returns integer(no of inputs being taken), takes arbitrary number of arguments
int scanf("__"_,_,_) { "format_specifier",&_addresses}

example:
*/
#include<stdio.h>
int main()
{
int x, y, z, a, b, c, d;
x = printf("Enter the value ");// x == 16
y = scanf("%d %d %d %d",&a,&b,&c,&d);// y == 4 == no of inputs, spaces is not counted in this case

printf("%d\n%d\n",x,y); // prints 16 and 4 respectively
return 0;
}
/*
Unformatted functions

[1] character input/output
    (a) getchar() : stdio.h
    (b) getch()   : conio.h
    (c) getche()  : conio.h
    (d) putchar() : stdio.h
    (e) putch()   : conio.h

    # conio.h means they are non-standard functions, thats why they are not included in stdio.h
*/
#include<stdio.h>
int main()
{
char ch;
ch = getchar(); // like : scanf("%c",&ch);
putchar(ch); // on pressing enter in the terminal, same as : printf("%c",ch);

return 0;
}
// in old compilers, getch() was used to hold the output screen, now it is used to take character input
// #include<conio.h> to use getch(); otherwise ==>> warning: implicit declaration of function 'getche' [-Wimplicit-function-declaration]

#include<stdio.h>
#include<conio.h>
int main()
{
char ch, ch2, ch3 ;
ch = getch(); //no need to press enter, execution is over as soon as any value is entered

ch2=getch();
putch(ch2); // no need to press enter, as soon as any value is entered putch() displays it

ch3 = getche(); //'e' stands for 'echo', no need to press enter, the value is stored in 'ch' as well as displayed at the same time by the function getche();
putch(ch3); // as soon as any value is given, it is printed two times without pressing enter

return 0;
}
/*
[2] string input/output
    (a) gets(); -->> can take input for multiple words (unlike scanf)
    (b) puts();

type modifiers : signed, unsigned, short, long
*/

// some other examples:
#include<stdio.h>
void fun(int);
int main()
{
fun(25);
return 0;
}
void fun(int n)
{
    if(n == 0)
    return ;
    else
    printf("%d",n%2); // final answer is 10011, 25:1 <==> 12:0 <==> 6:0 <==> 3:1 <==> 1:1 <==> 0: return
    fun(n/2);
}

#include<stdio.h>
int main()
{
int i=0,j=0;
while(i<5, j<10) // due to comma operator, only j<10 is operated
{
    i++;
    j++;
}
printf("%d %d",i,j); // prints 10 10
return 0;
}

#include<stdio.h>
int main()
{
signed char chr;
chr = 128;
printf("%d",chr); // prints -128, because range of signed char is from -128 to 127. when 128 is assigned, this value overflows and -128 is printed
return 0;
}