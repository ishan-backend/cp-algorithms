#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define maxn 50005;
vector<int> a;
struct node
{
    int sasum;  //max nonempty subarray sum
    int psum;   //max nonempty prefix sum
    int ssum;   //max nonempty suffix sum
    int sum;    // standard sum

}str;

vector<str> seg;

void recalculate(int root)
{
    seg[root].sum = seg[2*root].sum + seg[2*root+1].sum;

    seg[root].psum = max( seg[2*root].psum, seg[2*root].sum + seg[2*root+1].psum );

    seg[root].ssum = max( seg[2*root+1].ssum, seg[2*root+1].sum + seg[2*root].ssum );

    //maxm subarray sum
    seg[root].sasum = max( max( seg[2*root].sasum, seg[2*root+1].sasum ), seg[2*root].ssum + seg[2*root+1].psum);
}

void build(int l, int r, int root)
{
    if(l == r)
    {
        seg[root].sum = seg[root].psum = seg[root].ssum = seg[root].sasum = a[l];
    }

    else
    {
        int mid = (l+r)/2;
        build(l, mid, 2*root);
        build(mid+1, r, 2*root+1);
        recalculate(root);
    }

}

node query(int l, int r, int x, int y, int root)
{
    //just overlap
    if(x == l and r == y)
    {
        return seg[root];
    }

    // no overlap / handling partial overlaps 
    else if(y <= (l+r)/2 )
    {
        return query(l, (l+r)/2, x, y, 2*root);
    }

    else if(x > (l+r)/2)
    {
        return query((l+r)/2 + 1, r, x, y, 2*root+1);
    }

    int mid = (l+r)/2;
    node left = query(l, mid, x, mid, 2*root);
    node right = query(mid+1, r, mid+1, y, 2*root+1);
    
    
}

signed main()
{ 
    int n;
    cin>>n;
    a.assign(n+1, 0);
    seg.resize(4*n);

    // for(int i=1; i<=4*n; i++)
    // {
    //     seg[i].sasum=0, seg[i].psum=0, seg[i].ssum=0, seg[i].sum=0;
    // }  
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    build(1, n, 1);

    int m, x, y;
    cin>>m;
    while(m--)
    {
        cin>>x>>y;
        int ans;
        ans = query(1, n, x, y, 1);
        cout<<ans<<endl;
    }
    return 0;
}
