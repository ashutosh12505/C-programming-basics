/*
remove("file_name"); == to delete the file
rename("old_name","new_name"); == to rename the file using codes
remove() and rename() are example of OS level functions
COORD cord = {0, 0};
COORD is a structure, cord is a variable
<graphics.h> contains gotoxy(); inbuilt function
system("cls"); == to clear the screen
strcmp(a, b) == 0 if 'a' and 'b' are equal

# for deletion,

fp => original file pointer, ft => temporary file pointer
when the record to be deleted is found in the original file, it is skipped and everything else is copied to the temporary file. after that the temporary file is renamed as the original file

while (fread(&e, size, 1, filePointer) == 1)
{
    if( strcmp(e.name,emp_name) != 0)
    fwrite(&e, size, 1, temp_filePointer);
}

fread(&e, size, 1, filePointer) returns 1 if it is reading, else 0 if it doesn't read
strcmp(a,b) == 0 if (a == b), -1 if (a < b), 1 if (a > b)
strcmp does ASCII code comparision at the mismatch point. lower case letters have higher ASCII code and vice-versa

modifying record();

logic : modify the name which is matching

while (fread(&e, size, 1, filePointer) == 1)
{
    if (strcmp(e.name,ename) == 0)
    {
        printf("Enter new name : ");
        ---------------------------
        ---------------------------
    }
}

in file => after searching for the matching record, move the cursor exactly one record backward to do operations. otherwise the next record will be affected. to move the cursor exactly one record backward :

fseek(filePointer, -size, SEEK_CUR);
fwrite(&e, size, 1, filePointer);

different file opening modes :

r+  : reading (major) and writing (minor) purpose
w+  : writing (major) and reading (minor) purpose
a+  : appending (major) and reading (minor) purpose
rb  : reading binary files
wb  : writing binary files
ab  : appending binary files
rb+ : same operation for binary files
wb+ : "      "      "      "
ab+ : "      "      "      "

if file doesn't already exist then it will be created in the write and append modes.
append == writes at the end. data cannot be overwritten in this mode.

Sample project code*/
#include<stdio.h>
#include<stdlib.h>
struct student
{int rollno;
char name[30];
float mark;
}stud;
// FUNCTION TO INSERT RECORDS TO THE FILE
void insert()
{
FILE *fp;
fp = fopen("Record", "a");
printf("Enter the Roll no :");
scanf("%d",&stud.rollno);
printf("Enter the Name :");
scanf("%s", &stud.name);
printf("Enter the mark :");
scanf("%f", &stud.mark);
fwrite(&stud, sizeof(stud), 1, fp);fclose(fp);
}
// FUNCTION TO DISPLAY RECORDS
void disp()
{FILE *fp1;
fp1 = fopen("Record", "r");
printf("\nRoll Number\tName\tMark\n\n");
while (fread(&stud, sizeof(stud), 1, fp1))
printf(" %d\t\t%s\t%.2f\n", stud.rollno, stud.name, stud.mark);
fclose(fp1);
}
// FUNCTION TO DELETE A RECORD
void deletefile()
{
FILE *fpo;
FILE *fpt;
int r, s;
printf("Enter the Roll no you want to delete :");
scanf("%d", &r);
if (avlrollno(r) == 0)
printf("Roll no %d is not available in the file\n", r);
else
{fpo = fopen("Record", "r");
fpt = fopen("TempFile", "w");
while (fread(&stud, sizeof(stud), 1, fpo))
{
s = stud.rollno;
if (s != r)
fwrite(&stud, sizeof(stud), 1, fpt);
}
fclose(fpo);
fclose(fpt);
fpo = fopen("Record", "w");
fpt = fopen("TempFile", "r");
while (fread(&stud, sizeof(stud), 1, fpt))
fwrite(&stud, sizeof(stud), 1, fpo);
printf("\nRECORD DELETED\n");
fclose(fpo);
fclose(fpt);
}}
// FUNCTION TO UPDATE THE RECORD
void update()
{int avl;
FILE *fpt;
FILE *fpo;
int s, r, ch;
printf("Enter roll number to update:");
scanf("%d", &r);
avl = avlrollno(r);
if (avl == 0)
{printf("Roll number %d is not Available in the file", r);
}
else
{fpo = fopen("Record", "r");
fpt = fopen("TempFile", "w");
while (fread(&stud, sizeof(stud), 1, fpo))
{
s = stud.rollno;
if (s != r)
fwrite(&stud, sizeof(stud), 1, fpt);
else
{
printf("\n\t1. Update Name of Roll Number %d", r);
printf("\n\t2. Update Mark of Roll Number %d", r);
printf("\n\t3. Update both Name and Mark of Roll Number %d", r);
printf("\nEnter your choice:");
scanf("%d", &ch);
switch (ch)
{case 1:
printf("Enter Name:");
scanf("%s", &stud.name);
break;
case 2:
printf("Enter Mark : ");
scanf("%f", &stud.mark);
break;
case 3:
printf("Enter Name: ");
scanf("%s", &stud.name);
printf("Enter Mark: ");
scanf("%f", &stud.mark);
break;
default:printf("Invalid Selection");
break;
}fwrite(&stud, sizeof(stud), 1, fpt);
}}
fclose(fpo);
fclose(fpt);
fpo = fopen("Record", "w");
fpt = fopen("TempFile", "r");
while (fread(&stud, sizeof(stud), 1, fpt))
{fwrite(&stud, sizeof(stud), 1, fpo);
}
fclose(fpo);
fclose(fpt);
printf("RECORD UPDATED");
}}
// FUNCTION TO CHECK GIVEN ROLL NO IS AVAILABLE //
int avlrollno(int rno)
{
FILE *fp;
int c = 0;
fp = fopen("Record", "r");
while (!feof(fp))
{
fread(&stud, sizeof(stud), 1, fp);

if (rno == stud.rollno)
{
fclose(fp);
return 1;
}
}
fclose(fp);
return 0;
}
main()
{
int c, emp;
do
{printf("\n\t---Select your choice---------\n");
printf("\n\t1. INSERT\n\t2. DISPLAY\n");
printf("\t3. DELETE\n\t4. UPDATE");
printf("\n\t5. EXIT");
printf("\n\n------------------------------------------\n");
printf("\nEnter your choice:");
scanf("%d", &c);
printf("\n");
switch (c)
{case 1:insert();
break;
case 2:
disp();
break;
case 3:
deletefile();
break;
case 4:
update();
break;
case 5:
exit(1);
break;
default:printf("\nYour choice is wrong\nPlease try again...\n");
break;
}}
while (c != 5);
}