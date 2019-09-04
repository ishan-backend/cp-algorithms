#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define endl "\n"
vector<ll> lazy, seg;// can make a struct also of same   

void recalculate(int root)
{
    seg[root] = seg[2* root] + seg[2* root + 1];
}

void propagate(int l, int r, int root=1)
{
    // root to store sum of all lazy value in range l to r
    seg[root] += lazy[root] * (r-l+1);
    if(l < r)//root is internal node 
    {
        //lazy value : only propagate called to children nodes of root, it doesnt go below it
        lazy[2*root] += lazy[root];
        lazy[2*root + 1] += lazy[root];

    }
    lazy[root] = 0; // reset lazy value of root to 0

}


//RANGE UPDATE:
void update(int l, int r, int x, int y, int value, int root=1)
{
    // if root has lazy value other than 0 then just propagate it to next level
    if(lazy[root]!=0)
    {
        propagate(l, r, root);
    }

    // total overlap
    if(x <= l and r <= y)
    {
        lazy[root] = value;
        return;
    }

    // no overlap
    if(r < x or l > y)
    {
        return;
    }

    int mid = (l+r)/2;
    update(l, mid, x, y, value, 2*root);
    update(mid+1, r, x, y, value, 2*root+1);

    // // so that updated values get updated back to root
    propagate(l, mid, 2*root);
    propagate(mid+1, r, 2*root+1);
   
    recalculate(root);
}

int query(int l, int r, int x, int y, int root=1)
{
    if(lazy[root]!=0)
    propagate(l, r, root);
    // total overlap
    if(x <= l and r <= y)
    {
        return seg[root];
    }

    // no overlap
    if(r < x or l > y or x>y)
    {
        return 0;
    }

    int mid = (l+r)/2;
    //we have to calculate range sum
    int sum = 0;
    sum += query(l, mid, x, y, 2*root );
    sum += query(mid+1, r, x, y, 2*root+1);
    return sum;
}

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t=1;
    cin>>t;

    while(t--)
    {
        int n;
    cin>>n;
    int Q;
    cin>>Q;
    // a.assign(n+1, 0);
    seg.assign(4*n, 0); //here initial input array is 0
    lazy.assign(4*n, 0);

    ll ans=0;
    int x, y;
    while(Q--)
    {
        int c;
        cin>>c;
        if(c == 0)
        {
            int value;
            cin>>x>>y>>value;
            update(1, n, x, y, value);

        }
        if(c == 1)
        {
            cin>>x>>y;
            ans = query(1, n, x, y);
            cout<<ans<<endl;
        }
    
    }

    }
    return 0;
}
