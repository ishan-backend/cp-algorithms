#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int n, q;
vector<int> a;
vector<ll> seg;

void recalculate(int root)
{
    seg[root] = min(seg[2*root], seg[2*root+1]);
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
        return INT_MAX;
    }

    int mid = (l+r)/2;
    //we have to calculate range sum
    ll minm, m1, m2;
    m1 = query(l, mid, x, y, 2*root );
    m2 = query(mid+1, r, x, y, 2*root+1);
    return min(m1, m2);
}

void point_update(int l, int r, int x, int value, int root = 1)
{
    if(l == r)
    {
        seg[root] = value;
        return;
    }

    int mid = (l+r)/2;
    if(x<=mid) //left me aa rha toh left wale ko update
    {
        point_update(l, mid, x, value, root*2);
    }

    else
    {
        point_update(mid+1, r, x, value, root*2 + 1);
    }
    recalculate(root);
}

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t=1;
    // cin>>t;
    while(t--)
    {
        
    
    cin>>n>>q;
    a.resize(n+1);
    seg.resize(4*n); //to prevent overflow
    
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }

    build(1, n); //make tree
    ll ans=0;
    int x, y;
    char ch;
    while(q--)
    {
    
    cin>>ch;
    if(ch == 'q')
    {
        cin>>x>>y;
        ans = query(1, n, x, y); //doing minm query
        cout<<ans<<endl;
    }
    
    else if(ch == 'u')
    {
        cin>>x>>y;
        point_update(1, n, x, y);
    }
    
    }

    }
    return 0;
}
