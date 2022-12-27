/*dfs matrix*/
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
	visited[source]=1;
	path[p]=source;
	p++;
	if(source==destination)
	{
			
		for(int i=0;i<p;i++)
		{
			printf("%d ",path[i]);
		}
		printf("\n");
	}
	else{
		for(int i=0;i<n;i++)
			if(a[source][i]==1 && visited[i]==0)
			{
				printall(i,destination,visited,path);
			}
	}
	p--;
	visited[source]=0;
}
	
void printpath(int source,int destination)
{
	int visited[MAX];
	int path[MAX];
	int p=0;
	for(int i=0;i<n;i++)
		visited[i]=0;
	printall(source,destination,visited,path);
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
}