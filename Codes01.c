#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main() {

printf("Hello World\n");
printf("Name: Ashutosh Kumar Singh\nNew line\n");

int a=10,b=20,c=5,d;
d=a*b*c;
printf("Product  of %d and %d and %d is %d",a,b,c,d);

//area of circle
float r=2.34f,a=0.0f;
a=3.14*r*r ;
printf("\nArea of the circle is :%f and the provided radius is %f\n",a,r);
// printf("\nArea of the circle is :%.2f",a);    will print till 2 digits after the decimal

// calculate final amount and simple interest 
float principalAmount=2500.65f,rate=8.5f,time=5.12f,simpleInterest=0.0f,finalAmount=0.0f;
simpleInterest=(principalAmount * rate * time)/100.0;
finalAmount = principalAmount + simpleInterest;
printf("Simple interest is %.3f and the amount is %.3f",simpleInterest,finalAmount);

//swap value of two variables with the help of third variable
int a=10,b=20,c;
printf("Initial values of a and b are %d and %d respectively\n",a,b);
c=b;
b=a;
a=c;
printf("Final values of a and b are %d and %d respectively\n",a,b);

//swap value of two variables without the help of third variable
int p=5,q=10;
p=p+q;
q=p-q;
p=p-q;
printf("The values of p and q are %d and %d respectively\n",p,q);

//using division and multiplication
int x=4,y=5;
x=x*y;
y=x/y;
x=x/y;
printf("The values of x and y are %d and %d respectively",x,y);

// take two numbers as input and print their sum
int a,b,c;
printf("Enter value of a and b :");
scanf("%d%d",&a,&b);
c=a+b;
printf("\nSum is %d",c);

// take input price and quantity of three products and calculate their actual and 10% discounted price

float op1 = 0.0f,op2 = 0.0f,op3 = 0.0f,q1 = 0.0f,q2 = 0.0f,q3 = 0.0f,amount1=0.0f,amount2=0.0f;
printf("\nFirst product :");
scanf("%f %f",op1,q1);
printf("\nSecond product :");
scanf("%f %f",op2,q2);
printf("\nThird product :");
scanf("%f %f",op3,q3);
amount1=(op1*q1)+(op2*q2)+(op3*q3);
amount2=amount1*9/10;
printf("\nOriginal cost is %.3f\n",amount1);
printf("\nDiscounted cost is %.3f\n",amount2);

// sizeof() function
int a=12;
float b=3.45f;
double c = 36732.263223;
char ch='d';
long double e;
short int f;
long int g;
printf("%d %f %lf %c\n",a,b,c,ch);
printf("%d %d %d %d %d %d %d ",sizeof(a),sizeof(b),sizeof(c),sizeof(ch),sizeof(e),sizeof(f),sizeof(g));

// ASCII Code
char ch;
printf("Enter the character whose ASCII code is to be determined ");
scanf("%c",&ch);
printf("%c\n",ch); // prints the same character
printf("The ASCII code is %d\n",ch); // prints ASCII code of the character given (A)

int a;
printf("Enter the ASCII code of the character ");
scanf("%d",&a);
printf("The character is %c",a); // prints the character whose ASCII code is given in the input

char n[]="Hello"; // [] is for creating array
printf("%s\n",n);
printf("%c\n",n[4]); // indexing
printf("%d\n",sizeof(n)); // returns 6 despite the presence of only 5 digits due to presence of null character. It takes one memory cell for null character (one byte)

// distance converter

// km to metres
float kM1=0.0f,mtr1=0.0f;
printf("Enter the distance magnitude in KM ");
scanf("%f",&kM1);
mtr1 = kM1 * 1000;
printf("The distance is equals to %f metres\n",mtr1);

// metres to km
float mtr2=0.0f,kM2=0.0f;
printf("Enter the value in metres ");
scanf("%f",&mtr2);
kM2 = mtr2/1000;
printf("The distance is equals to %f kms\n",kM2);

// temperature converter

// from celcius
float c1=0.0f,f1=0.0f,k1=0.0f;
printf("Enter the temperature value in degree celcius ");
scanf("%f",&c1);
k1 = c1 + 273.15;
f1 = (9*c1)/5 + 32;
printf("This temperature is equals to %.2f fahrenhite and %.2f kelvin\n",f1,k1);

// from fahrenhite
float c2=0.0f,f2=0.0f,k2=0.0f;
printf("Enter the temperature value in degree fahrenhite ");
scanf("%f",&f2);
c2 = (f2 - 32)*5/9;
k2 = c2 + 273.15 ;
printf("This temperature is equals to %.2f celcius and %.2f kelvin\n",c2,k2);

// from kelvin
float c3=0.0f,f3=0.0f,k3=0.0f;
printf("Enter the temperature value in kelvin ");
scanf("%f",&k3);
c3 = k3 - 273.15;
f3 = (9*c3)/5 + 32;
printf("This temperature is equals to %.2f celcius  and %.2f fahrenhite\n",c3,k3);

// weight converter

// kg to pound
float kg=0.0f,pound=0.0f;
printf("Enter the value of weight in kgs ");
scanf("%f",&kg);
pound = kg * 2.205 ;
printf("The value of the weight in pounds is %.2f\n",pound);


// pound to kg
float kg2=0.0f,pound2=0.0f;
printf("Enter the value of weight in pounds ");
scanf("%f",&pound2);
kg2 = pound2 * 0.453 ;
printf("The value of the weight in kg is %.2f\n",kg2);

//rupee to pound conversion
float inr = 0.0f, pound =0.0f;
printf("Enter the amount in INR ");
scanf("%f",&inr);
pound = inr * 0.0100;
printf("The value in pounds is %.3f\n",pound);


//pound to rupee conversion
float inr2 = 0.0f, pound2 =0.0f;
printf("Enter the amount in pounds ");
scanf("%f",&pound2);
inr2 = pound2 * 100.7;
printf("The value in INR is %.3f\n",inr2);

// BMI Calculator
float weight = 0.0f, height = 0.0f, bmi = 0.0f;
printf("Enter the height in metres ");
scanf("%f",&height);
printf("Enter the height in kgs ");
scanf("%f",&weight);
bmi = weight/(height*height);
printf("The B.M.I is %.2f",bmi);

// Take input for no of days and salary per day for an employee. Compute final salary and also the salary after giving a bonus of 20%
int  noDays = 0, salaryPerDay = 0, originalSalary = 0 ;
float salaryWithBonus = 0.0f;

printf("Enter the no of days in the month ");
scanf("%d",&noDays);
printf("Enter the salary per day of the employee ");
scanf("%d",&salaryPerDay);
originalSalary = noDays * salaryPerDay;
salaryWithBonus = 1.2 * originalSalary ;
printf("Original salary is %d\n",originalSalary);
printf("Salary with bonus is %.2f\n",salaryWithBonus);

// memory address representation
int a=12;
printf("%p\n",&a); // hexadecimal with leading zero
printf("%u\n",&a); // decimal representation
printf("%X\n",&a); // hexadecimal without leading zero in capital letters
printf("%x\n",&a); // hexadecimal without leading zero in small letters

// take a sentence as an input and paste it with "Hello, World!" in the next line.
char s[100];
scanf("%[^\n]%*c", &s);
printf("Hello, World!\n%s",s);

return 0;
}