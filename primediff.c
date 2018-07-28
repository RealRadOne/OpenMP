//Finding maximum gap between prime numbers from 1-5000 using omp parallel for
#include<stdio.h>
#include<omp.h>
int main()
{
#pragma omp parallel
{
int temp=2,i,max=-1,j;
#pragma omp parallel for
//Work sharing construct
for(i=3;i<5000;i++)
{
int flag=0,tempr;
for(j=2;j<i;j++)
{
if(i%j==0&&j!=i)
{flag=1;break;}
}
if(flag==0)
{tempr=i-temp;temp=i;}
if(tempr>max)
max=tempr;
}
printf
("The max difference is %d.Printed by the thread %d\n",max,omp_get_thread_num());
}
}



