
ll power(ll x, ll y, ll p) { 
    ll res = 1; 
    x = x % p;
    while (y>0) 
    { 
        if (y&1) 
            res = ((res%p)*(x%p))%p; 
        y = y>>1; 
        x = ((x%p)*(x%p))%p; 
    } 
    return res; 
}
ll modInverse(ll n, ll p) { 
    return power(n,p-2,p); 
} 
ll nCrModPFermat(ll n, ll r, ll p) {  
   if (r==0) 
      return 1;
      if(r==n)
      return 1;
    ll fac[n+1]; 
    fac[0] = 1; 
    for (int i=1 ; i<=n; i++) 
        fac[i] = (fac[i-1]*i)%p; 
    return (((fac[n]%p)*(modInverse(fac[r],p)%p))%p * (modInverse(fac[n-r],p)%p))%p; 
}
