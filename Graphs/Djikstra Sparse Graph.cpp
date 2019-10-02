/* 
You are given a directed or undirected weighted graph with n vertices and m edges. 
The weights of all edges are non-negative.
You are also given a starting vertex s. This article discusses finding the lengths of the shortest paths from a starting vertex s to all other vertices, and output the shortest paths themselves.

single-source shortest paths problem.
*/

//SPARSE GRAPH DJIKSTRA : O(n log m + m log n) using pq


#include<bits/stdc++.h>
using namespace std;
#define INF 1000000000;

//adj list
vector<vector<pair<int, int>>> adj;

void djikstra(int s, vector<int> &d, vector<int> &p)
{
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    //vector<bool> found(n+1, false);

    d[s] = 0;
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;

    q.push({0, s});

    while(!q.empty())
    {
        int v = q.top().second; //current vertex
        int d_v = q.top().first;  //distance of current vertex

        q.pop();

        /*
        Therefore we need to make a small modification: at the beginning of each iteration,
         after extracting the next pair, we check if it is an important pair or if it is already an old and handled pair.
         This check is important, otherwise the complexity can increase up to O(nm).
         */
        if (d_v != d[v])
            continue;
        //OR for this operation, we can create a bool array of visited globally and check if its already visited(for an old pair)
        /*
        if(found[curr] == true)
                continue;
        found[curr] = true;
        */


        for (auto child : adj[v])
        {
            int to = child.first;
            int len = child.second;

            if (d[v] + len < d[to]) //if curr distance  + child.second < distance of child.first
            {
                d[to] = d[v] + len; //update distance of child.first
                p[to] = v; //update parent
                q.push({d[to], to});  //put distance of child.first and and child.first in pq.
            }
        }

    }

}



signed main()
{




    return 0;
}
