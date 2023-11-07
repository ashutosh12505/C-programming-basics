/*
Reading functions :

[1] fgetc()
[2] fgets()
[3] fread()
[4] fscanf()

Writing functions :

[1] fputc()
[2] fputs()
[3] fwrite()
[4] fprintf()

EOF (End Of File) : special marker used in file handling to indicate the end of a file. the EOF marker does not represent a character or a byte in the file, but rather a condition that indicates that there is no more data to be read from the file.

The value of EOF is implementation-defined and can vary depending on the compiler and operating system being used.

However, in most implementations, the value of EOF is -1. This value is used to indicate that the end of the file has been reached, and that there is no more data to be read from the file.

There is no ASCII code for EOF (End-of-File) because it is not a printable character.

The EOF marker is a condition that is returned by input/output functions when there is no more data to read from or write to a file. It is not a character that can be represented by an ASCII code, but rather a special value that is often defined as a macro constant, such as EOF, with a value of -1 in most C implementations.

26 is the ASCII code for the Substitute (SUB) character. on some older systems, the end-of-file marker was a CTRL-Z character, which had an ASCII code of 26.

But in modern systems, the EOF marker is not represented by a specific character or code, but rather a special condition that is returned by input/output functions when there is no more data to read from or write to a file. In C programming language, this condition is represented by the EOF constant, which has a value of -1.

It is not a printable character, so you cannot directly print its value as a character. However, you can print its integer value using the %d format specifier.
*/
#include <stdio.h>

int main() {
   printf("The value of EOF is %d\n", EOF);// output : The value of EOF is -1
   return 0;
}
// the actual value of EOF may vary depending on the implementation, but in most C implementations, it is defined as -1.
// EOF is a pre-defined macro constant
// other way to denote the end : feof();
// feof(); returns false till the end of the file is reached. at the end of the file it returns 0 (true).
// Simple operations
#include<stdio.h>
int main()
{
FILE * filePointer;
filePointer = fopen("Text 01.txt","w");
fputs("This line will be written in the file using codes. This is a basic file handling operation.\nThis text will be in a new line, not in the same line.",filePointer);
fputs("This line, however, will be in the same line.\tThese escape sequences are working similar to their functionality in printf() function.",filePointer);
int number = 400;
fprintf(filePointer,"\n\nThe insertion of data can also be done through fprintf() function. The benefit is that we can use format specifiers like %d as we do in the case of printf() function.",number);

fclose(filePointer);
return 0;
}
// while(true){} : true/false comes from <stdbool.h> library
// WAP to take input as numbers and write them in a file
#include<stdio.h>
#include<stdbool.h>
int main()
{
FILE * filePointer;
filePointer = fopen("Text 02.txt","w");
int i=0;
fprintf(filePointer,"Looping can also be done in a file\n\n");
for (i=0;i<11;i++)
{
    fprintf(filePointer,"number %d, ",i);
}
int inputNumber;
while(true)
{
printf("\nEnter the number you want to store.\nEnter -1 to quit : ");
scanf("%d",&inputNumber);
if(inputNumber == -1)
break;
else
fprintf(filePointer,"\n\n%d",inputNumber);
}
fclose(filePointer);
return 0;
}
// WAP to write any number and read the number from a file
#include<stdio.h>
#include<stdbool.h>
int main()
{
FILE *filePointer,*filePointerTwo;
filePointer = fopen("Text 03.txt","w");
int i=0;
printf("Write any number to scan from the file : ");
scanf("%d",&i);
fprintf(filePointer,"%d",i);
fclose(filePointer);
filePointerTwo = fopen("Text 03.txt","r");
int fileNumber;
fscanf(filePointerTwo,"%d",&fileNumber);
printf("The entered number is : %d",fileNumber);
fclose(filePointerTwo);
return 0;
}
//fscanf() returns EOF when it can no longer read any data from any file
// WAP to read numbers from new lines in a file
#include<stdio.h>
int main()
{
FILE *filePointer,*filePointerTwo;
int i,num,fileNum;
filePointer = fopen("Text 03.txt","w");
printf("\nEnter five numbers : ");
for(i=0;i<5;i++)
{
    scanf("%d",&num);
    fprintf(filePointer,"%d\n",num);
}
fclose(filePointer);
filePointerTwo = fopen("Text 03.txt","r");
while(fscanf(filePointerTwo,"%d",&fileNum) != EOF)
{
printf("\nNumber is : %d",fileNum);
}
fclose(filePointerTwo);
return 0;
}
// <<--------------------------------------------------->>
// reading character by character
#include<stdio.h>
int main()
{
// Text 03.txt contains : Ashutoshuvwxyz
FILE *filePointer;
filePointer = fopen("Text 03.txt","r");
// fgetc() stores the ASCII value of the characters present inside the file
char c = fgetc(filePointer);
printf("The character is %c\n",c); // A
c = fgetc(filePointer);
printf("The character is %c\n",c); // s
c = fgetc(filePointer);
printf("The character is %c\n",c); // h
c = fgetc(filePointer);
printf("The character is %c\n",c); // u
c = fgetc(filePointer);
printf("The character is %c\n",c); // t
c = fgetc(filePointer);
c = fgetc(filePointer);
c = fgetc(filePointer);
c = fgetc(filePointer);
c = fgetc(filePointer);

printf("The character is %c\n",c); // v
// every time we call the function fgetc() and pass the parameter as the file pointer, the cursor advances one position
fclose(filePointer);
return 0;
}
// reading all characters at once
#include<stdio.h>
int main()
{
char c;
FILE *filePointer;
// Text 03.txt contains : ashutoshkumarsingh
filePointer = fopen("Text 03.txt","r");
while((c = fgetc(filePointer)) != EOF)
{
    printf("%c ",c); // a s h u t o s h k u m a r s i n g h
}
fclose(filePointer);
return 0;
}
// reading using fgets()
#include<stdio.h>
int main()
{
char str[20]; // this size doesn't affect the output as there is no bound checking in C
FILE *filePointer;
// Text 03.txt contains : ashutoshkumarsingh
filePointer = fopen("Text 03.txt","r");
fgets(str,10,filePointer); // fgets(<destination>,<size_to_be_read>,<filePointer>)
printf("%s",str); // ashutoshk
// though the size to be printed was given as 10 in fgets() argument, only 9 elements are printed because the last character is always NULL character which can't be printed
fclose(filePointer);
return 0;
}
// writing using fputc() and fputs()
// fputc() returns the written character, and in case of any error it returns -1 (EOF)
// fputc(character_to_be_written,filePointer);
// fputc('A',filePointer); writes 'A' in the file, if we pass "A" in the argument then its a compile time error

// -------------------
#include<stdio.h>
int main()
{
FILE *filePointer;
filePointer = fopen("Text 03.txt","w");
fputc('A',filePointer); 
fputs("This is a string",filePointer);
// final output in the file : AThis is a string
fclose(filePointer);
return 0;
}
// -------------------
#include<stdio.h>
int main()
{
FILE *filePointer;
filePointer = fopen("Text 03.txt","w");
fputc('A',filePointer);
filePointer = fopen("Text 03.txt","w");
fputs("This is a string",filePointer);
// final output in the file : Ahis is a string
fclose(filePointer);
return 0;
}
// -------------------

#include<stdio.h>
int main()
{
FILE *filePointer;
filePointer = fopen("Text 03.txt","w");
fputc('A',filePointer);
fclose(filePointer);
filePointer = fopen("Text 03.txt","w");
fputs("This is a string",filePointer);
// final output in the file : This is a string
fclose(filePointer);
return 0;
}
// -------------------
#include<stdio.h>
int main()
{
FILE *filePointer;
filePointer = fopen("Text 03.txt","w");
fputc('A',filePointer);
fclose(filePointer);
filePointer = fopen("Text 03.txt","a");
fputs("This is a string",filePointer);
// final output in the file : AThis is a string
fclose(filePointer);
return 0;
}