#include<bits/stdc++.h>
#include<unordered_set>
#include<vector>
#define pb push_back

using namespace std;

void dfs(vector<int>* edges, int start, unordered_set<int>* component, bool* visited)
{
	visited[start] = true;
	component->insert(start);

	//Note: vector<pointer> ke array me ->size() use krte hain
	// in vectors just use .size()
	for(int i=0; i<edges[start].size(); i++)
	{
		int next = edges[start][i];
		if(!visited[next])
		{
			dfs(edges, next, component, visited);
		}
	}
}

unordered_set<unordered_set<int>*>* getComponents(vector<int>* edges, int n)
{
	bool* visited = new bool[n];
	//to mark all vertices initially as unvisited
	for(int i=0; i<n; i++)
	{
		visited[i]=false;
	}


	// to store final set of components, lets create output
	unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();


	for(int i=0; i<n; i++)
	{
		// if any node is unvisited, call dfs on it
		if(!visited[i])
		{
			//to store each connected compoenent we find out via dfs
			unordered_set<int>* component = new unordered_set<int>();

			// parameters:
			// edges - as complete graph, adj list
			// i - starting vertex of dfs, dfs decides direction of traversal using adj.list
			// visited - while doing dfs only traverse the unvisited nodes
			// component -  in which to store complete vertices traversed in one dfs
			dfs(edges, i, component, visited);

			// now component will carry one complete component
			// store it in output.
			output->insert(component);
		}
	}
	delete[] visited;
	return output;
}

signed main()
{
	//n vetices- 1 to n indexed 0 to n-1 in vector
	int n;
	cin>>n;
	//adjacency list - edges
	vector<int>* edges = new vector<int>[n];
	int m;
	cin>>m;
	for(int i=0; i<m; i++)
	{
		int j, k;
		cin>>j>>k;
		// edge between 1 to 3 is stored as 0 to 2 and 2 to 0 in adj list.
		edges[j-1].pb(k-1);
		edges[k-1].pb(j-1);
	}

	//components is pointer to set of many connected components.
	//in set, each value is a pointer to one of the connected components set
	unordered_set<unordered_set<int>*>* components = getComponents(edges, n);

	//printing all connected components
	unordered_set<unordered_set<int>*>::iterator it1 = components->begin();
	while(it1 != components->end())
	{
		unordered_set<int>* component = *it1;	//current component
		// since current compo is a set, iterate over all his elements 
		// it2 is iterator to set of all vertices in curr component
		unordered_set<int>::iterator it2 = component->begin();
		while(it2!=component->end())
		{
			cout<<*it2 + 1<<" ";
			it2++;
		}

		cout<<endl;
		delete component;	//deleting current component(set) which is already printed
		it1++;
	}
	delete components;	//deleting set of all connected components, as they'r printed already
	delete [] edges;
	return 0;
}

/*INPUT:
6 - vertices
5 - edges
1 2
1 4
2 3
3 4
5 6
OUTPUT:
5 6
4 3 2 1
*/
