#include<bits/stdc++.h>
using namespace std;

class  Triplet{

public:
	int x;
	int y;
	int gcd;	
};

Triplet extendedEuclid(int a, int b)
{
	//Extended Euclid Algorithm - to solve linear diophantine equations

	//Base Case:
	if(b == 0)
	{
		Triplet ans;
		ans.gcd = a;
		ans.x = 1;
		ans.y = 0;
		return ans;

	}
	Triplet smallAns = extendedEuclid(b, a%b);
	Triplet ans;
	ans.gcd = smallAns.gcd;		//1. gcd(a,b)
	ans.x = smallAns.y;			//2. x=y1
	ans.y = smallAns.x - (a/b)*smallAns.y;			//3. y = x1 - (a/b)*y1
	return ans;
	
}

// Multiplicative Modulo Inverse: 

// for eqn (a.b)+m =1 we have a and m , we get b.
// we got eqn a.b + mQ =1, using extended euclids ax+by = 1.
// whatever comes value of x is value for b.
// and that will exist if gcd(a, m) = 1
int mmInverse(int a, int b)
{
	Triplet ans = extendedEuclid(a, m);
	return	ans.x;
}

signed main()
{
	int a = 5;
	int b;
	int m = 17;
	// Here assuming that a and m ka gcd is 1. You can check it.
	int ans = extendedEuclid(a, b);
	// we know 5*7 = 35 modulo 17 is 1
	// so ans should be 7, similarly
	// if a = 5, m = 12
	// since 5 modulo 12 is 1
	// so 5*5 = 25 modulo 12 is 1, so b is 5
	cout<<"Multiplicative modulo inverse is"<<ans<<endl;
	return 0;
}