#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false);cin.tie(false);cout.tie(false);

//O(n) way to find longest prefix which is also a suffix
//Function returns lps array
int* getLPS(string pattern)
{
	int len = pattern.length();
	int* lps = new int[len]();

	lps[0]=0;
	int i=1;
	int j=0;
	while(i<len)
	{
		if(pattern[i] == pattern[j])
		{
			lps[i]=j+1;
			j++;i++;
		}
		else
		{
			if(j!=0)
			{
				j=lps[j-1];

			}
			else
			{
				//if j==0
				lps[i]=0;
				i++;
			}
		}

	}
	return lps;
}

//KMP search algorithm:(to tell if pattern is present in text)
bool kmPSearch(string text, string pattern)
{
	int lenText=text.length();
	int lenPat=pattern.length();

	int i=0;
	int j=0;

	int* lps = getLPS(pattern);

	while(i<lenText and j<lenPat)//aagar ye while loop j ki wajah se tuta toh hme pakka j cross kiya hoga lenpattern , mtlb pattern mil gya
	{
		if(text[i]==pattern[j])
		{
			
			i++;j++;

		}
		else
		{
			if(j!=0)
			{
				j=lps[j-1];
			}
			else
			{
				i++;
			}
		}

	}
	if(j==lenPat)
	{
		return true;
	}
	return false;
}

// //KMP search to count no of occurences of P in text T and return all those occurences
// int kmpSearch(string text, string pattern)
// {
// 	int lenText=text.length();
// 	int lenPat=pattern.length();

// 	int i=0;
// 	int j=0;
// 	int ctr=0;
// 	int* lps = getLPS(pattern);

// 	while(i<lenText and j<lenPat)
// 	{
// 		if(text[i]==pattern[j])
// 		{
			
// 			i++;j++;

// 		}
// 		if(j==lenPat)//additional condition *, reset j for further
// 		{
// 			ctr++;
// 			j=lps[j-1];
// 		}
// 		else //if (i<lenText and pattern[j]!=text[j])
// 		{
// 			if(j!=0)
// 			{
// 				j=lps[j-1];
// 			}
// 			else
// 			{
// 				i++;
// 			}
// 		}

// 	}
// 	return ctr;
// }



signed main()
{
	string text, pattern;
	cin>>pattern>>text;
	int temp =kmpSearch(text, pattern);
	cout<<temp;
	return 0;
}
