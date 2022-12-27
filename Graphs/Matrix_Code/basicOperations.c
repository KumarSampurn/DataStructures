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

int indegree(graph *adj_matrix, int vertex) 
{
    int count = 0;
    for (int i = 0; i < adj_matrix->n; i++) 
    {
        if (adj_matrix->adj[i][vertex] == 1) 
            count++;
    }
    return count;
}

int outdegree(graph *adj_matrix , int vertex)
{
    int count =0 ;
    for(int i =0; i< adj_matrix->n;i++)
    {
        if(adj_matrix ->adj[vertex][i]==1)
        {
            count++;
        }
    }
    return count;
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

int main() 
{

    graph adj_mat;
    int choice, vertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &adj_mat.n);
    createGraph(&adj_mat);


    while (1)
    {
        printf("\n1. Indegree of a vertex\n");
        printf("2. Outdegree of a vertex\n");
        printf("3. Display matrix\n");
        printf("4. Exit\n");

        scanf("%d", &choice);        
        switch (choice) 
        {
            case 1: 
                printf("Enter the vertex: ");
                scanf("%d", &vertex);
                int Indegree = indegree(&adj_mat, vertex);
                printf("\nIndegree of %d is %d\n", vertex, Indegree);
                break;
            
            case 2: 
                printf("Enter the vertex: ");
                scanf("%d", &vertex);
                int Outdegree = outdegree(&adj_mat, vertex);
                printf("\nOutdegree of %d is %d\n", vertex, Outdegree);
                break;
            
            case 3: 
                display(&adj_mat);
                break;
            
            case 4: 
                return 0;
            case 5:
                printf("Invalid choice\n");
            
        }


    } 

    return 0;
}

