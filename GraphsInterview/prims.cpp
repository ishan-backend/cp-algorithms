#include<bits/stdc++.h>
using namespace std;

int findMinVertex(int* weights, bool* visited, int n)
{
	/* This function chooses next minVertex to visit while making minm spanning tree*/

	int minVertex=-1;

	//going to each vertex
	for(int i=0; i<n; i++)
	{
		// minVertex needs to be unvisited.
		// if minVertex = -1 i.e.BASE CASE current node is choosen as minVertex
		// else if weight of current node <  weight of chosen minVertex till now, update minVertex to current node
		if(!visited[i] && (minVertex == -1 || weights[i] < weights[minVertex]))
		{
			minVertex = i;
		}
	}
	return minVertex;
}

void prims(int **edges, int n)
{
	int* parent = new int[n];
	int* weights = new int[n];
	bool* visited = new bool[n];

	for(int i=0; i<n; i++)
	{
		visited[i] = false;
		weights[i] = INT_MAX;
	}
	parent[0]=-1;
	weights[0]=0;

	for(int i=0; i < n-1; i++)	//n-1 instead of n, because when last vertex is explored, no unvisited neighbours are left
	{
		//Find min Vertex
		int minVertex = findMinVertex(weights, visited, n);
		// we have visited minVertex, so mark it visited
		visited[minVertex] = true;
		//Explore un visited neighbours
		for(int j=0; j<n; j++)
		{
			//If edge exists between minVertex and any node - that node is neighbour
			//explore that neighbour only if its unvisited
			if(edges[minVertex][j]!=0 && !visited[j])
			{
				if(edges[minVertex][j] < weights[j])
				{
					weights[j] = edges[minVertex][j];
					parent[j] = minVertex;
				}
			}
		}

	}

	// now printing Minimum Spanning Tree(MST) in format:
	// from to weight
	for(int i=1; i<n; i++)
	{
		if(parent[i] < i)
		{
			cout << parent[i] << " " << i << " " << weights[i] << endl;
		}
		else
		{
			cout << i << " " << parent[i] << " " << weights[i] << endl;
		}
	}

}

signed main()
{
	// n - total no. of vertices
	// e - total no. of edges
	int n;
	int e;   
	cin>>n>>e;
	int** edges = new int*[n];
	for(int i=0; i<n; i++)
	{
		edges[i] = new int[n];
		for(int j=0; j<n; j++)
		{
			edges[i][j]=0;
		}
	}
	for(int i=0; i<e; i++)
	{
		int f, s, weight;
		cin>>f>>s>>weight;
		edges[f][s]=weight;
		edges[s][f]=weight;
	}
	cout<<endl;

	prims(edges, n); 

	for(int i=0; i<n; i++)
	{
		delete[] edges[i];
	}
	delete[] edges;

	return 0;
}


/*
INPUT:
5 7
0 1 4 
0 2 8
1 3 6
1 2 2
2 3 3
2 4 9
3 4 5

OUTPUT:

0 1 4
1 2 2
2 3 3
3 4 5
*/
