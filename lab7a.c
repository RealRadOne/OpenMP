#include<stdio.h>
#include<omp.h>
int main()
{
int n,i;

printf("Enter the number of numbers:");
scanf("%d",&n);
printf("The even numbers are:\n");
omp_set_num_threads(8);
#pragma omp parallel for ordered
for(i=0;i<n;i++)
{
if(i%2==0)
#pragma omp ordered
printf("The thread that prints it is %d.The number is %d\n",omp_get_thread_num(),i);
}

printf("The odd numbers are:\n");
omp_set_num_threads(8);
#pragma omp parallel for ordered

for(i=0;i<n;i++)
{
if(i%2!=0)
#pragma omp ordered
printf("The thread that prints it is %d.The number is %d\n",omp_get_thread_num(),i);
}


}

