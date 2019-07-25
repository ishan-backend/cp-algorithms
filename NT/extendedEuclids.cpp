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
signed main()
{
	int a=16;
	int b = 10;
	Triplet ans = extendedEuclid(a, b);
	cout<<ans.gcd<<endl<<ans.x<<endl<<ans.y;
	//16*2 + 10*-3 = 2
	return 0;
}
