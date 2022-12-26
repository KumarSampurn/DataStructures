
# ***Implementation Using Adjacency List*** 

## <p align="center"><em>Structure of Graph</em></structurep>
---
~~~c 
typedef struct node
{
    int data;
    struct node* link;
} node;
~~~

- here is a visual representation of the structure  
  

    <img src="images/9.png"  width="60%" >  

    ***data ==> Name of the Vertex  
    link ==> node pointer to next pointer*** 

<br>  

First we Create an array of pointers to structures

```c
node* a[MAX];
```
<img src="images/10.png" width=50%>

Every index now acts like a vertex and we chain the nodes which are connected to the vertex with the index.
___

## <p align="center"><em>ADT OF GRAPHS</em></p>  
---

* Creating a Graph
* Displaying a Graph
* Calulating Indegree
* Calulating Outdegree
* Traversal Methods

___ 
<br>

### <p align ="center">Creating a graph</p>
b

~~~c
void create ( node* a[], int n)
{
    int i , j;
    for(i =0 ; i<n;i++)
    {
        a[i]=NULL;
    }
    while(1)
    {
        printf("Enter the source and destination");
        scanf("%d %d" , &i, &j);
        if(i<0|| j<0|| i>=n || j>=n)
        {
            break;
        }
        insert(a,i,j);
    }
}
~~~

*Understanding the code by breaking it into segments*

- First part  

    ~~~c
        int i , j;
        for(i =0 ; i<n;i++)
        {
            a[i]=NULL;
        }
    ~~~
        The first part of the funciton is setting each array index position as NULL.  
<br>  

- Second part  

    ~~~c
    while(1)
    {
        printf("Enter the source and destination");
        scanf("%d %d" , &i, &j);
        if(i<0|| j<0|| i>=n || j>=n)
        {
            break;
        }
        insert(a,i,j);
    }   
    ~~~
    The second part of the function takes source and destination and if they are valid it calls the insert function with source and destination




#### *Insert function*  

~~~c
void insert (node * a[], int i , int j)
{
    node* temp = (node*)malloc(sizeof(node));
    temp-> data = j;
    temp->link =NULL;

    node* cur = a[i];
    if( cur->link ==NULL)
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
~~~


Lets try to Understand the code by breaking it into segments

- Part 1 : ***Creating a new node***

    ~~~c
    node* temp = (node*)malloc(sizeof(node));
    temp-> data = j;
    temp->link =NULL;
    ~~~
    The above Part creates a node and assign the destination as the value of the node

- Part 2 :  ***Insert at Rear in Singly Linked List***  
    -   Check for empty list  

        ~~~c
        node* cur = a[i];
        if( cur ==NULL)
        {
            a[i]=temp;
            return;
        }
        ~~~

        We check if the if index is pointingto NULL that means the list is emptyso the node we just created willbecome the head of the list.

    - Insert anywhere else

        ~~~c
        while(cur->link!=NULL)
        {
            cur=cur->link;
        }
        cur->link=temp;
        ~~~

        



