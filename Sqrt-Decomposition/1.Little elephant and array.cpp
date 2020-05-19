#include "bits/stdc++.h"
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll                       long long int
#define ld                       long double
#define ull                      unsigned long long
#define vi                       vector<int>
#define pii                      pair<int,int>
#define pqbig                    priority_queue<int>
#define pqsmall                  priority_queue<int,vi,greater<int> >
#define mod                      1000000007 //998244353

#define for0(i,n)                for(int i=0;i<n;++i)
#define fora(i,a,b)              for(int i=a;i<=b;++i)
#define rfor(i,a,b)              for(int i=a;i>=b;--i)
#define onlyunique(v)            v.erase(unique(all(v)), v.end()); //only for sorted vector
#define rev(v)                   reverse(v.begin(),v.end())

#define sz(x)                    (int)x.size()
#define def(v)                   memset(v, -1, sizeof(v));
#define def0(v)                  memset(v, 0, sizeof(v));
#define all(v)                   v.begin(), v.end()
#define rall(v)                  v.rbegin(), v.rend()
#define fi                       first
#define se                       second
#define pb                       push_back
#define mp                       make_pair
#define pie                      (3.141592653589)
#define inf                      ((ll)1000000000000000000)

#define ordered_set             tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

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


void ishan_pandey()
{   //input fastio
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}


//Tutorial of Mo's:
//https://codeforces.com/blog/entry/7383
//https://www.hackerearth.com/practice/notes/mos-algorithm/
//Problems:
//https://codeforces.com/blog/entry/23005
//https://www.hackerearth.com/practice/notes/mos-algorithm/
//comparator: https://codeforces.com/blog/entry/7383?#comment-274639
//Solution starts here:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

const int maxn  = 100100;
const int block = 450; //block size: k+1 blocks of array, each of size sqrt(maxn)

struct Query
{
    int l, r, idx;

    //overloading < operator to sort Query data type
    bool operator < (const Query &other) const
    {
        if ( l / block != other.l / block)
            return l / block < other.l / block;
        return (r < other.r) ^ ((l / block) % 2);
    }
};

int n, a[maxn];
Query queries[maxn];

//problem: to find unique x such that x = freqof x, in range [l, r]
int freq[maxn];
int ret[maxn] = {0};
int ans = 0;

void add(int i) //i is being taken into consideration
{
    if (a[i] <= n)
    {
        if (freq[a[i]] == a[i])
            ans--;
        //freq[a[i]]++;
        if (++freq[a[i]] == a[i])
            ans++;
    }
}

void remove(int i) //i removed out of consideration
{
    if (a[i] <= n)
    {
        if (freq[a[i]] == a[i])
            ans--;
        //freq[a[i]]--;
        if (--freq[a[i]] == a[i])
            ans++;
    }
}


void solve()
{
    int m; cin >> n >> m;
    for0(i, n)
    cin >> a[i];

    for0(i, m)
    {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--, queries[i].r--; //0-based array
        queries[i].idx = i;
    }

    sort(queries, queries + m);

    for0(i, m)
    {
        dbg(queries[i].l, queries[i].r, queries[i].idx);
    }
    //only queries sorted till now
    int mo_lft = 0, mo_rgt = -1; //no segment currently

    for (int i = 0; i < m; i++)
    {
        //converging to queries: reach queries[i].l and stop same for right
        while (mo_lft < queries[i].l)
        {
            remove(mo_lft++);
        }
        while (mo_lft > queries[i].l)
        {
            add(--mo_lft);
        }
        while (mo_rgt < queries[i].r)
        {
            add(++mo_rgt);
        }
        while (mo_rgt > queries[i].r)
        {
            remove(mo_rgt--);
        }
        //[queries[i].l, queries[i].r] reached and ans calculated
        ret[queries[i].idx] = ans;
    }

    for0(i, m)
    {
        cout << ret[i] << endl;
    }
}

signed main()
{
    clock_t t1, t2;
    t1 = clock();

    ishan_pandey();
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve();
        // cout << "Case" << " " << "#" << i << ":" << " " << ans << endl;
    }

#ifndef ONLINE_JUDGE
    t2 = clock(); cerr << "time taken: " << (t2 - t1) / (ld)CLOCKS_PER_SEC;
#endif

    return 0;
}
