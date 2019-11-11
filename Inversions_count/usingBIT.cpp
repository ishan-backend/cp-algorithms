    #include <bits/stdc++.h>
    using namespace std;
     
    typedef long long llong;
     
    const int MAXN = 500020;
    llong tree[MAXN], A[MAXN], B[MAXN];
     
    llong read(int idx)
    {
     	llong sum = 0;
     		while (idx > 0)
     		{
      			sum += tree[idx];
      			idx -= (idx & -idx);
     		}
     	return sum;
    }
     
    void update(int idx ,llong val)
    {
     	while (idx <= MAXN)
     	{
      		 tree[idx] += val;
    		 idx += (idx & -idx);
     	}
    }
     
     
    signed main() 
    {
        int t;
        cin>>t;
        while(t--)
        {
     
            int N;
            cin>>N;
     
          //prerequisites
          memset(tree, 0, sizeof(tree));      
          for(int i = 0; i < N; ++i) 
          {
             scanf("%lld",&A[i]);
             B[i] = A[i];
          }
          sort(B, B + N);
          for(int i = 0; i < N; ++i) 
          {
             int rank = int(lower_bound(B, B + N, A[i]) - B);
             A[i] = rank + 1;
          }
          
          //using BIT
          llong inv_count = 0;
          for(int i = N - 1; i >= 0; --i) 
          {
             llong x = read(A[i] - 1);
             inv_count += x;
             update(A[i], 1);
          }
          
          printf("%lld\n",inv_count);
       
     
        }
       return 0;
    } 




//SPOJ YODANESS:
#include <iostream>

#include<bits/stdc++.h>
using namespace std;
#define llong long long 
const int MAXN = 300020;
llong tree[MAXN];

//using BIT:

llong read(int idx)
{
    llong sum = 0;
    while (idx > 0)
    {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int val, int idx, int n)
{
    while (idx <= n)
    {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}


signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        memset(tree, 0, sizeof(tree));   

        map<string, int> mymap;
        int temp=n;
        for(int i=1; i<=n; i++) //keeping array/map 1-based
        {
            string str;
            cin>>str;
            mymap[str] = i;
        }
        int* arr = new int[n+1];

        for(int i=1; i<=n; i++) //keeping array/map 1-based
        {
            string str;
            cin>>str;
            arr[i] = mymap[str];
        }

        int invcnt=0;
        for(int i=n; i>=1; i--)
        {
            invcnt += read(arr[i]);
            update(1, arr[i], n);
        }

        mymap.clear();
        cout<<invcnt<<endl;

    }
    return 0;
}


