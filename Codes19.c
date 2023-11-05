// another way of initialisation : taking input from the user
// WAP to read and display information of a student using structure
#include <stdio.h>
struct student
{
char name[50];
int roll;
float marks;
};
int main()
{
struct student s;
printf("Enter information for first student:\n");
printf("Enter name: ");
gets(s.name); // not '&s.name' because variable name is the address while taking string input
// gets(s.name) and puts(s.name) while dealing with string input/output
printf("Enter roll number: ");
scanf("%d", &s.roll);
printf("Enter marks: ");
scanf("%f", &s.marks);
printf("Displaying Information:\n");
printf("Name: ");
puts(s.name);
printf("Roll number: %d\n",s.roll);
printf("Marks: %.1f\n", s.marks);
return 0;
}
/*
struct student
{
    //body
};

here, student is a datatype and like other datatypes, array of structure can also be created for student.

Array of structures

WAP to read and display information of multiple number of books in a library
*/
#include <stdio.h>
struct bookInfo
{
char name[25];
int pages;
float price;
};
int main()
{
struct bookInfo book[20];
int i,n;
printf("\nEnter number of records you want to enter(less than or equal to 100) : ");
scanf("%d",&n);
fflush(stdin);
for(i=0;i<n;i++)
{
    printf("\nEnter the Name of Book : ");
    gets(book[i].name);
    fflush(stdin);//It is used to clear the input buffer(stdin is the keyboard)
    printf("\nEnter the Number of Pages : ");
    scanf("%d",&book[i].pages);
    fflush(stdin);
    printf("\nEnter the Price of Book : ");
    scanf("%f",&book[i].price);
    fflush(stdin);
}
printf("\n------------ Book Details ------------\n\n");
for(i=0;i<n;i++)
{
    printf("\nName of Book : %s",book[i].name);
    printf("\nNumber of Pages : %d",book[i].pages);
    printf("\nPrice of Book : %.2f",book[i].price);
    printf("\n\n");
}
return 0;
}
/*
Buffer : temporary storage in the memory which takes and transfers data
sometimes data remains in the buffer after it is transferred, and the compiler mis-understands that input has already been taken and skips the next input statement.
fflush(stdin);  // to clear the buffer by flushing the standard input being taken from the keyboard. it is defined in the header file : stdio.h

>> memory representation of structure of two books :

         Book_1                  Book_2
[<name>|<pages>|<price>] [<name>|<pages>|<price>]

>> for copying the data of one structure variable to another variable, assignment operator is used
*/
#include <stdio.h>
struct student
{
char name[50];
int roll;
float marks;
};
int main()
{
struct student s,s1; // s is the source of data, s1 is the destination
printf("Enter information below\n");
printf("Enter name : ");
gets(s.name); // & is not required for strings
printf("Enter roll number : ");
scanf("%d", &s.roll);
printf("Enter marks : ");
scanf("%f", &s.marks);
s1=s; // Copying data from one structure variable to another, initially s1 had garbage values
/*
s1.name = s.name;
s1.roll = s.roll;
s1.marks = s.marks;

these are not required, simply s1=s;
*/
printf("Displaying Information:\n");
printf("Name : ");
puts(s1.name);
printf("Roll number : %d\n",s1.roll);
printf("Marks : %.1f\n", s1.marks);
return 0;
}
/* comparing structure variables

if(s1.marks>s.marks)
{
    printf("Student one has got better marks");
}
else
{
    printf("Student two has got better marks");
}

nested structures : structure inside structure
*/
#include<stdio.h>
struct Address
{
char Housename[25];
char City[25];
char Streetname[25];
};
struct Employee
{
int Id;
char Name[25];
float Salary;
struct Address Add; // structure as an object
};
int main()
{
struct Employee E;
printf("\n\tEnter Employee Id : ");
scanf("%d",&E.Id);
fflush(stdin);
printf("\n\tEnter Employee Name : ");
gets(E.Name);
fflush(stdin);
printf("\n\tEnter Employee Salary : ");
scanf("%f",&E.Salary);
fflush(stdin);
printf("\n\tEnter Employee House Name : ");
gets(E.Add.Housename);
fflush(stdin);
printf("\n\tEnter Employee street name : ");
gets(E.Add.Streetname);
fflush(stdin);
printf("\n\tEnter Employee City : ");
gets(E.Add.City);
fflush(stdin);
printf("\n\tDetails of the Employee are :\n\n");
printf("\n\tEmployee Id : %d",E.Id);
printf("\n\tEmployee Name : %s",E.Name);
printf("\n\tEmployee Salary : %.2f",E.Salary);
printf("\n\tEmployee address : %s",E.Add.Housename);
printf(", %s",E.Add.Streetname);
printf(", %s",E.Add.City);
return 0;
}
// There are two ways of defining nested structures - (i) stand alone, and (ii) embedded structures
// stand alone structure is defined independently, and is just used in any other structure
#include <stdio.h>

struct Date_chatgpt {
    int day;
    int month;
    int year;
};

struct Employee_chatgpt {
    int id;
    char name[50];
    struct Date_chatgpt birthdate;
};

int main() {
    struct Employee_chatgpt emp1 = { 1001, "John Doe", { 5, 12, 1990 } };
    
    printf("Employee ID: %d\n", emp1.id);
    printf("Employee Name: %s\n", emp1.name);
    printf("Birthdate: %d/%d/%d\n", emp1.birthdate.day, emp1.birthdate.month, emp1.birthdate.year);
    
    return 0;
}
// an embedded structure is a structure that is defined inside another structure, without being given a name. This makes the embedded structure anonymous and can be used as a member of the enclosing structure.An embedded structure is also known as an unnamed or anonymous structure. It is used to group related data together and make the code more organized and readable.To define an embedded structure, we simply define the structure inside the enclosing structure without giving it a name. For example:
struct Employee_chatgpt_new {
    int id;
    char name[50];
    struct { // name is not given, directly variable is created
        int day;
        int month;
        int year;
    } hiredate;
};
// WAP to implement nested structure using embedded structure
#include <stdio.h>
struct Employeedetails
{
char ename[20];
int ssn;
float salary;
struct dob // or simply 'struct'
{
int date;
int month;
int year;
}db1;

}emp = {"Aniket",1000,1000.50,{22,6,1990}};
int main()
{
printf("\nEmployee Name : %s",emp.ename);
printf("\nEmployee SSN : %d",emp.ssn);
printf("\nEmployee Salary : %.2f",emp.salary);
printf("\nEmployee DOB : %d/%d/%d",emp.db1.date,emp.db1.month,emp.db1.year);
return 0;
}
// # In C, any integer value that starts with a leading zero is interpreted as an octal number (base 8). The digits 0 to 7 are valid digits in octal notation, but 8 and 9 are not.
#include <stdio.h>
struct EmployeeDetailsLast
{
char ename[20];
int ssn;
float salary;
struct
{
int date;
int month;
int year;
}db1;

}emp = {"Aniket",1000,1000.50,{22,6,1990}},emp2 = {"Ashutosh",1200,125050.7,{30,11,2002}};// dob month cannot be 08 or 09 because it will be treated as octal number if it starts with zero and 8 and 9 are not octal digits. on writing 09 it is a syntax error 'invalid octal digit'
int main()
{
printf("EMPLOYEE ONE\n\n");
printf("\nEmployee Name : %s",emp.ename);
printf("\nEmployee SSN : %d",emp.ssn);
printf("\nEmployee Salary : %.2f",emp.salary);
printf("\nEmployee DOB : %d/%d/%d",emp.db1.date,emp.db1.month,emp.db1.year);
printf("\n\nEMPLOYEE ONE\n\n");
printf("\nEmployee Name : %s",emp2.ename);
printf("\nEmployee SSN : %d",emp2.ssn);
printf("\nEmployee Salary : %.2f",emp2.salary);
printf("\nEmployee DOB : %d/%d/%d",emp2.db1.date,emp2.db1.month,emp2.db1.year);
return 0;
}