#include<stdio.h>
#include<malloc.h>

void intialiseGraph(int **graph, int nodes)
{
	int (*p)[nodes] = &graph[0]; // /(*p) is the pointer to 2-d array, points to first 1-D array of graph.  
	int *pint = p;  // pint pointing to one block in 1-d array 
	int choice = 1;
	int node1,node2,weight;
	char ch1;

	for(int i=0; i<nodes; i++)
	{
		for(int j=0; j<nodes; j++)
		{
			*(pint + i*nodes + j) = 0;
		}
	}

	printf("Node1 is connected to Node2\n");
	printf("Press D for Directed Graph and U for undirected graph =");
	scanf(" %c", &ch1);
	
	if( ch1 == 'D')
	{
		do
		{

			printf("Enter node1 node2 weight");
			scanf("%d %d %d", &node1, &node2, &weight);
			if( (node1 < nodes) && (node2 < nodes) )
			{
				*( pint + node1*nodes + node2 ) = weight;	
			}
			else
			{
				printf("Enter nodes carefully!\n");
			}	
			printf("Enter your choice = ");
			scanf("%d", &choice);

		}while(choice);	
	}
	else if( ch1 == 'U' )
	{
		do
		{

			printf("Enter node1 node2 weight");
			scanf("%d %d %d", &node1, &node2, &weight);
			if( (node1 < nodes) && (node2 < nodes) )
			{
				*( pint + node1*nodes + node2 ) = weight;
				*( pint + node2*nodes + node1) = weight;		
			}
			else
			{
				printf("Enter nodes carefully!\n");
			}
			printf("Enter your choice = ");
			scanf("%d", &choice);

		}while(choice);

	}
	else
	{
		printf("Wrong Choice\n");
	}
}

int** createGraphUtil(int nodes)
{
	int **graph = (int**) malloc( nodes * sizeof(int*));
	int row;

	for(row=0; row<nodes; row++)
		graph[row] = (int *) malloc( nodes * sizeof(int));
	return graph;			
}

void printAdjacentNodes(int** graph, int nodes)
{
	int (*p)[nodes] = &graph[0];
	int *pint = p;
	int choice, node1, node2;
	char ch1;
	printf("Press D for Directed Graph and U for undirected graph =");
	scanf(" %c", &ch1);
	if( ch1 == 'D')
	{
		do
		{
			printf("Enter node1");
			scanf("%d",&node1);
			if( node1 < nodes )
			{
				printf("Adjacent nodes are = ");
				for(int i=0; i<nodes; i++)
				{
					if( *(pint + node1*nodes + i) > 0)
					{
						printf("%d ", i);
					}
				}	
			}
			else
			{
				printf("Enter node carefully!\n");
			}
			
			printf("Enter your choice again = ");
			scanf("%d",&choice);

		}while(choice);	
	}
	else if( ch1 == 'U')
	{

		do
		{

			printf("Enter node1");
			scanf("%d",&node1);
			if( node1 < nodes)
			{
				printf("Adjacent nodes are = ");
				for(int i=0; i<nodes; i++)
				{
					if( *(pint + node1*nodes + i) > 0)
					{
						printf("%d ", i);
					}
				}

				for(int i=0; i<nodes; i++)
				{
					if( *(pint + i*nodes + node1) > 0)
					{
						printf("%d ", i);
					}
				}	
			}
			else
			{
				printf("Enter node carefully!\n");
			}			

			printf("Enter your choice again = ");
			scanf("%d",&choice);

		}while(choice);
	}
	
}

void createGraph()
{
	int nodes;
	printf("Enter the number of nodes = ");
	scanf("%d", &nodes);
	int **graph = createGraphUtil(nodes);
	// int (*p)[nodes] = &graph[0];
	// int *pint = p;
	intialiseGraph(graph,nodes);
	printAdjacentNodes(graph,nodes);
}

int main()
{
	int choice;
	printf("Press\n0 to quit\n1 to create a new graph\n");
	scanf("%d", &choice);

	switch(choice)
	{
		case 0:
			break;
		case 1:
			createGraph();
			break;	
		default	:
			printf("Enter correct choice\n");
			break;	
	}
}