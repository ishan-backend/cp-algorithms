/* Hello World. Author: IP */
#include<bits/stdc++.h>
using namespace std; 
// #define int                     long long
#define ll                      long long
#define ull                     unsigned long long
#define ld                      long double

#define mp                       make_pair
#define pb                       push_back
#define eb                       emplace_back
#define for0(i,n)                for(int i=0;i<n;++i)
#define fora(i,a,b)              for(int i=a;i<=b;++i)
#define rfor(i,a,b)              for(int i=a;i>=b;--i)

#define endl '\n' 
#define vvll                     vector<vector<int>>
#define vll                      vector<int>
#define mii                      map<int,int> 
#define msi                      map<string, int>

#define all(v)                   (v.begin(), v.end())
#define sz(x)                    (int)x.size()

#define sint                     set<int>
#define pii                      pair<int,int>
#define pqbig                    priority_queue<int>
#define pqsmall                  priority_queue<int,vi,greater<int> >

#define fi                       first
#define se                       second

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(nullptr);
#define MOD 1000000007
const long double PI = acos(-1.0);
//Some functions **********************************************************************************

ll power(ll x, ll y)
{
    if(y==0) return 1;
    ll z = power(x, y/2);
    z = z*z;
    z %= MOD;
    return (y&1 ? (z*x)%MOD : z);
}
bool prime[400005];
ll fac[10000010];

// void fact(){ fac[0]=1; for(int i=1;i<=10000000;i++){ fac[i]=(fac[i-1]*i)%mod;} return; }

void sieve(){ prime[0]=0; prime[1]=0;
    for(int i=2;i<400005;i++)
    {    prime[i]=1; }
    for(int i=2;i*i<400005;i++)
    {
        if(prime[i]==1){ for(int j=i*i;j<400005;j+=i){  prime[j]=0; }}
    }
}
ll siz[500005]; ll par[500005]; 
ll find(ll u)
{
    if(par[u] == u)
    {
        return u;
    }
    return find(par[u]);
}

void add(ll u, ll v)
{
    ll p1 = find(u); ll p2 = find(v);
    if(p1 == p2) return;
    if(siz[p1] < siz[p2]) swap(p1, p2);
    siz[p1] += siz[p2];
    par[p2] = p1;
    return;
}
// You might start coding here ***********************************************************************
inline int add(int a, int b, int mod = MOD) {
  a += b; return a >= mod ? a - mod : a;
}
inline int sub(int a, int b, int mod = MOD) {
  a -= b; return a < 0 ? a + mod : a;
}
inline int mul(int a, int b, int mod = MOD) {
  return int((long long) a * b % mod);
}
inline int mpow(int base, long long ex, int mod = MOD) {
  int res = 1;
  for (; ex > 0; ex >>= 1) {
    if (ex & 1) res = mul(res, base, mod);
    base = mul(base, base, mod);
  }
  return res;
}
inline int inv(int a, int mod = MOD) {
  return mpow(a, mod - 2, mod);
}
inline int mdiv(int a, int b, int mod = MOD) {
  return mul(a, mpow(b, mod - 2,  mod));
}
inline void adds(int &a, int b, int mod = MOD) {
  a += b; if (a >= mod) a -= mod;
}
inline void subs(int &a, int b, int mod = MOD) {
  a -= b; if (a < 0) a += mod;
}
inline void muls(int &a, int b, int mod = MOD) {
  a = int((long long) a * b % mod);
}
inline void mdivs(int &a, int b, int mod = MOD) {
  a = mdiv(a, b, mod);
}
void solve() 
{
  int n; cin >> n;
  vector<array<int,2>> a(n << 1);

  for(int i = 0; i < n; ++i) 
  {
    cin >> a[i][0] >> a[i][1];
    a[i + n][0] = a[i][0];
    a[i + n][1] = a[i][1];
  }

  vector<int> b(2 * n + 1);
  for (int i = 0; i < 2 * n; ++i) 
  {
    adds(b[i + 1], mul(a[i][0], a[(i + 1) % n][1]));
    subs(b[i + 1], mul(a[i][1], a[(i + 1) % n][0]));
    adds(b[i + 1], b[i]);
  }

  int q; cin >> q;

  while (q--) 
  {
    int l, r;
    cin >> l >> r;
    if (l == r) 
    {
      cout << "0\n";
      continue;
    }
    if (r < l) r += n;
    
    int ans = 0;

    adds(ans, mul(a[r - 1][0], a[l - 1][1]));
    subs(ans, mul(a[r - 1][1], a[l - 1][0]));
    adds(ans, b[r - 1]);
    subs(ans, b[l - 1]);

    ans = sub(0, ans);
    cout << ans << '\n';
  }
}

signed main()
{
    fastio;
    int t=1;
   // cin>>t;
    while(t--)
    {
       solve();
    }
    return 0;
}
