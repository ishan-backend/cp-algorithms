#include<bits/stdc++.h>
#include<vector>
using namespace std;
//const long double PI = acos(-1.0);
#define PI 3.14159265358979323846
#define ll long long
#define MAX 100001 //root(Upper bound = 10^10) = 10^5

// creating sieve function 
// returns vector of primes from 2 to 10^10

vector<int>* sieve()
{
	bool isPrime[MAX];
	for(int i=0; i<MAX; i++)
	{
		isPrime[i] = true;
	}

	for(int i=2; i*i<MAX; i++)
	{
		if(isPrime[i])
		{
			for(int j=i*i; j<MAX; j+=i)
			{
				isPrime[j] = false;
			}
		}
	}

	//vector to return
	vector<int>* primes = new vector<int>();
	primes->push_back(2);
	for(int i=3; i<MAX; i++)
	{
		if(isPrime[i])
		{
			primes->push_back(i);
		}
	}

	return primes;
}

// function to print primes in range l to r
void printPrimes(ll l,ll r, vector<int>* &primes)
{
	bool isPrime[r-l+1];

	for(int i=0; i<=r-l; i++)
	{
		isPrime[i] = true;
	}

	// like sieve , in place of i its primes[i]*primes[i]<=r
	for(int i=0; primes->at(i)*(ll)primes->at(i) <= r; i++)
	{
		//for every prime, we've to set false all multiples of a prime
		// start setting false from l / base value
		// e.g. l =24, prime=2, start with (n/i)*i, it will either come as l or smaller to l
		// if base comes smaller to l, add base+=currPrime


		int currPrime = primes->at(i);

		//Just smaller or equal value to l
		ll base = (l/(currPrime))*currPrime;
		if(base < l)
		{
			base = base + currPrime;
		}

		//Mark all multiples within l to r as false
		for(ll j= base; j<=r; j+=currPrime)
		{
			isPrime[j - l] = false;

		}

		//Case when base itself is a prime number
		if(base == currPrime)
		{
			isPrime[base - l] = true;
		}

	}

	for(int i=0; i<=r-l; i++)
	{
		if(isPrime[i] == true)
		{
			cout<<i+l<<endl;
		}
	}
}

int main()
{
	vector<int>* primes = sieve();
	int t;
	cin>>t;
	while(t--)
	{
		ll l, r;
		cin>>l>>r;
		printPrimes(l, r, primes);

	}
	return 0;
}

/*Input
2 <
2 10 <
2
3
5
7
3 7 <
3
5
7
*/
