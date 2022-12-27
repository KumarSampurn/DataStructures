#include<stdio.h>
#include<stdlib.h>
#define MAX 50

typedef struct node
{
	int data;
	struct node* link;
}node;
node *array[MAX];

void insert(node *a[],int i,int j)
{
	node *temp=malloc(sizeof(node));
	temp->data=j;
	temp->link=NULL;

	node *cur=a[i];

	if(cur==NULL)
	{
		a[i]=temp;
		return;
	}

	while(cur->link!=NULL)
	{
		cur=cur->link;
	}
	cur->link=temp;
}
void createGraph(node *array[],int n)
{
	int i,j;
    
	for( i=0 ;i<n ;i++)
    {
		array[i]=NULL;
    }
	while(1)
	{
		printf("Enter the source and destinationn");
		scanf("%d%d",&i,&j);
		if(i<0||j<0||i>=n||j>=n)
		    break;
		insert(array,i,j);
	}
}
void display(node *array[] , int n)
{
	for(int i=0;i<n;i++)
	{
		node *cur=array[i];
		printf("%d->",i);
		while(cur!=NULL)
		{
			printf("--> %d ",cur->data);
			cur=cur->link;
		}
		printf("\n");
	}
}
node *insertRear(int vertex,node *queue)
{
	node *temp=malloc(sizeof(node));
	temp->data=vertex;
	temp->link=NULL;

	if(queue==NULL)
	{
		queue=temp;
		return(queue);
	}

	node *cur=queue;
	while(cur!=NULL)
	{
		cur=cur->link;
	}
	cur=temp;
	return(queue);
}
node *deleteFront(node *queue)
{
	if (queue==NULL)
    {
        return NULL;
    }
    
	node* second = queue ->link;
    free(queue);
    return second;

    // return queue->link
}

void bfs(node *array[], int n , int vertex)
{

	int visited[MAX]={0};
    node *queue =NULL , *current;

    visited[vertex]=1;
    queue = insertRear(queue, vertex);

    while(queue != NULL)
    {
        vertex = queue->data;
        queue = deleteFront(queue);
        current= array[vertex];

        while(current!=NULL)
        {
            if(visited[current->data]==0)
            {
                visited[current->data]=1;
                printf("%d vertex is visited \t", current->data);
                queue=insertrear(queue,queue->data);
            }
            current=current->link;
        }
    }
}

void dfs(node* array[] , int visited[] , int vertex)
{
    visited[vertex]=1;
    printf("%d vertex is visited ", vertex);

    node* cur=array[vertex];
    while( cur!= NULL)
    {
        if(visited[cur->data]==0)
        {
            dfs(array , visited , cur->data);
            cur=cur->link;
        }
    }
}


int main()
{
	int n, vertex,choice;

    printf("Enter the number of vertices\n");
	scanf("%d",&n);
	createGraph(array,n);

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
                printf("enter the starting vertex\n");
	            scanf("%d",&vertex);
	            bfs(array,n,vertex);
                break;
            
            case 2: 
                printf("enter the starting vertex\n");
	            scanf("%d",&vertex);
				int visited[MAX]={0};
	            dfs(array,visited,vertex);
                
                break;
            
            case 3: 
	            display(array,n);
                break;
            
            case 4: 
                return 0;
            case 5:
                printf("Invalid choice\n");      
        }
    } 
    return 0;
}