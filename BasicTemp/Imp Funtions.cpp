//BINOMIAL COEFFICIENT nCk:

int C[10005][10005]; 
int binomialCoeff(int n, int k) 
{ 
    // int C[n + 1][k + 1]; 
    int i, j; 
  
    // Caculate value of Binomial Coefficient 
    // in bottom up manner 
    for (i = 0; i <= n; i++) 
    { 
        for (j = 0; j <= min(i, k); j++) 
        { 
            // Base Cases 
            if (j == 0 || j == i) 
                C[i][j] = 1; 
  
            // Calculate value using previosly 
            // stored values 
            else
                C[i][j] = C[i - 1][j - 1] + 
                          C[i - 1][j]; 
        } 
    } 
  
    return C[n][k]; 
} 

// To check if x is a power of two:

bool isPowerOfTwo(int x) 
{ 
  /* First x in the below expression is for the case when x is 0 */
  return x && (!(x&(x-1))); 
}

// MODULAR EXPONENTIATION:
ll inf = 1e12;
ll mod = 1e9 + 7;
ll power(ll x, ll n, ll mod) {
  ll res = 1;
  x %= mod;
  while (n) {
    if (n & 1)
      res = (res * x) % mod;
    x = (x * x) % mod;
    n >>= 1;
  }
  return res;
}
