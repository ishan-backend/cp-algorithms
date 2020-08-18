#include "bits/stdc++.h"
using namespace std;

#define int long long
#define endl                     "\n"

void Ishan_Pandey()
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    cout << setprecision(16) << fixed;
}

#ifndef ONLINE_JUDGE
#define dbg(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {cerr << name << " : " << arg1 << endl;}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << "  ";
    __f(comma + 1, args...);
}
#else
#define dbg(...) 50
#endif

using ll = long long;
#define pb push_back

const int maxn = 100010;
const int logx = 18; // > 14
vector<int> adj[maxn];
int depth[maxn];
int par[maxn][logx];

void dfs(int x)
{
    depth[x] = depth[par[x][0]] + 1;

    for (int i = 1; i < logx; i++)
    {
        //calculate par at heights of 2^i from current node x
        par[x][i] = par[par[x][i - 1]][i - 1];
    }

    for (int i = 0; i < adj[x].size(); i++)
    {
        if (adj[x][i] != par[x][0])
        {
            par[adj[x][i]][0] = x;
            dfs(adj[x][i]);
        }
    }
}

int lca(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);
    for (int i = logx - 1; i >= 0; i--)
    {
        if (depth[par[a][i]] >= depth[b])
            a = par[a][i];
    }

    if (a == b) return a;

    for (int i = logx - 1; i >= 0; i--)
    {
        if (par[a][i] != par[b][i])
        {
            a = par[a][i];
            b = par[b][i];
        }
    }

    return par[a][0];
}

int dist(int a, int b)
{
    return depth[a] + depth[b] - 2 * depth[lca(a, b)];
}

int go(int f, int s, int t)
{
    //s to f, t to f

    bool is1 = lca(f, s) == f;
    bool is2 = lca(f, t) == f;
    int sol = 0;

    if (is1 != is2) return 1;

    if (is1)
    {
        sol = max(sol, depth[lca(s, t)] - depth[f]);
    }
    else if (lca(f, s) != lca(f, t ))
    {
        sol = max(sol, depth[f] - max(depth[lca(f, s)], depth[lca(f, t)]));
    }
    else
    {
        sol = max(sol, dist(f, lca(s, t)));
    }
    return sol + 1;
}

void solve()
{
    int n, q;
    cin >> n >> q;

    for (int i = 2; i <= n; i++)
    {
        int x; cin >> x;
        adj[i].pb(x);
        adj[x].pb(i);
    }

    dfs(1);

    while (q--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        int sol = go(a, b, c);
        sol = max({sol, go(b, a, c), go(c, a, b)});
        cout << sol << endl;

    }

}
signed main()
{
    Ishan_Pandey();
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;

    //cin >> t;

    while (t--)
    {
        solve();
        // cout << "Case" << " " << "#" << itr1 << ":" << " " << ans << endl;
    }
    dbg("Completed");

    return 0;
}
