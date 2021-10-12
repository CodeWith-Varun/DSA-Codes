## Video Link :- [Click Here](https://youtu.be/S5QCJUX2f8s)

```c
#include <stdio.h>

// defining number of vertices and edges for our graph
#define no_of_vertices 8
#define no_of_edges 8

// Initialising an adjacency matrix
int adj_matrix[no_of_vertices + 1][no_of_vertices + 1] = {0};

// initialising an visited array to check whether the node is visited or not
// visited[i] = 0 represents unvisited and visited[i] = 1 represents visited node i
int visited[no_of_vertices + 1] = {0};

void generateAdjMatrix(int edges[][2])
{
	for(int i=0; i<no_of_edges; i++)
	{
		// as this is an undirected graph so we have to change both positions to 1
		// creating a link between edges[i][1] and edges[i][1] in both directions
		adj_matrix[edges[i][0]][edges[i][1]] = 1;
		adj_matrix[edges[i][1]][edges[i][0]] = 1;
	}

	printf("\nAdjacency Matrix for the above set of edges\n");
	for(int i=1; i<=no_of_vertices; i++)
	{
		for(int j=1; j<=no_of_vertices; j++)
		{
			printf("%d ",adj_matrix[i][j]);
		}
		printf("\n");
	}
    printf("\n");
}

void DFS(int vertex)
{
    // making the node visited
    visited[vertex] = 1;

    // printing in the output
    printf("%d ",vertex);

    // checking every node whether that is adjacent or not
    for(int i=1; i<=no_of_vertices; i++) {
        // checking for adjacent condition as well as visited condition
        if(adj_matrix[vertex][i] == 1 && visited[i] == 0) {
            // recursively calling the DFS function for the i node (adjacent node of vertex which is not visited)
            DFS(i);
        }
    }
}

int main()
{
    // set of edges {i, j} represents a edge between node i and j
    int edges[][2] = {{1,2}, {1,3}, {2,4}, {2,5}, {3,6}, {3,7}, {5,8}, {7,8}};
    
    // generating adjacency matrix for above set of edges
    generateAdjMatrix(edges);
    
    // starting the DFS
    DFS(1);

    return 0;
}
```
