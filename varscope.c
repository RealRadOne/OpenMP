#include<stdio.h>
#include<omp.h>
int main()
{
	int i=10,a=5;
        //The above variables are shared
        omp_set_num_threads(5);
        //BY default the number of threads created=the number of CPU cores
        #pragma omp parallel
	{
		int i=5,b=10;
                //The above variables are local to the threads forked by master thread
		printf("Check scope of i %d\n",i++);
                printf("A local variable %d\n",a++);           
	}
	printf("Check scope of i %d\n",i++);
}
