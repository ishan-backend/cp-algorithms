#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long
#define ll long long
#define MAX 500001
#define mod 1000000007

//sieve returns vector of primes less than n
vector<int>* sieve()
{
	bool isPrime[MAX];

	//empty vector primes
	vector<int>* primes = new vector<int>();

	for(int i=2; i<=MAX; i++)
		isPrime[i] = true;

	for(int i=2; i*i<=MAX; i++)
	{
		if(isPrime[i])
		{
			for(int j=i*i; j<=MAX; j+=i)
			{
				isPrime[j] = false;
			}
		}
	}

	primes->push_back(2);	//since primes is a pointer so use ->
	for(int i=3; i<=MAX; i+=2)
	{
		if(isPrime[i])
		{
			primes->push_back(i);
		}
	}
	return primes;

}

ll divisors(int n, vector<int>* & primes)  
//since we dont change primes , we can take it by reference
{
	ll result = 1;
	for(int i=0; primes->at(i)<=n; i++)
	{
		int k = primes->at(i);
		//k is a prime no less than n
		//now we have to calculate n/k + n/k^2 + .... + till k^x < n
		// this is maxm power of prime no k when n! is represnted as product of powers of its prime factors
		ll count = 0;
		while((n/k)!=0)
		{
			count= (count + (n/k))%mod;
			k = k*primes->at(i);
		}

		result = (result*((count+1)%mod))%mod;
	}
	return result;
}


signed main()
{
	//precomputation primes
	vector<int>* primes = sieve();
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n; //actually taking n of n!
		cout<<divisors(n, primes)<<endl;
	}

	return 0;
}

/*INPUT
3
2
3
4
OUTPUT
2
4
8
*/
