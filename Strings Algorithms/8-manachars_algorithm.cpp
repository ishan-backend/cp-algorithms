#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
//MANACHARs : O(n)
string convert(const string &s)
{
	string newstr="@";
	for(int i=0; i<s.size(); i++)
	{
		newstr += "#" + s.substr(i, 1);
	}

	newstr += "#$";
	return newstr;
}


int p[MAX*2];
string longestPalindromicSubstring(const string &s)
{
	string Q = convert(s);
	int c=0, r=0; //current center, right limit

	//outer loop
	for(int i=1; i<Q.size(); i++)
	{
		//find the corressponding letter in palindromic substring
		int iMirror = c-(i-c);


		//condition1:
		if(r>i)
		{
			p[i] = min(r-i, p[iMirror]);
		}

		//expanding around center i
		while(Q[i+1+p[i]] == Q[i-1-p[i]])
		{
			p[i]++;
		}

		//conditon2:
		if(i+p[i]>r)
		{
			c=i;	//next center =i
			r=i+p[i];
		}
	}

	//inner loop: to find longest palindrome length in p
	int maxPalindrome=0; //length of maxm palindrome
	int centeridx=0;

	for(int i=1; i<Q.size(); i++)
	{
		if(p[i]>maxPalindrome)
		{
			maxPalindrome = p[i];
			centeridx=i;
		}
	}

	// cout<<maxPalindrome<<endl;
	return s.substr((centeridx-1-maxPalindrome)/2, maxPalindrome);
}

void solve()
{
	string s;
	cin>>s;

	string lps = longestPalindromicSubstring(s);
	cout<<lps.length()<<endl;
	cout<<lps<<endl;
}


signed main()
{
	int t;
	t=1;
	// cin>>t;
	while(t--)
	{
		solve();
	}

	return 0;
}
