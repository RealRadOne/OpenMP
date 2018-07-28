#include <stdio.h>
#include <omp.h>
void main()
{
     omp_set_num_threads(5);
    //The below function sets the number of threads for the parallel program to be 5
     #pragma omp parallel
    //The code in the paranthesis will be parallelized
    {
    printf("The number of threads working on this is %d\n",omp_get_num_threads());
    //This function gets the number of threads working on the program
    printf("The ID number of thread working is %d\n",omp_get_thread_num());
    //This function gets the id of the thread working rn
    printf("The number of processes running are %d\n",omp_get_num_procs());
    //Gets the number of processes running concurrently
    printf("The max number of threads that can perform the operations are %d\n",omp_get_max_threads());
    //Function to get the max threads
    }
}
