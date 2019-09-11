#include<bits/stdc++.h>
using namespace std;

void update(int index, int value, int* BIT, int n)
{
	// if 1 index is changed , array size=8, then 1->2->4->8
	for(; index<=n; index += index&(-index))
	{
		BIT[index] += value;
	}
}

int query(int index, int* BIT)
{
	int sum=0;
	for(; index>0; index -= index&(-index))
	{
		sum+=BIT[index];
	}
	return sum;
}

signed main()
{
	int n;
	cin>>n;
	int m;
	cin>>m;
	int c;
	cin>>c;
	
	int* arr = new int[n+1]();	// arr of size n=1 initialised to 0
	int* BIT = new int[n+1]();
	
	for(int i=1; i<=n; i++)
	{
	    arr[i] = c;
	    update(i, arr[i], BIT, n);
	}
	
	char ch;
	
	while(m--)
	{
	    cin>>ch;
	    
	    if(ch =='S')
	    {
	        int u, v, k;
	        cin>>u>>v>>k;
	        
	            update(u, k, BIT, n);
	        
	            update(v+1, -k, BIT, n);
	        
	        
	    }
	    
	    else
	    {
	        int p;
	        cin>>p;
	        cout<<query(p, BIT)<<endl;
	        
	    }
	}
	return 0;
}
