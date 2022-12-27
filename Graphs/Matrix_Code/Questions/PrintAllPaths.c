// Write A program to print all paths from source to destination
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int a[MAX][MAX],n,p=0;

void createGraph()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
}


void printall(int source,int destination,int visited[MAX],int path[MAX])
{
	// Fill this code
}
	
void printpath(int source,int destination)
{
	//Fill this code
}

			
int main()
{
	int i,source,destination;
	printf("enter the number of nodes\n");
	scanf("%d",&n);
	printf("enter the adjacency list\n");
	createGraph();
	printf("enter the source and destination\n");
	scanf("%d%d",&source,&destination);
	printpath(source,destination);
    return 0;
}

/** Approach :
 * Start A traversal and keep pushing  vertices into stack 
 * When Vertex == Destination pop all elemnts from stack 
 * Understand Concept no need to follow boiler plate.
 */