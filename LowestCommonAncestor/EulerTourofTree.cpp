#include<bits/stdc++.h>
using namespace std;

#define MAX 1001

vector<vector<int>> adj;
int vis[MAX];
int euler[2*MAX];  //O(n) space complexity

//Function to store euler tour of tree : basically uses dfs
//O(n) TC
void eulerTree(int u, int &idx)
{
    vis[u]=1;
    euler[idx]=u;
    idx++;
    for(auto it:adj[u])
    {
        if(!vis[it])
        {
            eulerTree(it, idx);
            euler[idx]=u;
            idx++;
        }
    }

}

signed main()
{
    int n;
    cin>>n;
    adj.resize(n+1);

    for(int i=0; i<n-1; i++)
    {
        int u, v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int root=1;
    int index=0; //to start filling in euler array
    eulerTree(1, index); //assumed that tree is rooted at 1.

    //print euler tree
    int idx=0;
    for(int i=0; i<2*n-1; i++)
    {
        cout<<euler[i]<<" ";
    }

    return 0;
}
