#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int maxn = 100005;
int n;

struct node
{
    int count0;
    int count1;
    int count2;
}str;

vector<int> a(maxn);
vector<str> lazy(4*maxn), seg(4*maxn);

void recalculate(int root)
{
    seg[root].count0 = seg[2*root].count0 + seg[2*root+1].count0;
    seg[root].count1 = seg[2*root].count1 + seg[2*root+1].count1;
    seg[root].count2 = seg[2*root].count2 + seg[2*root+1].count2;
    return;
}

//intitially all array is 0, so count0 at each leaf node of seg tree will be 1, rest will be 0
void build(int l, int r, int root)
{
    if(l == r)
    {
        seg[root].count0 = 1;
        seg[root].count1 = 0;
        seg[root].count2 = 0;
        return;
    }

    if(l > r)
        return;
    
    int mid = (l+r)/2;
    build(l, mid, 2*root);
    build(mid+1, r, 2*root+1);
    recalculate(root);

}

void shuffle(int root)
{
    int temp = seg[root].count0;
    seg[root].count0 = seg[root].count2;
    seg[root].count2 = seg[root].count1;
    seg[root].count1 = temp;
    return;
}

void update(int l, int r, int x, int y, int root)
{

    //PROPAGATE ROOT PART:
    //in range [l, r] covered by root, if total no of numbers div by 3, modulo is 0
    if(lazy[root]%3 == 1)
    {
        seg[root].shuffle();
        if(l != r)
        {
            lazy[2*root] += lazy[root]%3;
            lazy[2*root+1] += lazy[root]%3;
        }

    }

    else if(lazy[root]%3 == 2)
    {
        seg[root].shuffle();
        seg[root].shuffle();
        if(l != r)
        {
            lazy[2*root] += lazy[root]%3;
            lazy[2*root+1] += lazy[root]%3;
        }
    }

    else if(lazy[root]%3 == 2 and lazy[root])
    {
         if(l != r)
        {
            lazy[2*root] += lazy[root]%3;
            lazy[2*root+1] += lazy[root]%3;
        }
        
    }

    lazy[root] = 0;

    //ACTUAL UPDATE:

    // total overlap
    if(x <= l and r <= y)
    {
        return seg[root].shuffle();
    }

    // no overlap
    if(r < x or l > y or l>r)
    {
        return;
    }

    if(l != r)
    {
        lazy[2*root] += 1;
        lazy[2*root+1] += 1;
        return;
    }

    int mid = (l+r)/2;
    update(l, mid, x, y, 2*root);
    update(mid+1, r, x, y, 2*root+1);
    recalculate(root);

}

node query(int l, int r, int x, int y, int root)
{

    //PROPAGATE ROOT PART:
    //in range [l, r] covered by root, if total no of numbers div by 3, modulo is 0
    if(lazy[root]%3 == 1)
    {
        seg[root].shuffle();
        if(l != r)
        {
            lazy[2*root] += lazy[root]%3;
            lazy[2*root+1] += lazy[root]%3;
        }

    }

    else if(lazy[root]%3 == 2)
    {
        seg[root].shuffle();
        seg[root].shuffle();
        if(l != r)
        {
            lazy[2*root] += lazy[root]%3;
            lazy[2*root+1] += lazy[root]%3;
        }
    }

    else if(lazy[root]%3 == 2 and lazy[root])
    {
         if(l != r)
        {
            lazy[2*root] += lazy[root]%3;
            lazy[2*root+1] += lazy[root]%3;
        }
        
    }

    lazy[root] = 0;


    //QUERY:
    node ans;
    ans.count0 = 0;
    ans.count1 = 0;
    ans.count2 = 0;

    // total overlap
    if(x <= l and r <= y)
    {
        return seg[root];
    }

    // no overlap
    if(r < x or l > y or l>r)
    {
        return ans;
    }

    int mid = (l+r)/2;
    node m1 = query(l, mid, x, y, 2*root);
    node m2 = query(mid+1, r, x, y, 2*root+1);
    node m;
    m.count0 = m1.count0 + m2.count0;
    m.count1 = m1.count1 + m2.count1;
    m.count2 = m1.count2 + m2.count2;
    return m;

}

signed main()
{   
    int n, q;
    cin>>n>>q;
    build(1, n, 1);

    int type, x, y;
    while(q--)
    {
        cin>>type;
        cin>>x>>y;
        if(type == 0)
        {
            update(1, n, x+1, y+1, 1);
        }

        if(type == 1)
        {
            printf("%d\n", query(1, n,x+1, y+1, 1).count0);
        }
    }
    return 0;
}
