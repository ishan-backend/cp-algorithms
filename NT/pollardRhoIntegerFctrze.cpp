// Given a positive intger n, if that is composite find a divisor for it
// Particularly for large composite numbers, with small prime factors.
// gives prime factors of large composite numbers.

/*
	algo:

	start with random x and c
	f(x) = x^2 + c
	while a divisor isnt obtained 
	- update x to f(x) mod n
	- update y to f(f(y)) mod n
	-  calc gcd of |x-y| and n
	- if gcd is not unity :
		-- if gcd is n, repeat step 2 with another set of x, y amd c
		-- else gcd is our answer
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

// to calc (b^exp)%mod
ll modular_pow(ll b, ll e, ll mod)
{
	ll ans=1;
	while(e>0)
	{
		// if e is odd
		if(e & 1)
			ans = (ans * b)%mod;

		// e = e/2, is actually deleting last bit of e
		e = e>>1;
		//dividing e (power) by 2 means we should square the no
		b = (b*b)%mod;
	}
	return ans;
}

// Pollard Rho- uses modular_pow function
ll pollardRho(ll n)
{
	// random seed initialise
	srand(time(NULL));

	if(n == 1) return 1;
	if(n%2 == 0) return 2; //if even n , then one of divisors is 2

	// pick from range [2, n)
	ll x = (rand()%(n-2))+2;
	ll y = x;

	// constant in f(x)
	ll c = (rand()%(n-1))+1;

	//initialise candidate divisor or result
	ll d =1;

	//until p.f. isnt obtained
	//however if n is prime return n
	while(d == 1)
	{
		//Tortoise
		x = (modular_pow(x, 2, n) + c + n)%n;	//x(i+1) = f(x(i))

		//Hare
		y = (modular_pow(y, 2, n) + c + n)%n;	//y(i+1) = f(f(y(i)))

		//check of gcd abs(x-y) and n
		d = __gcd(abs(x-y), n);

		//retry if algo fails to find prime factor with chosen x and c
		if (d == n)
			return pollardRho(n);
	}
	return d;
}

signed main()
{
	ll n = 10967535067;
	cout<<"One of divisors for n is "<<pollardRho(n)<<endl;

	return 0;
}

