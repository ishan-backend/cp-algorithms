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

const int xoxo = 1000010;
const int maxn = 300010;

int divi[xoxo];

void prep()
{
    for (int i = 1; i < xoxo; i++)
    {
        for (int j = i; j < xoxo; j += i)
        {
            divi[j]++; //divisors of i
        }
    }
}

int n, m;
int st[4 * maxn];
int a[maxn];

void build(int i, int l, int r)
{
    if (l == r)
    {
        st[i] = a[l];
        return;
    }

    int mid = (l + r) >> 1;
    //recursive calls below
    int lc = i << 1;
    int rc = (i << 1) | 1;

    build(lc, l, mid);
    build(rc, mid + 1, r);

    //compute ans: sum of values in this range
    st[i] = st[lc] + st[rc];
}

void print_tree(int num_nodes)
{
    for (int i = 1; i <= num_nodes; i++)
    {
        cerr << i << " " << st[i] << endl;
    }
}


int query(int i, int ql, int qr, int l, int r)
{
    //total overlap
    if (ql <= l and qr >= r)
    {
        return st[i];
    }

    //no overlap
    if (ql > r or qr < l)
    {
        //for sum query->0 return
        //for min query-> INT_MAX return
        //for max query-> INT_MIN return;
        return 0;
    }

    int mid = (l + r) >> 1;
    int lc = i << 1;
    int rc = (i << 1) | 1;

    //recurse, phir niche se aye answers combine kro
    return query(lc, ql, qr, l, mid) + query(rc, ql, qr, mid + 1, r);
}

//point update
void update(int x, int val, int i, int l, int r)
{
    if (l == r)
    {
        st[i] = val;
        return;
    }

    int mid = (l + r) >> 1;
    int lc = i << 1;
    int rc = (i << 1) | 1;

    //if x lies in left half
    if (x <= mid)
    {
        update(x, val, lc, l, mid);
    }
    //else perform on right
    else
    {
        update(x, val, rc, mid + 1, r);
    }

    //reupdate this node
    st[i] = st[lc] + st[rc];
}





void solve()
{
    prep();
    int q; cin >> n >> q;

    for0(i, n) cin >> a[i];

    build(1, 0, n - 1); //startnode, l, r


    //set s: to maintain the indices of elements that have a value != 1 and != 2, bcz their a[i] == div[a[i]]
    set<int> s;

    for0(i, n)
    {
        if (a[i] != 1 and a[i] != 2)
        {
            s.insert(i);
        }
    }


    while (q--)
    {
        int tt; cin >> tt;

        if (tt == 1)
        {
            //replace
            int l, r;
            cin >> l >> r;
            --l, --r; //0-based arr


            //refine this range acc to set using bs
            auto it = s.lower_bound(l), it2 = s.upper_bound(r);

            //it2 wont be included
            //traversing in set
            while (it != it2)
            {
                int idx = *it;
                a[idx] = divi[a[idx]];

                //point update
                update(idx, a[idx], 1, 0, n - 1);
                it++;

                //cant delete an element from set when it is pointing to it, as we need it move forward
                if (a[idx] == 1 or a[idx] == 2)
                    s.erase(prev(it));
            }
        }
        else
        {
            //sum
            int l, r; cin >> l >> r;
            --l, --r;

            cout << query(1, l, r, 0, n - 1);
            cout << endl;
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




