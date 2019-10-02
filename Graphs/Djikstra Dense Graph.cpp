/* 
You are given a directed or undirected weighted graph with n vertices and m edges. 
The weights of all edges are non-negative.
You are also given a starting vertex s. This article discusses finding the lengths of the shortest paths from a starting vertex s to all other vertices, and output the shortest paths themselves.

single-source shortest paths problem.
*/

//DENSE GRAPH DJIKSTRA : O(n^2 + m): in dense graph is optimal where m == n^2


#include<bits/stdc++.h>
using namespace std;
#define INF 1000000000;

//adj list
vector<vector<pair<int, int>>> adj;

//start vertex, distance array, parent array (by reference pass)
void djikstra(int s, vector<int> &d, vector<int> &p)
{
    int n = adj.size();  //no of vertices in graph
    d.assign(n, INF);
    p.assign(n, -1);

    //visited array - initialised as false
    vector<bool> u(n, false);

    /*
    Dijkstra's algorithm performs n iterations.
     On each iteration it selects an unmarked vertex v with the lowest value d[v],
      marks it and checks all the edges (v,to) attempting to improve the value d[to].

    */

    d[s] = 0;
    for(int i=0; i<n; i++) //n iterations
    {
        int v = -1; //unmarked vertex which is to be selected this iteration (out of left unmarked vertices)

        for(int j=0; j<n; j++)
        {
            //if out of all these vertices
            //1. if not visited
            //AND
            //2. if parent still set to -1(for starting vertex only) OR dis of jth vertex is less than vth vertex 

            if(!u[j] and (v == -1 or d[j] < d[v]))
            {
                v = j;
            }
        } 
        //v is now vertex that has minm d[] from source s among unmarked vertices



        /*
        if some vertices are unreachable from the starting vertex s, the values d[v] for them will remain infinite.
         Obviously, the last few iterations of the algorithm will choose those vertices, but no useful work will be done for them.
          Therefore, the algorithm can be stopped as soon as the selected vertex has infinite distance to it.

        */
        if(d[v] == INF)
            break;
        

        u[v] = 1; //v is marked visited
        for(auto edge: adj[v])   // in adjlist, for a vertex v , adj[v] holds all the vertices which have edge from v, that is v is from
        {
            int to = edge.first;
            int weight = edge.second;

            //relaxation
            if (d[v] + len < d[to]) 
            {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }

    } //n iterations
}

signed main()
{




    return 0;
}
