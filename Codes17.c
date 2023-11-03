/*
Multiplication of matrices : no of columns of the first natrix should be equal to the no of rows of the second matrix

while(c1 != r2)
printf("Error");

three nested loops :  (a)  for each row,
                          (b)  each column
                              (c)  computing elements of that column

main code :
// multiplying

for(i=o;i<r1;i++)
{
    for(j=0;j<c2;j++)
    {
        for(k=0;k<c1;k++)
        {
            result[i][j] += a[i][k] + b[k][j] ;
        }
    }
}
// displaying the result

for(i=0;i<r1;i++)
{
    for(j=0;j<c2;j++)
    {
        printf("%d ",result[i][j]);
    }
}
*/
#include<stdio.h>
int main()
{
int i,j,k,a[2][2] = {{1, 2}, {3, 4}},b[2][2] = {{5, 6}, {7, 8}},result[2][2];

for(i=0;i<2;i++)
{
    for(j=0;j<2;j++)
    {
        for(k=0;k<2;k++)
        {
            result[i][j] += a[i][k] * b[k][j] ;
        }
    }
}

printf("The result matrix of multiplication of these two matrices is :\n\n");

for(i=0;i<2;i++)
{
    for(j=0;j<2;j++)
    {
        printf("%d  ",result[i][j]);
    }
    printf("\n\n");
}

return 0;
}
// WAP to take input of two matrices and print their multiplication result
#include<stdio.h>
int main()
{
int a[5][5],b[5][5],result[5][5],i,j,k,r1,c1,r2,c2;
printf("Enter the number of rows and columns in the first matrix ");
scanf("%d %d",&r1,&c1);
printf("Enter the elements ");
for(i=0;i<r1;i++)
{
    for(j=0;j<c1;j++)
    {
        scanf("%d",&a[i][j]);
    }
}
printf("Enter the number of rows and columns in the second matrix ");
scanf("%d %d",&r2,&c2);
printf("Enter the elements ");
for(i=0;i<r2;i++)
{
    for(j=0;j<c2;j++)
    {
        scanf("%d",&b[i][j]);
    }
}
if(c1 != r2)
printf("Error !!");
for(i=0; i<r1; i++)
{
for(j=0; j<c2; j++)
    {
        result[i][j] = 0;
    }
}
for(i=0;i<r1;i++)
{
    for(j=0;j<c2;j++)
    {
        for(k=0;k<c1;k++)
        {
            result[i][j] += (a[i][k] * b[k][j]);
        }
    }
}
printf("The result of multiplication of the matrices is :\n\n");
for(i=0;i<r1;i++)
{
    for(j=0;j<c2;j++)
    {
        printf("%d  ",result[i][j]);
    }
    printf("\n\n");
}
return 0;
}
// Second code for the same program
#include <stdio.h>
int main()
{
int a[10][10], b[10][10], result[10][10], r1, c1, r2, c2, i, j, k;
printf("Enter rows and column for first matrix: ");
scanf("%d %d", &r1, &c1);
printf("Enter rows and column for second matrix: ");
scanf("%d %d",&r2, &c2);
while (c1 != r2)
{
printf("Error! No. of columns of first matrix not equal to no.of row of second.\n\n");
printf("Enter rows and column for first matrix: ");
scanf("%d %d", &r1, &c1);
printf("Enter rows and column for second matrix: ");
scanf("%d %d",&r2, &c2);
}
printf("\nEnter elements of matrix 1:\n");
for(i=0; i<r1; i++)
{
    for(j=0; j<c1; j++)
    {
        printf("Enter elements a%d%d: ",i,j);
        scanf("%d", &a[i][j]);
    }
}
printf("\nEnter elements of matrix 2:\n");
for(i=0; i<r2; i++)
{
    for(j=0; j<c2; j++)
    {
        printf("Enter elements b%d%d: ",i, j);
        scanf("%d",&b[i][j]);
    }
}
for(i=0; i<r1; i++)
{
    for(j=0; j<c2; j++)
        {
            result[i][j] = 0;
        }
}
for(i=0; i<r1; i++)
{
    for(j=0; j<c2; j++)
    {
        for(k=0; k<c1; k++)
        {
            result[i][j]+=a[i][k]*b[k][j];
        }
    }
}
printf("\nOutput Matrix:\n");
for(i=0; i<r1; i++)
{
    for(j=0; j<c2; j++)
    {
        printf("%d  ", result[i][j]);
    }
    printf("\n\n\n");
}
return 0;
}
// WAP to print the transpose of any matrix
#include <stdio.h>
int main()
{
int a[10][10], transpose[10][10], r, c, i, j;
printf("Enter rows and columns of matrix: ");
scanf("%d %d", &r, &c);
// Storing elements of the matrix
printf("\nEnter elements of matrix:\n");
for(i=0; i<r; i++)
{
    for(j=0; j<c; j++)
    {
        printf("Enter element a%d%d: ",i, j);
        scanf("%d", &a[i][j]);
    }
}
// Displaying the matrix a[][] */
printf("\nEntered Matrix: \n");
for(i=0; i<r; i++)
{
    for(j=0; j<c; j++)
    {
        printf("%d  ", a[i][j]);
    }
    printf("\n\n");
}
// Finding the transpose of matrix a
for(i=0; i<r; i++)
{
    for(j=0; j<c; j++)
    {
        transpose[i][j] = a[j][i];
    }
}
// Displaying the transpose of matrix a
printf("\nTranspose of Matrix is :\n");
for(i=0; i<r; i++)
{
    for(j=0; j<c; j++)
    {
        printf("%d  ",transpose[i][j]);
    }
    printf("\n\n");
}
return 0;
}