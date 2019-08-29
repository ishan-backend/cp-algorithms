#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int n;
vector<int> a;
vector<ll> seg;

void recalculate(int root)
{
    seg[root] = seg[2*root] + seg[2*root+1];
}

void build(int l, int r, int root=1)
{
    if(l == r)
    {
        seg[root] = a[l];
        return;
    }

    int mid = (l+r)/2;
    build(l, mid, 2*root);
    build(mid+1, r, 2*root+1);
    recalculate(root);

}

ll query(int l, int r, int x, int y, int root=1)
{
    // total overlap
    if(x <= l and r <= y)
    {
        return seg[root];
    }

    // no overlap
    if(r < x or l > y)
    {
        return 0;
    }

    int mid = (l+r)/2;
    //we have to calculate range sum
    ll sum = 0ll;
    sum += query(l, mid, x, y, 2*root );
    sum += query(mid+1, r, x, y, 2*root+1);
    return sum;
}

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t;
    cin>>t;
    while(t--)
    {
        
    
    cin>>n;
    a.resize(n+1);
    seg.resize(4*n); //to prevent overflow
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }

    build(1, n); //make tree

    int q;
    cin>>q;
    ll ans=0;
    int x, y;
    while(q--)
    {
    
    cin>>x>>y;
    ans = query(1, n, x, y); //doing sum query
    cout<<ans<<endl;
    }

    }
    return 0;
}
