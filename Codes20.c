/*
Union : A user defined datatype, these are collection of heterogenous data elements like structures.
They are different from structures in the way they take memory.
Union takes one memory location at a time for storing the values of all the attributes. they follow memory sharing.
Union takes memory equals to the memory taken by the largest attribute/data-element (not datatype)
*/
#include<stdio.h>
#pragma pack(1)
union example1
{
    int a;
    float b;
    double c;
};
int main()
{
union example1 e1;
printf("%d",sizeof(e1)); // prints 8
return 0;
}
#include<stdio.h>
#pragma pack(1)
union example2
{
    int a;
    float b;
    char c[20];
};
int main()
{
union example2 e2;
printf("%d",sizeof(e2)); // prints 20
return 0;    
}
/*
Simultaneous initialization is not allowed in unions
The memory location is given to all the attributes one-by-one
advantage : consumes less memory
used when all values are not required at once
we can have the nesting of unions, unions & structures and vice-versa
*/
#include <stdio.h>
#include <string.h>
union Data {
int i;
float f;
char str[20];
char str1[20];
};
int main()
{
union Data object;
object.i = 10;
printf( "data.i : %d\n", object.i);
object.f = 220.5;
printf( "data.f : %f\n", object.f);
strcpy( object.str, "C Programming");
printf( "data.str : %s\n", object.str);
strcpy( object.str1, "C++");
printf( "data.str : %s\n", object.str1);
return 0;
}
// if we assign all values at once and access at once, then only last value can be accessed
// in case of unions, datatype matters more than variable name. if format specifier in the print statement is same as the last stored value, then that value will be displayed even if the variable name is different
#include<stdio.h>
union data
{
    int x,y;
};
int main()
{
union data object;
object.x = 12;
printf("%d",object.y); // prints 12
return 0;
}

#include<stdio.h>
union data
{
    int x;
    char y;
    float z;
};
int main()
{
union data object;
object.x = 97;
printf("%c\n",object.y); // prints 'a', the ASCII code character of 97
printf("%f\n",object.y); // prints 0.000000
object.z = 97.3242;
printf("%d\n",object.z); // prints garbage value (not 97 after truncating the decimal part)
// this is because there is a close association between characters and integers, but no association between floats and integers
printf("%c\n",object.y); // can't be accessed now
return 0;
}

// WAP to read and display one record using union
#include<stdio.h>
union employee
{
char name[30];
int id;
float salary;
}u; // global variable
int main()
{
//union employee u2; // if initialised here, u2 would have been local variable
printf("\n Enter name : ");
gets(u.name);//Initialization
printf("\n Entered name is : %s",u.name);//Accessing
printf("\n Enter id : ");
scanf("%d",&u.id);//Initialization
printf("\n Entered id is : %d",u.id);//Accessing
printf("\n Enter salary : ");
scanf("%f",&u.salary);//Initialization
printf("\n Entered salary is : %.2f",u.salary);//Accessing
return 0;
}

/* Array of unions : every index will have memory equal to the size of largest data element in the union declaration
{
char name[30];
int id;
float salary;
}u[100]; // this is declaration of an array of 100 unions
*/
#include<stdio.h>
union employee_using_union
{
char name[30];
int id;
float salary;
};
int main()
{
union employee_using_union u[20];
int n,i;
printf("\n Enter value of n : ");
scanf("%d",&n);
fflush(stdin);
for(i=0;i<n;i++)
{
printf("\n Enter name : ");
fflush(stdin);
gets(u[i].name);
printf("\n Entered name is : %s",u[i].name);
printf("\n Enter id : ");
fflush(stdin);
scanf("%d",&u[i].id);
printf("\n Entered id is : %d",u[i].id);
printf("\n Enter salary : ");
fflush(stdin);
scanf("%f",&u[i].salary);
printf("\n Entered salary is : %.2f",u[i].salary);
}
return 0;
}

/*
        File handling

file : collection of data which is stored permanently
steps :

(i)   opening the file (not manually)
(ii)  pointing the file to buffer(temporary storage)
(iii) read/write is done on the buffer and later transferred to the file
(iv)  closing the file [necessary step to clear the buffer]

function to open the file : fopen(); which is defined in the stdio.h library

fopen() returns the address of the file, which can also be assigned to any variable. when the file is not opened, the fopen() function returns NULL

FILE *fp; is a declaration statement in C, which declares a variable named fp of type FILE * (pointer to FILE structure).

In C, a FILE structure is used to represent a file that is opened for reading or writing. By declaring a variable of type FILE *, we create a pointer that can store the memory address of a FILE structure.

The fp variable is commonly used as a file pointer in C programs. After opening a file with fopen, we assign the pointer returned by fopen to fp. This allows us to perform various operations on the file, such as reading or writing data.
FILE is an inbuilt structure
fopen(); has two parameters : fopen("file_Name_With_Address",file_Mode);

basic file opening modes :

r (read) : returns NULL value (error) if the file doesn't exist, or is corrupt or permission is denied
w (write) : previous data is erased from the file, file gets created if it isn't already present
a (append) : writes at the end of the file so previous data is preserved, creates file if it is not already existing
ab, rb, wb modes are used for opening binary files, with same functionality

types of files : text files and binary files

text file :
[1] stores data which can easily be understood and viewed by the user
[2] little bit slower, because it conversion between human language and machine language
[3] not secure as it is easy to understand, its extension is '.txt'

binary file :
[1] faster because no conversion is involved, data is stored in a format that is optimized for the computer's hardware

.dat files : .dat is a file extension that is often used to indicate a generic data file. The .dat extension is not associated with any specific file format or application, and the contents of a .dat file can vary depending on the application that created it.

In many cases, a .dat file may be a binary file that contains structured data in a format that is specific to the application that created it. For example, a database application may store its data in a binary .dat file that can only be read by that application.

However, the .dat extension can also be used for text files that contain data in a simple delimited or fixed-width format. 

closing the file : fclose(<file_pointer>);
*/