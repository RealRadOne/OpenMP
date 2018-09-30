#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
int pow(int num1,int num2)
{
int final=1;
for(int i=0;i<num2;i++)
{final=final*num1;}
return(final);
}
int main(int argc, char** argv) 
{
  // Initialize the MPI environment
  MPI_Init(&argc,&argv);
  // Find out rank, size
  int rank,size,num,res=0,sum;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  if (rank == 0) 
{
    //Master inputs the number to be checked
    scanf("%d",&num);
    //Master sends the number to the slave thread
    MPI_Send(&num, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
} 
else if (rank == 1) 
{
    MPI_Recv(&num, 1, MPI_INT, 0, 0, MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    printf("Process 1 received number %d from process 0\n", num);
    int flag=0;
    //Checking for prime number
    for(int i=2;i<num;i++)
    {
    if(num%i==0)
    {flag=1;break;}
    }
    if(flag==0)
    {res=1;}
    //Checking for three digit Armstrong number
    {sum=pow((num%10),3)+pow(((num/10)%10),3)+pow((num/100),3);}
    if((sum==num)&&res==1)
    {res=2;}
    else if((sum==num)&&res!=1)
    {res=3;}
    //Sending the result to the next process for printing
    MPI_Send(&res,1,MPI_INT,2,1,MPI_COMM_WORLD);
}
else if(rank==2)
{
   //Receiving the result variable
   MPI_Recv(&res, 1, MPI_INT, 1, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
   printf("Process 2 received %d result from process 0\n",res);
   if(res==1)
   printf("The number is only prime\n");
   else if(res==2)
   printf("The number is both prime and amstrong\n");
   else if(res==3)
   printf("The number is armstrong but not prime\n");
   else
   printf("The number is neither prime nor armstrong\n");
}
  MPI_Finalize();
  return 0;
}
