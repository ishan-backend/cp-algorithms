#include "bits/stdc++.h"
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int                      long long
#define ll                       long long
#define ld                       long double
#define ull                      unsigned long long
#define vi                       vector<int>
#define pii                      pair<int,int>
#define mod                      1000000007 //998244353

#define for0(i,n)                for(int i=0;i<n;++i)
#define fora(i,a,b)              for(int i=a;i<=b;++i)
#define rfor(i,a,b)              for(int i=a;i>=b;--i)
#define onlyunique(v)            v.erase(unique(all(v)), v.end()); //only for sorted vector
#define rev(v)                   reverse(v.begin(),v.end())

#define sz(tmp)                  (int)tmp.size()
#define def(v)                   memset(v, -1, sizeof(v));
#define def0(v)                  memset(v, 0, sizeof(v));
#define all(v)                   v.begin(), v.end()
#define rall(v)                  v.rbegin(), v.rend()
#define f                        first
#define s                        second
#define pb                       push_back
#define mp                       make_pair
#define pie                      (3.141592653589)
#define inf                      ((ll)7000000000000000000)
#define um                       unordered_map

#define ordered_set             tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
//0-based idxing, methods: find_by_order(k); & order_of_key(k);
//To make it an ordered_multiset, use pairs of (value, time_of_insertion)
//to distinguish values which are similar.

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using maxpq = priority_queue<T>;

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

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

const int maxn = 200010;
int st[4 * maxn];
int lazy[4 * maxn];

void range_update(int i, int ql, int qr, int l, int r)
{
    //lazy values propagate down
    if (lazy[i])
    {
        //in ith node st[i] holds answer for segment [l,r]
        st[i] = (r - l + 1) - st[i];

        //propagate down if this isnt leaf
        if (l != r)
        {
            lazy[2 * i] ^= 1;
            lazy[2 * i + 1] ^= 1;
        }
        lazy[i] = 0;
    }


    //no overlap
    if (ql > r or qr < l)
    {
        return;
    }

    //total overlap: is jagah st me update krdo, next level pe updates lazy me daal do
    //return kr jao
    if (ql <= l and qr >= r)
    {
        //we're sure as we have handled lazy values above
        //only handle st values here
        st[i] = (r - l + 1) - st[i];
        if (l != r)
        {
            lazy[2 * i] ^= 1;
            lazy[2 * i + 1] ^= 1;
        }
        lazy[i] = 0;
        return;
    }

    int mid = (l + r) >> 1;
    range_update(2 * i, ql, qr, l, mid);
    range_update(2 * i + 1, ql, qr, mid + 1, r);

    //after calling recursions
    ///update st for next query
    st[i] = st[2 * i] + st[2 * i + 1]; //total on bulbs
}


//query ke samay
int range_query(int i, int ql, int qr, int l, int r)
{
    if (lazy[i])
    {
        //in ith node st[i] holds answer for segment [l,r]
        st[i] = (r - l + 1) - st[i];

        //propagate down if this isnt leaf
        if (l != r)
        {
            lazy[2 * i] ^= 1;
            lazy[2 * i + 1] ^= 1;
        }
        lazy[i] = 0;

    }

    //no overlap
    if (ql > r or qr < l)
    {
        return 0; //no on bulbs
    }

    //total overlap:
    if (ql <= l and qr >= r)
    {
        //we're sure as we have handled lazy values = 0 by now
        //only focus on returning st values
        return st[i];
    }
    int mid = (l + r) >> 1;

    return range_query(2 * i, ql, qr, l, mid) + range_query(2 * i + 1, ql, qr, mid + 1, r);
}



void solve()
{
    int n, m; cin >> n >> m;

    //st initially all 0

    while (m--)
    {
        int type;
        cin >> type;

        if (type == 0)
        {
            //push all button in this range exactly once: toggle states
            int l, r;
            cin >> l >> r;
            --l, --r;
            //root of st, ql, qr, ll, rl
            range_update(1, l, r, 0, n - 1);
        }
        else
        {
            //how many lights are on in this range
            int l, r;
            cin >> l >> r;
            --l, --r;
            cout << range_query(1, l, r, 0, n - 1) << endl;

        }

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




