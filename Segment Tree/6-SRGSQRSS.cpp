#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct node //each node of seg tree
{
    int ssum; //sum of squares of all values in range[L,R]
    int sum; //sum of all values in range[L,R]
};

struct node2 //each node of lazy tree
{
    int type; //initially no type, is type of update query: 1-> increment values by , 2-> make values equals
    int value; //updated value for that subarray from update query
};

vector<node> seg;
vector<node2> lazy;


//STEP1) BUILD THE TREE................................................
void recalculate(int root)
{
    seg[root].ssum = seg[2*root].ssum + seg[2*root+1].ssum;
    seg[root].sum = seg[2*root].sum + seg[2*root+1].sum;
}
void build(int l, int r, int root=1) //start, end, root
{
    if(l == r) //when at leaf nodes
    {
        seg[i].ssum = arr[l]*arr[l];
        seg[i].sum = arr[l];
    }

    int mid = (l+r)/2;
    build(l, mid, 2*root);
    build(mid+1, r, 2*root+1);
    recalculate(root);
}

//STEP2) Handle Range updates -- >>> LAZY PROPAGATION
void update(int l, int r, int x, int y, ll v, int qtype, int root=1) //l, r = array range in which input is taken; x,y = update in this interval, 
{
    if(l > r) return; //out of range

    if(lazy[root].type != 0) //if already before on this lazy node, some type is set, that means we need to propgate to its children
    // then only we can perform current update
    {
        ll uvalue = lazy[root].value; 
        //take out update value at root from lazy tree, update in seg tree
        //then progate to its children in lazy tree
        seg[root].sum = uvalue * (r-l+1);
        seg[root].ssum = uvalue * uvalue * (r-l+1);

        if(l != r)//if root is not leaf node, then obly propagate
        {
            lazy[2*root].type=0;
            lazy[2*root].value = uvalue;
            lazy[2*root+1].type=0;
            lazy[2*root+1].value = uvalue;
        }
        lazy[root].value=0;
    }

    if(lazy[root].value != 0)//if update value on node in lazy tree is not 0
    {
        ll uvalue = lazy[root].value;
        seg[i].ssum += ( uvalue*uvalue*(r-l+1) + 2*uvalue*(seg[root].sum));

        seg[i].sum += uvalue*(r-l+1);


        if(l != r)
        {
            lazy[2*root].value += uvalue;
            lazy[2*root+1].value += uvalue;
        }
        lazy[root].value=0;
    }

    //no overlap
    if(x > r or y < l)
        return;
    
    //total overlap : if update to be performed range[x, y] lies within current subarray range[l, r]
    if(x >= l and y <= r)
    {
        if(qtype == 0) //set all nos in range[x, y] as v
        {
            seg[root].sum = v*(y-x+1);
            seg[root].ssum = v*v*(y-x+1);

            if(y != x)
            {

            lazy[2*root].type=0;
            lazy[2*root].value = v;
            lazy[2*root+1].type=0;
            lazy[2*root+1].value = v;

            }
        }
        else //when qtype is 1 -> increment values in range[x, y] by v
        {
            seg[root].ssum += v*v*(y-x+1) + 2*v*(seg[root].sum);
            seg[root].sum += v*(y-x+1);

            if(y != x)
            {
                 lazy[2*root].value += v;
                 lazy[2*root+1].value += v;
            }

        }
        
        return;
    }

    int mid = (l+r)/2;
    update(l, mid, x, y, v, qtype, 2*root);
    update(mid+1, r, x, y, v, qtype, 2*root+1);
    recalculate(root);
}

ll query(int l, int r, int x, int y, int i)
{
    if()
}



void solve()
{
    int n, q;
    cin>>n>>q;

    ll arr[n+1];
    for(int j=1; j<=n; j++)
    {
        cin>>arr[j];
    }

    seg.resize(4*n);
    build(1, n, 1); //range in seg tree to build: 1 (points)-> arr[1], n -> arr[n], root=1.
    //till build only segment tree is used.

    //lazy is used for range updates.
    lazy.resize(4*n);
    for(int j=0; j<4*n; j++)
    {
        lazy[j].type = 0;
        lazy[j].value=0; //contains update value
    }

    for(int j=0; j<q; j++)
    {
        int qtype;
        cin>>qtype;

        if(qtype==0 or qtype==1)
        {
            //1 -> add x to all nos with indices in [l,r]
            //0-> set all nos with indices in [l, r] with x
            int l, r;
            ll x;
            cin>>l>>r>>x;

            update(1, n, l, r, x, qtype, 1); //last 1 is root
        }

        else if(qtype==2) //return sum of squares of the nos with indices in [l, r]
        {
            int l, r;
            cin>>l>>r;
            cout<<query(1, n, l, r, 1)<<endl;
        }
    }


}

signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
