#include<bits/stdc++.h>
using namespace std;

void bitmasks(int arr[], int n)
{

for(int i=0; i<(1<<n); i++)//masks
{
	for(int j=0; j<n; j++)
	{
		if((i&(1<<j))>0) //precedence
		{
			cout<<ch[i];
		}
	}
	cout<<endl;
	}
}


signed main()
{
	int n;
	cin>>n;
	char ch[n];
	for(int i=0; i<n; i++)
	{
		cin>>ch[i];
	}

	int size = 1<<n;



	return 0;
}
