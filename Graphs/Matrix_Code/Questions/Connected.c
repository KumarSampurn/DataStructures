// WRITE A PROGRAM TO CHECK IF A GRAPH IS CONNECTED OR NOT.
#include <stdio.h>
#define MAX 50

typedef struct graph {
    int n; 
    int adj[MAX][MAX]; 
} graph;

void createGraph(graph *adj_matrix) 
{
    int i, j;

    for ( i = 0; i < adj_matrix->n; i++) 
    {
        for ( j = 0; j < adj_matrix->n; j++) 
        {
            adj_matrix->adj[i][j] = 0;
        }
    }

    while (1) 
    {
        printf("Enter source and destination vertices: ");
        scanf("%d %d", &i, &j);

        if (i < 0 && j <= 0 || i >= adj_matrix->n || j >= adj_matrix->n) 
            break;
        
        adj_matrix->adj[i][j] = 1;
    }
}








int main() 
{

    graph adj_matrix;
    int choice, vertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &adj_matrix.n);
    createGraph(&adj_matrix);

    int visited[MAX]={0};
    
    
    // bfs(adj_matrix.adj,0,adj_matrix.n,visited);

    dfs(adj_matrix.adj ,visited ,0 ,adj_matrix.n);
    
    for (int i = 0; i < adj_matrix.n; i++)
    {
       if(visited[i]==0)
       {
           printf("Not Connected");
           return 0;
       }
    }
    printf("Connected Graph");       
    return 0;
}

//Approach : Read BFS/ DFS Traversals