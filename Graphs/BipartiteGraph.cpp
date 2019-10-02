#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool bipartite(vector<int>* edges, int n) 
{
	//this never happens but still check
	if (n == 0) 
	{
		return true;
	}

	unordered_set<int> sets[2]; //creating two sets for two colors: Red and Blue: these sets will contain vertex nos
	vector<int> pending; //pending nodes is a vector that acts as squeue
	
	sets[0].insert(0); //add first node 0 to the first color set
	pending.push_back(0); //add 0th node to pendingnodes also

	//"Pending Nodes tells me : which vertices i've colored(put in either of two sets"
	//"But we havent still checked their neighbours".

	while (pending.size() > 0) 
	{
		int current = pending.back(); //working on either first/last entry, since vector can be popped back easily(cheaper)
		pending.pop_back();

		//now we need to check if the popped element has all neighbours (not of same set as it is)
		int currentSet = sets[0].count(current) > 0 ? 0 : 1;
		for (int i = 0; i < edges[current].size(); i++) 
		{
			int neighbor = edges[current][i];

			//Two possibilities:

			//1) if neighbor(current) isnt in both color sets
			if (sets[0].count(neighbor) == 0 && sets[1].count(neighbor) == 0) 
			{
				//then put neighbor in opposite color set than that of current vertex
				sets[1 - currentSet].insert(neighbor);
				pending.push_back(neighbor); //push neighbor in queue
			} 
			//2) else if neighbor is in current color set, then its problem
			// that means it can never be a bipartite graph
			else if (sets[currentSet].count(neighbor) > 0) 
			{
				return false;
			}
		}
	}

	//else if all nodes have been colored successfully, then its bipartite graph
	return true;
}

int main() 
{
	while (true) 
	{
		int n;
		cin >> n;

		//if 0 is encountered, input is terminated
		if (n == 0)
			break;

		vector<int>* edges = new vector<int>[n]; //adj list

		int m;
		cin >> m;

		for (int i = 0; i < m; i++) 
		{
			int j, k;
			cin >> j >> k;
			//assuming vertices are numbered 0 .. n-1
			edges[j].push_back(k);
			edges[k].push_back(j);
		}

		bool ans = bipartite(edges, n);

		delete [] edges;

		if (ans) 
		{
			cout << "BICOLORABLE." << endl;
		} 
		else 
		{
			cout << "NOT BICOLORABLE." << endl;
		}
	}

	return 0;
}

/*
INPUT:
5
5
0 1
1 2
2 3
3 4
0 4

OUTPUT:
NOT BICOLORABLE
*/
