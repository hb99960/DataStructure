#include<stdio.h>


void SieveOfEratosthenes(int number)
{
	int a[number];
	int count = 0 ;
	int j;
	int n;
	
	for(int i=0; i<number; i++)
		a[i] = i+1; 

	for(int i=1; i<number; i++)
	{
		
		if(a[i] != 0)
		{
			j = 2;
			while( (a[i]*j) <= number)
			{
				n = (a[i] * j);
				a[n-1] = 0;
				count++;
				j++;
			}
		}
	}

	printf("Total counts = %d\n",count);
	for(int i=1; i<number; i++)
	{	
		if(a[i] != 0)
			printf("%d ",a[i]);
	}
}

int main()
{
	int number;
	printf("Enter the number = ");
	scanf("%d",&number);
	
	SieveOfEratosthenes(number);		
	return 0;
}