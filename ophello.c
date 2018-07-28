#include<stdio.h>
#include<omp.h>
void main()
{
#pragma omp parallel
//The omp parallel directive explicitly instructs the compiler to parallelize the code
{
printf("Greeting\n");
//The code inside the parenthesis is parallelized 
//The code will be printed as many times as the number of cores
}
}

