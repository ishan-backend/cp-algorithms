#include<bits/stdc++.h>
using namespace std;
// a^b%c

//Recursive Modular Exponentiation-O(log n)
int modExpo(int a, int b, int c)
{
	if(a==0)
		return 0;
	if(b==0)
		return 1;

	long ans;
	if((b%2)==0)
	{
		//b is even
		long smallAns = modExpo(a, b/2,c);
		ans = (smallAns*smallAns)%c;
	}
	else
	{
		//b is odd
		//can use long/int in smallAns here
		long smallAns = modExpo(a, b-1, c);
		ans = (a%c);
		ans = (ans*smallAns)%c;
	}

	//handling for -ve answers as well
	return (int)((ans+c)%c);

}

//Iterative Modular Exponentiation- O(log b) S.C=> O(1) no extra space
int modExpoIt(int a, int b, int c)
{
	if(a==0)
		return 0;
	if(b==0)
		return 1;
	long ans=1;
	while(b!=0)
	{
		//get rightmost bit of b
		int rightmostBit = (b&1);
		if( rightmostBit == 1)
		{
			ans=(ans*a)%c;
		}
		a = (a*a)%c;
		b= b/2;
	}

	return ans;
}

signed main()
{
	int a=5;
	int b=5;
	int c=1e9+7;

	cout<<modExpo(a,b,c)<<endl;
	cout<<modExpoIt(a,b,c)<<endl;
	return 0;
}
