#include<stdio.h>
#include<omp.h>
void main()
{
omp_set_num_threads(2);
#pragma omp parallel sections
{
#pragma omp section
//The section to compute the addition of two matrices
{
int a[4][4],b[4][4];
for(int i=0;i<4;i++)
for(int j=0;j<4;j++)
{a[i][j]=1;b[i][j]=i*j;}
int sum=0;
for(int i=0;i<4;i++)
{
int sumr=0;
for(int j=0;j<4;j++)
 {
 a[i][j]=a[i][j]+b[i][j];
 }
}
printf("The matrix obtained is\n");
for(int i=0;i<4;i++)
{
 for(int j=0;j<4;j++)
 printf("%d ",a[i][j]);
printf("\n");
}
printf("The thread computing this is %d\n",omp_get_thread_num());
}
#pragma omp section
//The section to compute the multiplication of two matrices
{
int a[4][4],b[4][4];
for(int i=0;i<4;i++)
for(int j=0;j<4;j++)
{a[i][j]=1;b[i][j]=i*j;}
int sum=0;
for(int i=0;i<4;i++)
{
int sumr=0;
for(int j=0;j<4;j++)
 {
 sumr=sumr+(a[i][j]*b[j][i]);
 }
sum=sum+sumr;
//printf("The sum of one iteration is %d\n",sumr);
}
printf("The sum is %d\n",sum);
printf("The thread computing this is %d\n",omp_get_thread_num());
}
}
}
