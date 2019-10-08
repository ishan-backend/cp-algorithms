#include<bits/stdc++.h>
using namespace std;

class Edge
{
public:
	int source;
	int dest;
	int weight;
};

bool compare(Edge e1, Edge e2)
{
	// to compare Edge objects in inbuilt sort function
	// so create bool compare where you compare two objects of Edge class and 
	// compare them on basis of weights in "ascending order"
	return e1.weight < e2.weight;
	
}

int findParent(int v, int* parent)
{
	if(parent[v] == v)
		return 1;

	//Recursive call
	return findParent(parent[v], parent);
}

void kruskals(Edge* input, int n, int E)
{
	// Sort the input array - ascending order based on weights
	// since input array is of type Edge, which has 3 properties
	// we need to decide to sort the input array based on weight property

	sort(input, input+E, compare);

	int* parent = new int[n];
	for(int i=0; i<n; i++)
	{
		//initialise each node's parent as self
		parents[i] = i;
	}

	// making OUTPUT - OUR MINM SPANNING TREE
	Edge* output = new Edge[n-1];

	int count = 0;	// currently how many edges are added to mst
	int i = 0;	//currently working on which edge

	while(count != n-1)
	{
		Edge currentEdge = input[i];

		//Check if we can add current edge to MST or not.
		// i.e. figure out parent of both( source and dest.) of current edge
		int sourceParent = findParent(currentEdge.source, parent);
		int destParent = findParent(currentEdge.dest, parent);

		if(sourceParent != destParent)
		{
			output[count] = currentEdge;
			count++;
			parent[sourceParent] = destParent;
		}
		i++;
	}


	// cout minimum spanning tree
	for(int i=0; i<n-1; i++)
	{
		if(output[i].source < output[i].dest)
		{
			cout<< output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
		}
		else
		{
			cout<< output[i].dest<<" "<<output[i].source<<" "<<output[i].weight<<endl;
		}
	}

}

signed main()
{

	// n- no of vertices, E- no of edges
	int n, E;
	cin>>n>>E;
	// input is a pointer to array of objects of class Edge
	Edge* input = new Edge[E];

	// Input weighted graph
	for(int i=0; i<E; i++)
	{
		int s, d, w;
		cin>>s>>d>>w;
		// input[i] represents one onject of class Edge
		input[i].source = s;
		input[i].dest = d;
		input[i].weight = w;	
	}

	kruskals(Edge, n, E);


	return 0;
}

/*
 INPUT:
 6 11
 0 1 2
 1 3 1
 0 2 4
 2 4 9
 4 5 5
 3 5 7
 4 3 11
 2 5 10
 0 3 3
 2 1 8
 2 3 6

 output:
 */

