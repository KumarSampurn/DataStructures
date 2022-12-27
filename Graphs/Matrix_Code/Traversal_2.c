#include<stdio.h>
int visit[50]={0};
int q[50],f=0,r=-1;
int a[50][50],n;

void create_graph()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
}

void printgraph()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}
void bfs(int v)
{
	visit[v]=1;
	printf("%d \t",v);
	q[++r]=v;
	while(f<=r)
	{
		v=q[f++];
		for(int u=0;u<n;u++)
		{
			if(a[v][u]==1)
			{
				if(visit[u]==0)
				{
					q[++r]=u;
					visit[u]=1;
					printf("%d\t",u);
				}
			}
			
		}
	}
}

void dfs(int v)
{
		visit[v]=1;
		printf("%d is visited\n",v);
		for(int i=0;i<n;i++)
		{
			if(a[v][i]==1 &&visit[i]==0)
				dfs(i);
		}
}
	
int main()
{
	int v;
	printf("Enter the no of vertices\n");
	scanf("%d",&n);
	create_graph();
	printgraph();
	printf("Enter the starting vertex\n");
	scanf("%d",&v);

    printf("BFS traversal\n");
	bfs(v);
    printf("\nDFS traversal\n");
    dfs(v);
}


/** This is an easy way for BFS and DFS , if we make everything global */