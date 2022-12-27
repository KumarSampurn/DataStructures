
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
<br>

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
    if( cur ==NULL)
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
~~~c 
    void insert( node* a[] , int i , int j )
~~~
The function takes the following argument :
- node* [ ]  : An Array of pointers where every index is a vertex 
- int i : source index 
- int j : destination index


Lets try to Understand the code by breaking it into segments

- Part 1 : ***Creating a new node***

    ~~~c
    node* temp = (node*)malloc(sizeof(node));
    temp-> data = j;
    temp->link =NULL;
    ~~~
    This Part creates a node and assign the destination as the value of the node.

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

        
___ 
<br>  

### <p align ="center">Displaying a graph</p>  

<br>

~~~c
void display( node * array[] , int n)
{
    for ( int i = 0 ; i < n ; i++)
    {
        node* cur = array[i];
        printf("%d\t", i);
        while( cur ! = NULL)
        {
            printf("--> %d " , cur->data);
            cur=cur->link; 
        }
        printf("\n");
    }
}
~~~

Displaying the contents of the graph is similar to displaying the contents of the linked list for n iterations.


___  
<br>  

### <p align ="center">Calculating **Indegree**</p>  
<br>  

*Indegree of a Vertex* is the ***number of paths leading*** to the ***Vertex***.

~~~c
int indegree( node * array[] , int n ; int vertex)
{
    node* cur =NULL;
    int count = 0;
    for ( int i = 0; i< n ; i++)
    {
        node * cur= array[i];
        while( cur != NULL)
        {
            if( cur->data == vertex)
                count++;

            cur= cur->link;
        }
    }
    return count;
}
~~~
The logic behind calculating indegree is counting number of occurence of vertex in the lists of each index of array .

That is what we are trying to do :
- First we take a loop a for all the vertices 
- We then traverse the list of every index and check if ***cur->data == vertex*** if thats true we increment the count by 1.

<br>  

___  

### <p align ="center">Calculating **Outdegree**</p>


*Outdegree of a Vertex* is the ***number of paths leading away*** from the ***Vertex***.

~~~c
int outdegree ( node* array[] , int n , int vertex)
{
    node* cur = array[vertex];
    int length = 0;

    while( cur!=NULL)
    {
        length++;
        cur= cur-> link;
    }
    return length;
}
~~~

Since we add only those element in the list which can be accessed from a vertex directly therefore the length of the list will tell us the Outdegree of the vertex.  


___ 

<br>  

### <p align ="center">**Traversal Methods**</p>
### <p align ="center">*BFS: BREADTH FIRST SEARCH*</p>

* Pre -requisites :  
    - How Queues works,   
    - How BFS works, 


* BFS ALGOTRITHM  
    * Select a Starting vertex for BFS and enqueue it to the queue.
    * Visit *all Adjacent vertices*.
    * if any of the adjacent vertex *is unvisited* *make it visited* then *enqueue it to the queue*. 
    * While the *queue is not empty* dequeue a element from the queue and *repeat the above two statements* with dequeued element at starting vertex.

~~~c
void bfs (node *array[] ,int n , int vertex)
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
                queue=insertRear(queue,list->data);
            }
            current=current->link;
        }
    }
}
~~~
Lets Understand the code:     
~~~c
void bfs( node* array[] , int n , int vertex)
~~~

The Function takes three arguments :  
* node* array [ ] : An Array of pointers where every index is a vertex 
* int n : number of vertices 
* int vertex : The vertex to start the BFS from.

~~~c
int visited[MAX]={0};
node *queue =NULL , *current;
~~~
Declaring a Visited array , a queue.

~~~c
visited[vertex]=1;
queue = insertRear(queue, vertex);
~~~
Visiting the Vertex and Enqueing it into the queue.

~~~c
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
                queue=insertRear(queue,list->data);
            }
            current=current->link;
        }
    }
~~~
Lets try to understand this snippet:  
* While the queue is not empty
* We are Dequeing an vertex from the Queue
* Traversing the vertex's list and if the new vertex in list is not visited we are enqueing it to the queue and printing it . 





```Helper Functions```
~~~c
node* insertRear(node* queue , int element)
{
    // Creating a new node
    node* temp = (node*)malloc(sizeof(node));
    temp->data = element;
    temp->link = NULL;

    // if queue is empty 
    if(queue==NULL)
    {
        list = temp;
        return queue;
        // return temp; avoid above lines by returning temp
    }

    // Insert at end 
    node* cur= queue;
    while(cur->link !=NULL)
    {
        cur=cur->link;
    }
    cur->link = temp;
    return queue;

}

node* deleteFront( node*  queue  )
{
    // if queue is empty
    if( queue ==NULL)
        return NULL;

    // returning the second node and freeing the first one.
    node* second = queue ->link;
    free(queue);
    return second;

    // return queue->link; improper way of proceding without freeing but works. So a man has to do what he has to do.
}
~~~
___

### <p align ="center">*DFS: DEPTH FIRST SEARCH*</p>

* Pre -requisites :  
    - How Recursion works especially **Backtracking** in Recursion,  
    - How DFS works, 

* DFS ALGOTRITHM  
    * We will be using system stack for this.
    * Select a Starting vertex for DFS and make it visited.
    * Visit *all Adjacent vertices*.
    * If any of the adjacent vertex *is unvisited  start DFS for the vertex* .
    * If the loop is over start Backtracking.

~~~c
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
~~~
Lets Try to understand the code:  

~~~c
void dfs( node* array[] , int visited[] , int vertex )
~~~
The **DFS** takes three arguments:

* node* array [  ] : An Array of pointers where every index is a vertex 
* int visited [ ] : An visited Array to keep track which all elements have been visited so far.
* int vertex : The vertex to start the DFS from. 


~~~c
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
~~~

* Visiting a vertex marking it as visited.
* traversing the list of the vertex and if the element in the list in not visited 
* startimg the DFS for the element.  

* Dry Run once to Understand how Backtracking works.

___
## <p align ="center">***Thats all for Theory***</p>
___

> **P.S.**  
*In actual coding the function prototypes may change but the concepts will be same.*