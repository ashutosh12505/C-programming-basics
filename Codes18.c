// WAP to print the sum of diagonal elements of any input matrix
#include<stdio.h>
int main()
{
int a[10][10],sum=0;
int i,j,m,n;
printf("Enter number of rows and column:");
scanf("%d%d",&m,&n);
while(m != n)
{
    printf("Diagonal elements are defined only for a square matrix. Rows and columns must be equal.\n\n");
    printf("Enter number of rows and column:");
    scanf("%d%d",&m,&n);
}
printf("Enter Elements : ");
for(i=0;i<m;i++)
{
    for(j=0;j<n;j++)
    {
        scanf("%d",&a[i][j]);
    }
}
for(i=0;i<m;i++)
{
    for(j=0;j<n;j++)
    {
        if(i==j)
        {
            sum=sum+a[i][j];
        }
    }
}
printf("Sum of Diagonal Elements = %d ",sum);
return 0;
}
/*
Structure and union

array = collection of homogeneous data elements
structure = collection of heterogeneous data elements. it is a user defined data-type.

(similar to class in python)

class (python) = collection of attributes and behaviours(functions)
structure (c) = collection of attributes
structure (c++) = public collection of attributes and behaviours
class (c++) = private by default

no memory is created on defining any structure. it is like a template only. memory is created on declaring/creating any variable of that structure

in array of structures, attributes are common, and values are different. in that case different variable can be created, or values can be stored at different locations also.

Syntax :

defining a structure :
*/
#include<stdio.h>
#include<string.h> // for strcpy() function
struct structure_name // structure name is given by following the rules of naming identifiers
{
    char name[20]; // collection of characters == string
    int roll_no;
    float fees;
};
// till now only template is created, no memory is allocated
//creating variables :
int main()
{
struct structure_name s1,s2;/*initially values of all the attributes of all structures are garbage
assigning values :
s1.name = "Aniket"; >>>> this is wrong because in case of strings, the name of the string contains its address. so writing this is similar to changing the address of 'name' attribute, which is not allowed.
for copying strings, strcpy() function is used. <string.h> is the header file which contains this function.
strcpy(<destination>,<source_or_string>)*/
strcpy(s1.name,"Aniket");
s1.roll_no = 11;
s1.fees = 12500.7f;
// garbage values are over-written after assigning is done
printf("Name : %s\nRoll Number : %d\nFees : %.2f",s1.name,s1.roll_no,s1.fees);
return 0;
}
/*syntax for assigning/accessing : object/variable_name<dot_operator>attribute
other way of assigning value : creating global variables*/
#include<stdio.h>
struct student
{
char name[20];
int r_no;
float fees;
}s1={"Aniket",23,2450.50f},s2={"Vishal",24,3450.50f}; // s1 and s2 are accessible throughout the program
int main()
{
printf("\n%s %d %.3f",s1.name,s1.r_no,s1.fees);
printf("\n%s %d %.3f",s2.name,s2.r_no,s2.fees);
return 0;
}
// Other way of initialising structures : declaring objects globally and assigning value locally
#include<stdio.h>
#include<string.h>
struct student
{
char name[20];
int r_no;
float fees;
}s1,s2;
int main()
{
strcpy(s1.name,"Suhail");
s1.r_no=25;
s1.fees=230.98;
printf("%s %d %.2f",s1.name,s1.r_no,s1.fees);
strcpy(s2.name,"Vijay");
s2.r_no=28;
s2.fees=100.98;
printf("\n%s %d %.2f",s2.name,s2.r_no,s2.fees);
return 0;
}
// another way of initialisation : defining structure globally and creating objects/variables locally
#include<stdio.h>
struct student
{
char name[20];
int r_no;
float fees;
};
int main()
{
struct student s1={"Aniket",23,230.56};
struct student s2={"Suhail",24,550.56};
printf("\n%s %d %.2f",s1.name,s1.r_no,s1.fees);
printf("\n%s %d %.2f",s2.name,s2.r_no,s2.fees);
return 0;
}
// another way of initialisation : one variable/object local and another object/variable global
#include<stdio.h>
struct student
{
char name[20];
int r_no;
float fees;
};
struct student s1={"Aniket",23,230.56};//Global object
int main()
{
struct student s2={"Suhail",24,550.56};//Local object
printf("\n%s %d %.2f",s1.name,s1.r_no,s1.fees);
printf("\n%s %d %.2f",s2.name,s2.r_no,s2.fees);
return 0;
}
// if only declaration is done then all the attribute values are garbage. if any one attribute is assigned value then all other values are zero
// while assigning values, sequence matters.
#include<stdio.h>
struct student
{
char name[20];
int r_no;
float fees;
};
struct student s1={"Ankit",50.2f};// 50.2f gets assigned to 'roll_no' attribute of the object s1 and when printed using %d, 50 is printed
int main()
{
printf("\n%s %d %.2f",s1.name,s1.r_no,s1.fees);
return 0;
}
/*
memory is individually taken by each attribute. modern compilers do bit padding to increase the speed of execution of the program, by giving extra memory. old compilers give memory desired as per the definition of the structure. in modern compilers, the size of the largest datatype is checked and memory is given in multiple of that size to every attribute. this is known as bit padding
*/
#include<stdio.h>
struct studentsnew
{
    char name[20];
    int roll_no;
    float fees;
};
int main()
{
struct studentsnew s1;
printf("%d",sizeof(s1)); // prints 28, which is correct as 20 + 4 + 4 == 28
return 0;
}

#include<stdio.h>
struct studentsnew2
{
    char name[19];
    int roll_no;
    float fees;
};
int main()
{
struct studentsnew2 s1;
printf("%d",sizeof(s1)); // prints 28, which should have been 27. extra one byte is used in bit padding
return 0;
}

#include<stdio.h>
#pragma pack(1) // to remove bit padding
struct studentsnew2
{
    char name[19];
    int roll_no;
    float fees;
};
int main()
{
struct studentsnew2 s1;
printf("%d",sizeof(s1)); // prints 27
return 0;
}
/*
bit padding : compiler identifies the datatype with largest size and the memory is allocated in the multiple of that datatype. example :

char name[17];  >> char 1 byte
int roll_no;    >> int 4 bytes
double fees;    >> double 8 bytes

so memory is allocated in the multiple of 8 bytes so that every variable gets memory. minimum required memory is 17+4+8 bytes i.e. 29 bytes. but as 24 bytes are not enough, 32 bytes are allocated. 3 bytes are given due to bit padding.

default answer in exam : without bit padding, theoratical concepts based on simple addition
*/
#include<stdio.h>
#pragma pack(1)
struct studenttwo
{
    char name[17]; // largest data element
    int roll_no;
    double fees;   // largest datatype
};
int main()
{
struct studenttwo s1;
printf("%d",sizeof(s1));
return 0;
}