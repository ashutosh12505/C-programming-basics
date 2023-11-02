/*WAP to read and display elements of a 2D array - nested loops - outer loop for each row - inner row for each column of any particular row

int array[rows][columns];
for(i=0;i<rows;i++)
{
    for(j=0;j<columns;j++)
    {
        printf("%d ",array[i][j]);
    }
    printf("\n");
}
*/
#include<stdio.h>
int main()
{
int rows,columns,i,j,array[50][50];
printf("Enter the number of rows ");
scanf("%d",&rows);
printf("Enter the number of columns ");
scanf("%d",&columns);
for(i=0;i<rows;i++)
{
    for(j=0;j<columns;j++)
    {
        printf("Element in column %d of the row %d is ",j+1,i+1);
        scanf("%d",&array[i][j]);
    }
}
printf("The elements are :\n\n");
for(i=0;i<rows;i++)
{
    for(j=0;j<columns;j++)
    {
        printf("%d   ",array[i][j]);
    }
    printf("\n\n");
}
return 0;
}
// For column major approach, array[j][i] is written in place of array[i][j]
// There is not any maximum-limit on size of arrays
// WAP to take the input for a 1D array and print a 2D array with the same elements by taking number of columns input from the user
#include<stdio.h>
int main()
{
int array[100],columns,i,size;
printf("Enter the total number of elements ");
scanf("%d",&size);
printf("Enter the array elements ");
for(i=0;i<size;i++)
{
    scanf("%d",&array[i]);
}
printf("Enter the number of columns in each row ");
scanf("%d",&columns);
printf("The resultant array is \n");
for(i=0;i<size;i++)
{
    if(i%columns==0)
    {
        printf("\n\n%d  ",array[i]);
    }
    else
    printf("%d  ",array[i]);
}
return 0;
}
// Operations on matrices
// Addition/division/subtraction/modulus : logic ==> result[i][j] = first[i][j] <operation> second[i][j];
// WAP to take input of two matrices and print their sum, division, modulus and subtraction
#include<stdio.h>
void addition(int [][20], int [][20], int, int );
void subtraction(int [][20], int [][20], int, int );
void division(int [][20], int [][20], int, int );
void modulus(int [][20], int [][20], int, int );
int main()
{
int i,j,choice,rowsOne,rowsTwo,columnsOne,columnsTwo,arrayOne[20][20],arrayTwo[20][20];
printf("Enter the number of rows in the first array ");
scanf("%d",&rowsOne);
printf("Enter the number of columns in the first array ");
scanf("%d",&columnsOne);
printf("Enter the array elements ");
for(i=0 ; i<rowsOne  ; i++)
{
    for(j=0 ; j<columnsOne ; j++)
    {
        scanf("%d",&arrayOne[i][j]);
    }
}
printf("Enter the number of rows in the second array ");
scanf("%d",&rowsTwo);
printf("Enter the number of columns in the second array ");
scanf("%d",&columnsTwo);
printf("Enter the array elements ");
for(i=0 ; i<rowsTwo  ; i++)
{
    for(j=0 ; j<columnsTwo ; j++)
    {
        scanf("%d",&arrayTwo[i][j]);
    }
}
printf(" [1] Addition\n [2] Subtraction\n [3] Division\n [4] Modulus\n\nEnter your choice :  ");
scanf("%d",&choice);
switch(choice)
{
    case 1:
    printf("The addition of the two matrices is \n\n");
    addition(arrayOne,arrayTwo,rowsOne,columnsOne);
    break;
    case 2:
    printf("The subtraction of the given two matrices is \n\n");
    subtraction(arrayOne,arrayTwo,rowsOne,columnsOne);
    break;
    case 3:
    printf("The division of the given matrices is \n\n");
    division(arrayOne,arrayTwo,rowsOne,columnsTwo);
    break;
    case 4:
    printf("The modulus of the given matrices is \n\n");
    modulus(arrayOne,arrayTwo,rowsOne,columnsOne);
    break;
}
return 0;
}
void addition(int a1[][20], int a2[][20], int r, int c)
{
    int i,j,result[20][20];
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            result[i][j] = a1[i][j] + a2[i][j] ;
        }
    }
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d  ",result[i][j]);
        }
        printf("\n\n");
    }
}
void division(int a1[][20], int a2[][20], int r, int c)
{
    int i,j,result[20][20];
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            result[i][j] = a1[i][j] / a2[i][j] ;
        }
    }
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d  ",result[i][j]);
        }
        printf("\n\n");
    }
}
void subtraction(int a1[][20], int a2[][20], int r, int c)
{
    int i,j,result[20][20];
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            result[i][j] = a1[i][j] - a2[i][j] ;
        }
    }
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d  ",result[i][j]);
        }
        printf("\n\n");
    }
}
void modulus(int a1[][20], int a2[][20], int r, int c)
{
    int i,j,result[20][20];
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            result[i][j] = a1[i][j] % a2[i][j] ;
        }
    }
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d  ",result[i][j]);
        }
        printf("\n\n");
    }
}