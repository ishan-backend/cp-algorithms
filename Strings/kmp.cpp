#include<bits/stdc++.h>
using namespace std;


/* finding longest prefix which is also a suffix*/
//Time Complexity: O(n)
//fills lps array for a given pattern
int* getLps(string pattern)
{
	int len = pattern.length();
	//lps returned should be atmax size of pattern
	int* lps = new int[len];

	//Base 
	lps[0] = 0;
	int i=1;
	int j=0;

	while(i<n)
	{
		if(pattern[i] == pattern[j])
		{
			lps[i] = j+1;
			i++, j++;
		}
		else
		{
			if(j!=0)
			{
				j=lps[j-1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
	return lps;

}

//KNUTH-MORRIS-PRATT algo-O(m)+O(n)
/*uses in pattern - lps = longest prefix which is also a suffix.
	thus, at any point in time we never went back in main string s. 
*/
bool kmpSearch(string text, string pattern)
{
	int lenText = text.length();
	int lenPat = pattern.length();
	int i=0, j=0;

	int *lps = getLps(pattern);
	while(i<lenText && j<lenPat)
	{
		if(text[i] == pattern[i])
		{
			i++, j++;
		}
		else
		{
			if(j!=0)
			{
				j = lps[j-1];
			}
			else
				i++;
		}
	}

	if(j == lenPat)
	{
		return true;
	}
	else
		return false;

}

signed main()
{
	string s, p; //s-string, p-pattern to match.
	//to find substring p in s
	
	s = "abcxabcdabcdabcy";
	p = "abcdabcy";
	cout<<kmpSearch(s, p)<<endl; //return 1;

	p = "abcdabcx";
	cout<<kmpSearch(s, p)<<endl; // returns 0; //not found

	return 0;
}