#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
 
struct node
{
    int val,m;
};

vector<node> seg;
vector<int> arr;
 
void recalculate(int root)
{
    int left = root*2,right = root*2+1;
    int solution = max(max(seg[left].val,seg[right].val),seg[left].m + seg[right].m);
    int maximum = max(seg[left].m,seg[right].m);
    seg[root].val = solution;
    seg[root].m = maximum;
}
 
void build(int l, int r, int root = 1)
{
    if(l==r){
        seg[root].val = 0;
        seg[root].m = arr[l];
        return;
    }
 
    int mid = (l+r)/2;
    build(l,mid,root*2);
    build(mid+1,r,root*2 + 1);
    recalculate(root);
}
 
node query(int l, int r, int x, int y, int root = 1)
{
    if(x<=l and r<=y){
        return seg[root];
    }
    if(y<l or x>r){
        node newNode;
        newNode.val = 0;
        newNode.m = 0;
        return newNode;
    }
 
    int mid = (l+r)/2;
    node le = query(l,mid,x,y,root*2);
    node re = query(mid+1,r,x,y,root*2+1);
    int f = max(max(le.val,re.val), le.m+re.m);
    int s = max(le.m, re.m);
    node newNode;
    newNode.val = f;
    newNode.m = s;
    return newNode;
 
}
 
void update(int l, int r, int x, int value, int root)
{
    if(l==r){
        seg[root].m = value;
        return;
    }
    int mid = (l+r)/2;
    if(x<=mid){
        update(l,mid,x,value,root*2);
    }
    else{
        update(mid+1,r,x,value,root*2+1);
    }
    recalculate(root);
}
 
signed main(){
    FASTIO
    int n;
    cin>>n;
    arr.resize(n+1);
    seg.resize(4*n);
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    build(1,n);
     int q; cin >> q;
     int x,y;
     while(q--){
         char ch;
         cin>>ch;
         if(ch == 'Q'){
            cin>>x>>y;
            node tempNode = query(1,n,x,y);
            cout<<tempNode.val<<"\n";
         }
         if(ch == 'U'){
            cin>>x>>y;
            update(1,n,x,y,1);
         }
     }
    return 0;
}

/*
INput:
5
1 2 3 4 5
6
Q 2 4
Q 2 5
U 1 6
Q 1 5
U 1 7
Q 1 5

Output:
7
9
11
12
*/
