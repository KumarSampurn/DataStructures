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
int indegree(node *array[],int n,int vertex)
{
    node* cur=NULL;
	int count=0;
	for(int i=0;i<n;i++)
	{
		node *cur=array[i];
		while(cur!=NULL)
		{
			if(cur->data==vertex)
			{
				count++;
			}
			cur=cur->link;
		}
	}
	return(count);
}
int outdegree(node *array[],int vertex)
{
	node *cur=array[vertex];
	int length=0;
	while(cur!=NULL)
	{
        length++;
		cur=cur->link;
	}
	return(length);
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
                printf("Enter the vertex\n");
	            scanf("%d",&vertex);
	            int Incount=indegree(array,n,vertex);
	            printf("indegree count=%d \n",Incount);
                break;
            
            case 2: 
                printf("Enter the vertex\n");
	            scanf("%d",&vertex);
	            int Outcount=outdegree(array,vertex);
	            printf("outdegree count=%d \n",Outcount);
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