#include<stdio.h>

int verifyMatrix(int *a, int n)
{
	int value = 1;
	int flag = 0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if( *(a + i*n + j) != value++)
			{
				flag  = 1;
			}
		}
	}
	if(flag)
		return 0;
	return 1;
}

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void shuffle(int *a, int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			swap( (a + i*n + j), (a + j*n + i) );	
		}
	}
}

void printMatrix(int *a, int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			int value = *( a + i*n + j);
			printf("%d ",value);
		}
		printf("\n");
	}
}

void up(int *a, int n, int *i, int *j)
{
	int x = *j;
	int y = *i;
	if( y-1 >=0 )
	{
		swap( (a + x + y*n), (a + x + (y-1)*n) );
		*i = y-1;
	}	
}

void down(int *a, int n, int *i, int *j)
{
	int x = *j;
	int y = *i;
	if( y+1 < n)
	{
		swap( (a + x + y*n), (a + x + (y+1)*n) );
		*i = y+1;
	}
}

void left(int *a, int n, int *i, int *j)
{
	int x = *j;
	int y = *i;
	if( x-1 >= 0)
	{
		swap( (a + x + y*n), (a + x-1 + y*n) );
		*j = x-1;
	}
}

void right(int *a, int n, int *i, int *j)
{
	int x = *j;
	int y = *i;
	if( x+1 <n)
	{
		swap( (a + x + y*n), (a + x+1 +y*n) );
		*j = x+1;
	}
}

void clrscr()
{
    system("@cls||clear");
}

int main()
{
	int n;
	printf("Enter the size of matrix = ");
	scanf("%d",&n);

	int flag = 0;
	int arr[n][n];
	int number = 1;
	int choice;
	int iIndex = n-1;
	int jIndex = n-1;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			arr[i][j] = number++;
		}
	}
	arr[n-1][n-1] = -1;
	shuffle(arr,n);
	printMatrix(arr,n);
	printf("Solve the puzzle.");
	printf("Controls:\n8 - up\n2 - down\n4 - left\n6 - right\n0 - quit\n");
	scanf("%d", &choice);
	while( !verifyMatrix(arr,n) )
	{
		switch(choice)
		{
			case 0:
				flag = 1;
				break;
			case 8:
				up(arr, n, &iIndex, &jIndex);
				break;
			case 2:
				down(arr, n, &iIndex, &jIndex);
				break;
			case 4:
				left(arr, n, &iIndex, &jIndex);
				break;
			case 6:
				right(arr, n, &iIndex, &jIndex);
				break;			
		}
		clrscr();
		printMatrix(arr,n);
		if(flag)
			return;
		scanf("%d",&choice);	
	}
}