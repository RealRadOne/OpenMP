#include <stdio.h>
#include <mpi.h>

int main (int argc, char *argv[])
{
    int rank, comm_size,nproc;
    int sum,startval,endval,accum;
    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &nproc);
    double start=MPI_Wtime();
    sum = 0;
    startval = 100*rank/nproc+1;
    endval =   100*(rank+1)/nproc;
   for(int i=startval;i<=endval;++i)
     sum = sum + i;
   printf("I am the node %d",rank); 
   printf("\n the partial sum is:%d\n",sum); 
   if(rank!=0) //the slaves sending back the partial sums
   MPI_Send(&sum,1,MPI_INT,0,1,MPI_COMM_WORLD);
   else //id==0! the master recieves the partial sums
   for(int j=1;j<nproc;j=j+1)
   {
      MPI_Recv(&accum, 1, MPI_INT, j, 1, MPI_COMM_WORLD, &status);
      sum = sum + accum;
      printf("the sum yet is %d\n",sum);
    }
  if(rank == 0)
    printf("the sum from 1 to 100 is:%d\n",sum);
  
  MPI_Finalize();
}
