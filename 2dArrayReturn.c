#include<stdio.h>
#include<malloc.h>

int ** createArray(int row, int col);
void initialiseArray(int **array, int row, int col);
void printArray(int **array, int row, int col);


void initialiseArray(int **array, int row, int col)
{
	int (*p)[col] = &array[0];
	int *pint = p;

	printf("\nEnter the elements = ");
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			scanf("%d",(pint + i*col + j) );	
		}	
	}

}

void printArray(int **array, int row, int col)
{
	int (*p)[col] = &array[0];
	int *pint = p;
	printf("Elements are = \n");
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			printf("array[%d][%d] = %d\n", i, j, *(pint + i*col +j) );
		}
	}

}

int ** createArray(int row, int col)
{
	int **array = (int **)malloc( row*sizeof(int*) );
	int i;
	for(i = 0; i<col; i++)
	{
		array[i] = (int *)malloc( col*sizeof(int) );
	}
	return array;
}

int main()
{
	int row,col;

	printf("Enter the row and column = ");
	scanf("%d %d", &row, &col);

	int **array = createArray(row,col);
	int (*p)[col] = &array[0];
	int *pint = p;
	initialiseArray(array, row, col);
	printArray(array, row, col);

	return 0;
}
