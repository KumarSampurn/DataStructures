//Write a Program to Check if a cycle existing in a Graphs or not

#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int a[MAX][MAX],n,p=0;

void createGraph()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
}

int main()
{
	int i,source,destination;
	printf("enter the number of nodes\n");
	scanf("%d",&n);
	printf("enter the adjacency list\n");
	createGraph();
	
    return 0;
}









/** Make source and Destination same and do this for all vertices in a loop
 * whenever source == Destination make flag =1 and come out of loop .
 * If outside the loop flag =1 then cycle exist otherwise not
 * Understand Concept no need to follow boiler plate.
*/

