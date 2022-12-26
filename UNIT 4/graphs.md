# Graphs 

> What are Graphs ?

* Graphs are ***non linear*** data data structures
* Which have set of Vertices (node) & edges 
* G = (V, E)
* Graphs can be implemented by :  
    * Adjacency Matrix
    * Linked list 

##  __Types of Graphs__

``` Graphs are of two types : ```  
<br>
### <p align="center">*Undirected graphs*</p>  

    Well you can think of undirected graphs as cities which are connected to each other,  you have a road from CITY A to CITY B ; but you can take the same road to come form CITY B to CITY A .    

![image](images/1.png)

```Here is a representation of The Graphs as Adjacency Matrix```

|  | A | B | C | D | E |
|:-:|---|---|---|---|---|
| A | 0 | 1 | 0 | 0 | 0 |
| B | 1 | 0 | 1 | 1 | 1 |
| C | 0 | 1 | 0 | 1 | 0 |
| D | 0 | 1 | 1 | 0 | 1 |
| E | 0 | 1 | 0 | 1 | 0 |


~~~ 
a[i,j] = {
            1   if ( i -> j)
            0   otherwise
         }


In an adjacency matrix a[i,j] signifies that there is a path from vertex i to vertex j 
~~~



```Here is a representation of The Graphs as Adjacency List or linked list```

![image](images/3.png)

### <p align="center">*Directed graphs*</p>

    Directed Graphs are more like a cliff and a Valley like you come down from the cliff but you cant go up from valley

    Or you can say its One Sided like your feelings for your crush

![image](images/2.png)

```Here is a representation of The Graphs as Adjacency Matrix```

|  | A | B | C | D | E |
|:-:|---|---|---|---|---|
| A | 0 | 1 | 0 | 0 | 0 |
| B | 0 | 0 | 0 | 1 | 0 |
| C | 0 | 1 | 0 | 1 | 0 |
| D | 0 | 0 | 0 | 0 | 1 |
| E | 0 | 0 | 0 | 0 | 0 |

```Here is a representation of The Graphs as Adjacency List or Linked list```

![image](images/4.png)


#### Important Concepts  : 
---

* Adjacency 
    * Two nodes are Adjacent if connected by an edge  

        ![image](images/5.png)

    Here A and B are adjacent to each other

* Successor and Predessor 

    * In Directed Graphs there are successor and predessor  
    ![image](images/6.png)

* Paths 

    * Paths are Basically the road which you can take to reach a specific point
    ![image](images/1.png)

    ```In this figure, if i have to reach D from A``` 

    ```
    A -> B -> C -> D  
    A -> B -> E -> D  
    A -> B -> D  
    ```
    These are the Paths that you can choose.

* Cycle

    * Graphs with atleast 1 are called cyclic graph .
    ![image](images/1.png)

    ```This is a cyclic graph due to B D E ```

* Acyclic 
    
    * Reverse of Cyclic 

        > A directed acyclic graph is called a DAG  

        ![image](images/7.png)

* Connected Components

    * Number of Vertices connected together  

        ![image](images/cc1.png)
        There are 2 Connected Components in this example.

        ![image](images/cc2.png)
        There is 1 Connected Components in this example


* Degree of a Vertex 

    Number of Edeges connected to a vertex .  
    There are two types of Degree.

    * Indegree  
    <br>
    *Indegree of a Vertex* is the ***number of paths leading*** to the ***Vertex***.  

        * Directed Graphs  

            ![image](images/7.png)

            Indegree of B is 2.   
            Indegree of C is 0.  

        * Undirected Graphs  

            ![image](images/1.png)
            Indegree of B is 4.  
            Indegree of C is 2.

    * Outdegree  
    <br>
    *Outdegree of a Vertex* is the ***number of paths leading away*** from the ***Vertex***.  

        * Directed Graphs  

            ![image](images/7.png)

            Outdegree of B is 0.   
            Indegree of C is 2.  

        * Undirected Graphs  

            ![image](images/1.png)
            Outdegree of B is 4.  
            Outdegree of C is 2.

    > Note:  
     **Indegree** and **Outdegree** for a vertex in Undirected graph are equal.


* Traversal Methods 

    * BFS : Breadth First Search  
    Approach :  

        - Push one ( starting ) Vertex in Queue
        - Dequeue a Vertex from the Queue.
        - Visit all adjacent vertices. 
        - If an adjacent vertex is unvisited  , push them into Queue while Visiting them.
        - Now Repeat the last 3 steps until the Queue is not empty.

        Lets take an example to understand this.  
        
        <img src="images/bfs1.png"  width="50%"><img src="images/bfs2.png"  width="50%" ><img src="images/bfs3.png"  width="50%" ><img src="images/bfs4.png"  width="50%" ><img src="images/bfs5.png"  width="50%" ><img src="images/bfs6.png"  width="50%" ><img src="images/bfs7.png"  width="50%" ><img src="images/bfs8.png"  width="50%" ><img src="images/bfs9.png"  width="50%" ><img src="images/bfs10.png"  width="50%"><img src="images/bfs11.png"  width="50%" ><img src="images/bfs12.png"  width="50%" ><img src="images/bfs13.png"  width="50%" ><img src="images/bfs14.png"  width="50%" ><img src="images/bfs15.png"  width="50%" ><img src="images/bfs12.png"  width="50%" >

    * DFS : Depth First Search  
    Approach :  

        - Push one Vertex into Stack
        - Pop a Vertex from the Stack.
        - Visit an adjacent node if it is unvisited push it into the stack. 
        - Now Repeat the above 2 steps until the Stack is not empty.

        Lets take an example to understand this.  
        
        <img src="images/dfs1.png"  width="50%"><img src="images/dfs2.png"  width="50%"><img src="images/dfs3.png"  width="50%"><img src="images/dfs4.png"  width="50%"><img src="images/dfs5.png"  width="50%"><img src="images/dfs6.png"  width="50%"><img src="images/dfs7.png"  width="50%"><img src="images/dfs8.png"  width="50%"><img src="images/dfs9.png"  width="50%"><img src="images/dfs10.png"  width="50%"><img src="images/dfs11.png"  width="50%"><img src="images/dfs12.png"  width="50%"><img src="images/dfs13.png"  width="50%"><img src="images/dfs14.png"  width="50%"><img src="images/dfs15.png"  width="50%"><img src="images/dfs16.png"  width="50%"><img src="images/dfs17.png"  width="50%"><img src="images/dfs18.png"  width="50%"><img src="images/dfs19.png"  width="50%"><img src="images/dfs20.png"  width="50%"><img src="images/dfs21.png"  width="50%"><img src="images/dfs22.png"  width="50%">


    > Note :  
    Whenever you do a **BFS/DFS** Traversal the traversal they are limited to only a connected component that means if there are more than one connected components then you have to **BFS/DFS** for every connected components to get all the elements of the graph.  

<br>  

---
***<p align="center">Thats All for Theory</p>***  

---



