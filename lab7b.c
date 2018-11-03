#include<stdio.h>
#include<omp.h>
int main()
{
    int i,n,votes[100],one=0,two=0,three=0;
    printf("Enter the number of voters (max 100) ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        votes[i]=rand()%3;
    #pragma omp parallel for num_threads(5)
    for(i=0;i<n;i++){
        #pragma omp critical
        {
            if(votes[i]==0)
		one++;
            else if(votes[i]==1)
		two++;
	    else if(votes[i]==2)
		three++;
        }
    }
    printf("\nThe number of votes for one: %d\n",one);
    printf("The number of votes for two: %d\n",two);
    printf("The number of votes for three: %d\n",three);
    if(one>two && one>three)
	printf("One is the winner\n");
    if(two>one && two>three)
	printf("Two is the winnner\n");
    else
	printf("Three is the winner\n");
    return 0;
}
