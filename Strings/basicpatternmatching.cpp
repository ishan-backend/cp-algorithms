#include<bits/stdc++.h>
using namespace std;

//Naive Approach
bool isMatching(string s, string p)
{
	int n = s.length();
	int m = p.length();
	for(int i=0; i<=(n-m); i++)
	{
		bool isFound = true;
		for(int j = 0; j<m; j++)
		{
			if(s[i+j]!=p[j])
			{
				isFound = false;
				break;
			}
		}
		if(isFound == true)
			return true;

	}
	return false;
}
signed main()
{
	string s, p; //s-string, p-pattern to match.
	//to find substring p in s
	cin>>s;
	cin>>p;
	cout<<isMatching(s, p)<<endl;
	return 0;
}

//Time Complexity: O(n*m) since, n-m almost is n because m is small.