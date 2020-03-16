const ll N=1000005;
ll spf[N];
void sieve()
{
    rep(i,1,N)
        spf[i]=i;
    for(ll i=2;i*i<N;i++)
    {
        if(spf[i]==i)
        {
            for(ll j=i*i;j<N;j+=i)
            {
                if(spf[j]==j)
                    spf[j]=i;
            }
        }
    }
}
