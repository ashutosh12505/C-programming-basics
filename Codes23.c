/*
fread() and fwrite() : to read/write objects or binary files. arrays - homogeneous and objects - heterogeneous. for homogeneous data, "w" can be the mode
void *ptr: A pointer to the data to be written. This is a void pointer because fwrite() can write any type of data.
fwrite() takes 4 parameters : (void *ptr,size_of_each element,no_of_characters,filePointer)
it reaturns the number of characters it is writing in the file

Program showing the use of fwrite()
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
FILE *fp;
int count;
char str[]="Programming in C";
fp=fopen("Welcome.txt","w");
if(fp==NULL)
{
printf("\n The file could not be opened");
exit(1);
}
count=fwrite(str,1,strlen(str),fp);//void *,size,no.of objects,file pointer
printf("\n%d bytes were written to the file",count);
fclose(fp);
return 0;
}
/*fread() 
The fread() used to read a block of data from a file. It takes four parameters:
(void *ptr_to_the_destination,size_of_each element,no_of_characters,filePointer)
A pointer to the memory location where the data read from the file will be stored. This parameter is of type void*.
The size, in bytes, of each element that is to be read from the file. This parameter is of type size_t.
The number of elements to read from the file. This parameter is of type size_t.
A pointer to the file object that is being read from. This parameter is of type FILE*.
The function returns the total number of elements successfully read from the file. If this number is less than the number of elements requested, it indicates that the end of the file has been reached, or an error has occurred.

Program showing the use of fread()
*/
#include<stdio.h>
int main()
{
FILE *fp;
char str[9];
fp=fopen("student1.txt","r");
if(fp==NULL)
{
printf("\n The file could not be opened");
}
fread(str,1,8,fp);//void *,size,count,file pointer
str[8]='\0'; // withput adding null character at the last the data is an array of characters, not a string
printf("\n Data read from the file is:%s",str);
fclose(fp);
return 0;
}
/*
for writing heterogeneous data in a file :
fwrite(&e[i], sizeof(e[i]), 1, filePointer);

here, &e[i] == address of each record,
sizeof(e[i]) == size of each record
1 == number of records to be written in one iteration
filePointer == pointer to the file where data is being written

Program showing the use of fwrite() for writing heterogeneous data
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
struct employee
{
int emp_code;
char name[20];
int hra;
int da;
int ta;
};
FILE *fp;
struct employee e[5];
int i,x;
fp=fopen("Employee.txt","wb");
if(fp==NULL)
{
printf("\n Error Opening file");
exit(1);
}
printf("\n Enter the details:");
for(i=0;i<2;i++)
{
printf("\n\n Enter the employee code:");
scanf("%d",&e[i].emp_code);
fflush(stdin);
printf("\n\n Enter the name of the employee:");
gets(e[i].name);
fflush(stdin);
printf("\n\n Enter the HRA,DA and TA:");
scanf("%d%d%d",&e[i].hra,&e[i].da,&e[i].ta);
x=fwrite(&e[i],sizeof(e[i]),1,fp);
printf("\n%d",x);
}
fclose(fp);
return 0;
}
// Using fread() for heterogeneous data
#include<stdio.h>
#include<stdlib.h>
int main()
{
struct employee
{
int emp_code;
char name[20];
int hra;
int da;
int ta;
};
FILE *fp;
struct employee e;
int i,x;
fp=fopen("Employee.txt","rb");
if(fp==NULL)
{
printf("\n Error Opening file");
exit(1);
}
printf("\n THE DETAILS OF THE EMPLOYEE ARE:");
while(1)
{
fread(&e,sizeof(e),1,fp);
if(feof(fp))
break;
printf("\n\n Employee Code:%d",e.emp_code);
printf("\n\n Name:%s",e.name);
printf("\n\n HRA,DA and TA:%d %d %d",e.hra,e.da,e.ta);
}
fclose(fp);
return 0;
}
// Using fread() for heterogeneous data
#include<stdio.h>
#include<stdlib.h>
int main()
{
FILE *fp;
struct emp
{
char name[40];
int age;
float bs;
};
struct emp e;
fp=fopen("Employee.txt","r");
if(fp==NULL)
{
puts("Cannot open file");
exit(1);
}
while(fscanf(fp,"%s%d%f",e.name,&e.age,&e.bs)!=EOF)
{
printf("\n%s %d %.2f",e.name,e.age,e.bs);
}
fclose(fp);
}
/*to trace the end of any file :

(1) feof() function : returns 0 everywhere, returns true value at the end of the file. parameter == <filePointer>
(2) EOF (macro) : while(filePointer != EOF)

structure data is read from a file using fscanf()

sequential access : first-last
random access : fseek() function
parameters of fseek() : (filePointer, offset, whence);
offset : distance to move in the file. can be either positive or negaive
whence : reference position. three types - SEEK_SET, SEEK CUR, SEEK_END

SEEK_SET : beginning : offset always positive
SEEK_CUR : current position : offset can be either positive or negative
SEEK_END : at the last position of the file : offset is always negative

fseek(); will help in moving the cursor to any particular position in the file
to tell the current position of cursor, ftell(filePointer) is used. it returns integer value
printf("%d",ftell(filePointer));
to move the cursor to the end : fseek(filePointer, 0, SEEK_END);
fscanf(filePointer, "%s", str);
printf(filePointer, "%s", str);

to reset the position of cursor, rewind(filePointer); or fseek(filePointer, 0, SEEK_SET);
*/
// C Program to demonstrate the use of fseek()
#include <stdio.h>
int main()
{
FILE *fp;
char str[12];
fp = fopen("test.txt", "r");
printf("\n Cursor Position : %ld", ftell(fp));
fseek(fp, 0, SEEK_END);// Moving pointer to end
printf("\n%ld", ftell(fp));
fseek(fp, -4, SEEK_END);
fscanf(fp,"%s",str);
printf("\n%s",str);
printf("\n%ld", ftell(fp));// Printing position of pointer
rewind(fp);
printf("\n%ld", ftell(fp));
fseek(fp, 2, SEEK_SET);
fseek(fp,2,SEEK_CUR);
fgets(str,12,fp); // can read max 11 characters
printf("\n%s",str);
return 0;
}