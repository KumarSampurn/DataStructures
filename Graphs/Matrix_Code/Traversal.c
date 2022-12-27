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


void display(graph *adj_matrix)
{
    for(int i=0 ; i< adj_matrix -> n ; i++)
    {
        for( int j =0 ; j< adj_matrix -> n ;j++)
        {
            printf("%d \t", adj_matrix->adj[i][j]);
        }
        printf("\n");
    }
}

void bfs ( int matrix[][MAX] , int vertex , int n)
{
    int visited[MAX]= {0};
    int queue[n];
    int rear = -1 ,front = 0;

    visited[vertex] = 1 ;
    printf("%d \t");
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
                    printf("  %d \t ", i);
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
    printf(" %d \t" , vertex);

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


    while (1)
    {
        printf("\n1. BFS Traversal \n");
        printf("2. DFS Traversal \n");
        printf("3. Display matrix\n");
        printf("4. Exit\n");

        scanf("%d", &choice);        
        switch (choice) 
        {
            case 1: 
                printf("Enter the vertex: ");
                scanf("%d", &vertex);
                
                bfs(adj_matrix.adj,vertex,adj_matrix.n);
                break;
            
            case 2: 
                printf("Enter the vertex: ");
                scanf("%d", &vertex);
                int visited[MAX]={0};
                dfs(adj_matrix.adj,visited,vertex,adj_matrix.n);
                break;
            
            case 3: 
                display(&adj_matrix);
                break;
            
            case 4: 
                return 0;
            case 5:
                printf("Invalid choice\n");
            
        }


    } 

    return 0;
}

