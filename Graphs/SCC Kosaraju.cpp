#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;

void dfs(vector<int>* edges, int start, unordered_set<int> &visited, stack<int> &finishStack) 
{
	visited.insert(start);

	for (int i = 0; i < edges[start].size(); i++) 
	{
		int adjacent = edges[start][i];
		if (visited.count(adjacent) == 0) 
		{
			dfs(edges, adjacent, visited, finishStack);
		}
	}
	finishStack.push(start);
}

void dfs2(vector<int>* edges, int start, unordered_set<int>* component, unordered_set<int> & visited) 
{
	visited.insert(start);
	component->insert(start);

	for (int i = 0; i < edges[start].size(); i++) 
	{
		int adjacent = edges[start][i];
		if (visited.count(adjacent) == 0) 
		{
			dfs2(edges, adjacent, component, visited);
		}
	}
}

unordered_set<unordered_set<int>*>* getSCC(vector<int>* edges, vector<int>* edgesT, int n)
{
	unordered_set<int> visited;
	stack<int> finishedVertices;

	for (int i = 0; i < n; i++) 
	{
		if (visited.count(i) == 0) //if not visited, dodfs
		{
			dfs(edges, i, visited, finishedVertices);
		}
	}

	unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
	visited.clear(); //marking all vertices unvisited

	while (finishedVertices.size() != 0)  //till stack gets empty
	{
		int element = finishedVertices.top();
		finishedVertices.pop();

		if (visited.count(element) != 0) 
		{
			continue;
		}

		unordered_set<int>* component = new unordered_set<int>();
		dfs2(edgesT, element, component, visited);
		output->insert(component);

	}
	return output;
}

int main() {
	int n; //no of vertices, assuming you are numbered in problem vertices as 1 .... n
	//But for our internal calculations we'll convert to 0 ... n-1
	cin >> n;


	vector<int>* edges = new vector<int>[n]; //adj list for orig graph
	vector<int>* edgesT = new vector<int>[n]; //adj list for transpose graph


	int m; //no of edges
	cin >> m;

	for (int i = 0; i < m; i++) {
		int j, k;
		cin >> j >> k;
		edges[j - 1].push_back(k - 1); //push in orig graph

		edgesT[k - 1].push_back(j - 1); //push in transpose graph
	}

	//THIS WILL GET US ALL SCC
	unordered_set<unordered_set<int>*>* components = getSCC(edges, edgesT, n);
	

	//PRINTING ALL SCC
	unordered_set<unordered_set<int>*>::iterator it = components->begin();
	while (it != components->end()) 
	{
		unordered_set<int>* component = *it;
		unordered_set<int>::iterator it2 = component->begin();
		while (it2 != component->end()) 
		{
			cout << *it2  + 1<< " ";
			it2++;
		}
		cout << endl;
		delete component;
		it++;
	}

	//DELETION OF HEAP MEMORY
	delete components;
	delete [] edges;
	delete [] edgesT;
}
