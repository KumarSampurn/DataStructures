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




void bfs ( int matrix[][MAX] , int vertex , int n, int visited[])
{
    
    int queue[n];
    int rear = -1 ,front = 0;

    visited[vertex] = 1 ;
    // printf("%d \t");
    queue[++rear] = vertex ;
    
    while ( front <= rear )
    {
        vertex = queue[front++];
        for( int i = 0 ; i< n ; i++)
        {
            if( matrix[vertex][i]==1 )
            {
                if( visited [i] == 0)
                {
                    visited [i] =1 ;
                    // printf(" Vertex %d is visited ", i);
                    // printf("  %d \t ", i);
                    queue[++rear]=i;
                }
            }
        }
    }
}

void dfs ( int matrix [][MAX] , int visited [],int vertex , int n)
{
    visited [vertex] = 1 ;
    // printf("Vertex %d is visited " , vertex);
    // printf(" %d \t" , vertex);

    for ( int i = 0; i < n ; i++)
    {
        if(matrix[vertex][i]==1  && visited [i]==0)
        {
            dfs( matrix, visited , i , n );
        }
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


/** The logic behind this this if you do a DFS / BFS traversal then you access all the
 *  connected components so if the graph is connected it will be the  one connected 
 * component so the visited array of all vertices will be 1 . If you encounter an 
 * element which was not visited then it means that the graph was not a connected
 *  graphs*/