template < typename T > T GCD(T a, T b)            { ll t; while(a) { t = a; a = b % a; b = t; } return b; }
template < typename T > string toString(T a)       { return to_string(a); }
template < typename T > void toInt(string s, T &x) { stringstream str(s); str >> x;}
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
inline int powr(int a, ll b){
  int x = 1 % mod;
  while(b){
    if(b & 1) x = mul(x, a);
    a = mul(a, a);
    b >>= 1;
  }
  return x;
}
inline int inv(int a){ return powr(a, mod - 2);}
 
const int N = 1e6 + 5;
 
int fact[N], invFact[N];
 
void pre() {
  fact[0] = invFact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = mul(fact[i - 1], i);
  }
  invFact[N - 1] = inv(fact[N - 1]);
  for (int i = N - 2; i >= 1; i--) {
    invFact[i] = mul(invFact[i + 1], i + 1);
  }
}
 
int nCr(int n, int r) {
  if (r > n) return 0;
  int ans = fact[n];
  ans = mul(ans, invFact[r]);
  ans = mul(ans, invFact[n - r]);
  return ans;
}
