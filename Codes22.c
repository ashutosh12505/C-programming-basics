// different modes
// r+ : opening an existing text file for both reading and writing. It will replace the existing content with that of new content only from the begininng, rest text will be the same
#include<stdio.h>
int main()
{
// Text 03.txt contains : abcdefgh
FILE *filePointer;
filePointer = fopen("Text 03.txt","r+");
fputs("PQRS",filePointer);
// new content : PQRSefgh
fclose(filePointer);
return 0;
}
// w+ : if text is present in the file, it truncates it to zero length and then writes into it. if file doesn't exist, then a new file is created. can be used for both reading and writing
#include<stdio.h>
int main()
{
// Text 03.txt contains : abcdefghijklmnopqrstuvwxyz
FILE *filePointer;
filePointer = fopen("Text 03.txt","w+");
fputs("Ashutosh",filePointer);
// new content : Ashutosh
fclose(filePointer);
return 0;
}
// a+ : the reading will start from the begininng but writing can only append to file. if file doesn't exist then a new file is created
#include<stdio.h>
int main()
{
// Text 03.txt contains : Ashutosh
FILE *filePointer;
filePointer = fopen("Text 03.txt","a+");
fputs(" Kumar Singh",filePointer);
// new content : Ashutosh Kumar Singh
fclose(filePointer);
return 0;
}
// moving to a specific location in a file
// fseek() : used to move the cursor to different positions in a file

// ftell() : tells the byte location of current position in the file pointer. to know the size of any file, move to the last and get the byte location
#include<stdio.h>
int main()
{
// Text 03.txt contains : Ashutosh Kumar Singh
FILE *filePointer;
filePointer = fopen("Text 03.txt","a+");
fseek(filePointer,0,SEEK_END);
printf("The size of the file is %d bytes",ftell(filePointer));
// output : The size of the file is 20 bytes
fclose(filePointer);
return 0;
}
// rewind() : moves the control to the begininng of the file
// fclose() : closes the file and returns zero. if fails due to any reason then returns -1

// <<------------------------------------------------>>

// WAP to read data from a file and print it on the console using fgetc();
#include<stdio.h>
#include<stdlib.h> // for the exit(); function
int main()
{
FILE *fp;
char str[10000];
int i=0,ch;
fp=fopen("student1.txt","r");
if(fp==NULL)// error handling code
{
printf("\nThe file could not be opened");
exit(1); // non-zero means error, zero means no error
}
ch=fgetc(fp);
while(ch!=EOF)
{

str[i]=(char)ch;// to print at once, not character by character
ch=fgetc(fp);
i++;
}
str[i]='\0';// for storing null character at the last position
printf("\n%s",str);
fclose(fp);
}
// Using fgets(); == line by line
#include<stdio.h>
#include<stdlib.h>
int main()
{
FILE *fp;
char str[10];
fp=fopen("Text 03.txt","r");
if(fp==NULL)
{
printf("\n File could not be opened");
exit(1);
}
while(fgets(str,10,fp)!=NULL) // prints only 10 characters in a line. when new line (\n) is encountered, it skips reading and the program is over
printf("\n%s",str);
fclose(fp);
return 0;
}
// fputc() is for writing data in the file character by character. Program showing use of fputc()
#include<stdio.h>
#include<stdlib.h>
int main()
{
FILE *fp;
char feedback[100];
int i;
fp=fopen("Comments.txt","w");
if(fp==NULL)
{
printf("\nThe file could not be opened");
exit(1);
}
printf("\n Enter some string:");
gets(feedback);
for(i=0;feedback[i]!='\0';i++)
{
fputc(feedback[i],fp); // no output on the console, only the data is written in the file
}
fclose(fp);
return 0;
}
// fputs() writes data in the file line by line. Program showing the use of fputs()
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
FILE *fp;
char s[80];
fp=fopen("Poem.txt","w");
if(fp==NULL)
{
puts("Cannot open file");
exit(1);
}
printf("\n Enter a few lines of text:\n");
while(strlen(gets(s))>0) // becomes false when any line without any character is entered
{
fputs(s,fp);
fputs("\n",fp);
}
fclose(fp);
// strlen() returns the length of the string without counting the null character
// sizeof("Hello"); == 6 (with null character)
// strlen("Hello"); == 5
return 0;
}
/*
fprintf() and fscanf() are used for writing heterogeneous data in the file. both take arbitrary number of arguments
fscanf() can read data through file as well as keyboard.
to read from file : 
x = fscanf(filePointer,"%s %d",name,&roll_number);
printf("%d",x); == number of values being read from the file 

Program showing use of fprintf()*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
FILE *fp;
int i;
char name[20];
float salary;
fp=fopen("Details.txt","w");
if(fp==NULL)
{
printf("\n The file could not be opened");
exit(1);
}
for(i=0;i<3;i++)
{
puts("\n Enter your name:");
gets(name);
fflush(stdin);
puts("\n Enter your salary:");
scanf("%f",&salary);
fprintf(fp,"%s \t %.2f\n",name,salary);
fflush(stdin);
}
fclose(fp);
return 0;
}
/*
to read from the keyboard :
fscanf(stdin,"%s %d",name,&roll_number);
this is similar to scanf();

Program showing the use of fscanf()
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
FILE *fp;
char name[80];
int roll_no;
int x;
fp=fopen("Checking.txt","r");
if(fp==NULL)
{
printf("\n File could not be opened");
exit(1);
}
/*printf("\nEnter the name and roll number of the student");
//READ FROM KEYBOARD
fscanf(stdin,"%s%d",name,&roll_no);
printf("\n NAME:%s \t ROLL NUMBER=%d",name,roll_no);*/
//READ FROM FILE Checking.txt

x=fscanf(fp,"%s%d",name,&roll_no);
printf("\n NAME:%s\t ROLL NUMBER=%d",name,roll_no);
printf("\n%d",x);//Number of values we are reading
fclose(fp);
return 0;
}