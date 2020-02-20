struct graph
{
	int n;
	vector<vector<int>> adj;

	graph(int n) : n(n), adj(n) {}

	void add_edge(int u, int v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int add_node()
	{
		adj.push_back({});
		return n++;
	}

	vector<int>& operator[](int u) { return adj[u]; }
};

vector<vector<int>> biconnected_components(graph &adj)
{
	int n = adj.n;

	vector<int> num(n), low(n), art(n), stk;
	vector<vector<int>> comps;

	function<void(int, int, int&)> dfs = [&](int u, int p, int &t)
	{
		num[u] = low[u] = ++t;
		stk.push_back(u);

		for (int v : adj[u]) if (v != p)
		{
			if (!num[v])
			{
				dfs(v, u, t);
				low[u] = min(low[u], low[v]);

				if (low[v] >= num[u])
				{
					art[u] = (num[u] > 1 || num[v] > 2);

					comps.push_back({u});
					while (comps.back().back() != v)
						comps.back().push_back(stk.back()), stk.pop_back();
				}
			}
			else low[u] = min(low[u], num[v]);
		}
	};

	for (int u = 0, t; u < n; ++u)
		if (!num[u]) dfs(u, -1, t = 0);

	// build the block cut tree
	function<graph()> build_tree = [&]()
	{
		graph tree(0);
		vector<int> id(n);

		for (int u = 0; u < n; ++u)
			if (art[u]) id[u] = tree.add_node();

		for (auto &comp : comps)
		{
			int node = tree.add_node();
			for (int u : comp)
				if (!art[u]) id[u] = node;
				else tree.add_edge(node, id[u]);
		}

		return tree;
	};

	return comps;
}


//Tree implementaion -2
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef vector<vector<pair<int, int> > > vvii;


#define all(x) (x).begin(), (x).end()
#define nall(x) (x).rbegin(), (x).rend()
#define sz(a) int((a).size())
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define rz resize
#define MP make_pair
#define F first
#define S second
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define NFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)



struct dis_set
{
  vi p, r;
  dis_set() {}
  dis_set(int n): p(n), r(n) {FOR(i, 0, n - 1)p[i] = i;}

  int get(int i)
  {
    if (p[i] != i)p[i] = get(p[i]);
    return p[i];
  }
  int connect(int i, int j)
  {
    int x = get(i), y = get(j);
    if (x == y) return 0;
    if (r[x] < r[y])p[x] = y;
    else {p[y] = x; if (r[x] == r[y])++r[x];}
    return 1;
  }
};

struct BlockCutTree {
  vector<vector<pair<int, int> > > g;

  int n, m, dfsctr, root, child;
  vi dfs_num, dfs_low, depth, vis, is_art, low;
  vector<ii> e;
  dis_set edges;
  vvi blocks, toArt, inBlock;

  // special :
  vi here, ans, reached;
  vvi VIS;


  void dfs_pre(int u, int p, int e)
  {
    dfs_num[u] = dfs_low[u] = dfsctr++;
    low[u] = depth[u];
    for (auto it : g[u])
    {
      if (dfs_num[it.F] == -1)
      {
        depth[it.F] = depth[u] + 1;
        if (u == root)++child;
        dfs_pre(it.F, u, it.S);
        dfs_low[u] = min(dfs_low[u], dfs_low[it.F]);
        low[u] = min(low[u], low[it.F]);
        if (dfs_low[it.F] >= dfs_num[u])
          is_art[u] = 1;
        if (e != -1)if (low[it.F] < depth[u]) edges.connect(e, it.S);
      }
      else if (p != it.F)
      {
        if (e != -1)if (dfs_num[it.F] < dfs_num[u]) edges.connect(e, it.S);
        low[u] = min(low[u], depth[it.F]);
        dfs_low[u] = min(dfs_low[u], dfs_num[it.F]);
      }
    }
  }

  BlockCutTree (vvii &ig, int m): g(ig), m(m) {   // pair<to, edge_index>
    n = ig.size();

    e = vector<ii>(m);
    FOR (i, 0, n - 1) for (ii it : g[i]) e[it.S] = {i, it.F};

    low = is_art = dfs_low = depth = vis = vi(n);
    dfs_num = vi(n, -1);

    dfsctr = 0;
    root = 0, child = 0;
    edges = dis_set(m);
    dfs_pre(0, -1, -1);
    is_art[root] = child > 1;

    blocks = vvi(m);

    FOR (i, 0, m - 1) {
      blocks[edges.get(i)].pb(e[i].F);
      blocks[edges.get(i)].pb(e[i].S);
    }

    FOR (i, 0, m - 1) {
      sort(all(blocks[i]));
      blocks[i].erase(unique(all(blocks[i])), blocks[i].end());
    }
    toArt.resize(m), inBlock.resize(n);

    FOR (i, 0, m - 1) {
      for (int it : blocks[i]) {
        inBlock[it].pb(i);
        if (is_art[it]) {
          toArt[i].pb(it);
        }
      }
    }

  }

  void dfs(int u, bool isBlock) {
    if (isBlock and reached[u]) {
      ans = here;
      return;
    }
    VIS[u][isBlock] = 1;

    if (isBlock) {
      FOR (i, 0, sz(toArt[u]) - 1) {
        int v = toArt[u][i];
        if (!VIS[v][0]) {
          dfs(v, 0);
        }
      }
    }
    else {
      here.pb(u);
      FOR (i, 0, sz(inBlock[u]) - 1) {
        int v = inBlock[u][i];
        if (!VIS[v][1]) {
          dfs(v, 1);
        }
      }
      here.pop_back();
    }
  }

  void solve(int s, int e) {
    reached = vi(m);
    FOR (i, 0, sz(inBlock[e]) - 1) {
      reached[inBlock[e][i]] = 1;
    }
    VIS = vvi (m, vi(2));

    dfs(inBlock[s][0], 1);

    if (find(all(ans), s) != ans.end())
      ans.erase(find(all(ans), s));

    if (find(all(ans), e) != ans.end())
      ans.erase(find(all(ans), e));

    cout << sz(ans) << "\n";
    sort(all(ans));
    FOR (i, 0, sz(ans) - 1) {
      cout << ans[i] + 1 << "\n";
    }
  }
};
