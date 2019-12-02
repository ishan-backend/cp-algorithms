#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;

using ordered_set =  tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ;

#define int long long
#define ll long long
#define endl "\n"
#define mod 1000000007
#define pi pair<int, int> 
#define mi map<int, int>
#define f first
#define s second
#define pb push_back
#define mp  make_pair
#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)

const int N = 1e5+5;
const int LG = 19; //maxheight LG=X in 2^X = N;
int n, timer=0;
//we'll use dfs for assigning heights so we need timer
int starttime[N], endtime[N], storelevel[N];

int par[LG][N]; //par at height 2^i of node j



vector<int> level[N]; //used to find blood cousins
vector<int> adj[N]; //list


//dfs stores immediate parent of each node ,and assigns levels to each node of rooted tree/s in graph
void dfs(int k, int parent, int lvl)
{
    starttime[k] = ++timer;
    storelevel[k] = lvl;
    par[0][k] = parent; //at height 1

    level[lvl].pb(timer); //final ans uses this ...

    for(auto i: adj[k])
    {
        if(i == parent)
            continue;
        dfs(i, k, lvl+1);
    }
    endtime[k] = timer;
}

void precompute() //stores parents at heights 2^i using recurrence
{
    for(int j=1; j<LG; j++)
    {
        for(int i=1; i<=n; i++) //nodes in graph numbered 1..n
        {
            par[j][i] = par [j-1] [par[j-1][i]] ;
        }
    }
}

int kth_ancestor(int u, int k)//ancestor at kth height from u
{
    int curr = u;
    for(int j=20; j>=0; j--)//from MSB to LSB
    {
        //if jth bit is set in k
        if(k & (1ll<<j))
        {
            //move curr to its jth heighted parent
            curr = par[j][curr];
        }
    }
    return curr;
}

void solve()
{
    cin>>n;
    for1(i, n)
    {
        int par;
        cin>>par; //parent of ith node
        adj[par].pb(i);
    }

    //0th node is nothing but it will help us in height precomputation

    dfs(0, 0, 0); 
    precompute();

    int q;
    cin>>q;
    // cout<<q;
    while(q--)
    {
        int v, p;
        cin>>v>>p;

        int node = kth_ancestor(v, p);

        if(node == 0)
            cout<<"0"<<" ";

        else
        {
            int cur = storelevel[v]; //level where we have to find total no of blood cousins
            // cout<<cur;
            int ans;
            
            ans = upper_bound(level[cur].begin(), level[cur].end(), endtime[node]) - lower_bound(level[cur].begin(), level[cur].end(), starttime[node]);

            ans--; //bcz v is already , we have to find its blood cousins
            cout<<ans<<" ";
        }
    }

    return;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cout << setprecision(9) << fixed;
    clock_t z = clock();

    int t=1;
    // cin>>t;
    while(t--)
    {
        solve();
    }


    #ifndef ONLINE_JUDGE
    cout << "\nRun Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
    #endif
    return 0;
}
