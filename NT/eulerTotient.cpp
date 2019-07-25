//Complexity: O(n log log n)
#include<bits/stdc++.h>
using namespace std;

void eulerphi(int n)
{
	int phi[n+1];
	//we,ll use 1 based indexing a[i] = i
	for(int i=1; i<=n; i++)
	{
		phi[i] = i;
	}

	for(int i = 2; i<=n; i++)
	{
		if(phi[i] == i)//agar prime hai
		{
			phi[i] = i-1; //euler totient func

			//go to all multiples of this prime, multiply by i-1, then divide by i
			for(int j=2*i; j<=n; j+=i)
			{
				phi[j] = (phi[j]*(i-1))/i;
			}
		}
	}

	//printing euler totient phi for every number till n
	for(int i=1; i<=n; i++)
	{
		cout<<"euler totient phi for "<<i<<"is "<<phi[i]<<endl;
	}
}

signed main()
{
	eulerphi(10);
	return 0;
}