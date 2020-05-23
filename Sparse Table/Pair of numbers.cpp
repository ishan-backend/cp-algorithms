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
#define um                       unordered_map

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
int dxx[4] = { 0 , -1 , 0 , 1 };
int dyy[4] = { 1 ,  0 , -1 ,  0 };
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};


//my first sparse table problem, can also be done through seg trees
const int xoxo = 300010;
int sparse[20][300010] , n, a[xoxo];

void build()
{
    int i, j;
    //for all segment of length (2^0) , their gcd is self
    for (i = 1; i <= n; i++)
        sparse[0][i] = a[i];

//calc sparse table by merging answers from its left half and right half block
    for (i = 1; i < 20; i++)
        for (j = 1; j + (1 << i) - 1 <= n; j++)
            sparse[i][j] = __gcd(sparse[i - 1][j], sparse[i - 1][j + (1 << (i - 1))]);
}

int query(int a, int b)
{
    int k = log2(b - a + 1);
    return __gcd(sparse[k][a], sparse[k][b - (1 << k) + 1]);
}


void solve()
{
    cin >> n;

    set<int> result; //consists of all l's with max length r-l of same gcd

    for (int i = 1; i <= n; i++) cin >> a[i];

    build();

    /**/


    int low = 0, high = 0, r = 0, l = 0, maxseg = 0;


    for (int i = 1; i <= n; i++)
    {
        //if i is to be the gcd in its segment, [from, to] ? does this seg exist

        //start
        low = 1, high = i;

        while (low <= high)
        {
            int mid = (low + high) >> 1;
            if (query(mid, i) == a[i])
            {
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        l = low;

        //end
        low = i, high = n;

        while (low <= high)
        {
            int mid = (low + high) >> 1;
            if (query(i, mid) == a[i])
            {
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        r = high;

        if (r - l > maxseg)
        {
            maxseg = r - l;
            result.clear();
            result.insert(l);
        }
        else if (r - l == maxseg)
        {
            result.insert(l);
        }

    }

    cout << sz(result) << " " << maxseg << endl;
    for (int x : result)
    {
        cout << x << " ";
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
    t2 = clock(); cerr << "time taken : " << (t2 - t1) / (ld)CLOCKS_PER_SEC;
#endif

    return 0;
}
