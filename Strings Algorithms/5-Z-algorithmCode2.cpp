/*

We can construct Z array in linear time.

The idea is to maintain an interval [L, R] which is the interval with max R
such that [L,R] is prefix substring (substring which is also prefix). 

Steps for maintaining this interval are as follows – 

1) If i > R then there is no prefix substring that starts before i and 
   ends after i, so we reset L and R and compute new [L,R] by comparing 
   str[0..] to str[i..] and get Z[i] (= R-L+1).

2) If i <= R then let K = i-L,  now Z[i] >= min(Z[K], R-i+1)  because 
   str[i..] matches with str[K..] for atleast R-i+1 characters (they are in
   [L,R] interval which we know is a prefix substring).     
   Now two sub cases arise – 
      a) If Z[K] < R-i+1  then there is no prefix substring starting at 
         str[i] (otherwise Z[K] would be larger)  so  Z[i] = Z[K]  and 
         interval [L,R] remains same.
      b) If Z[K] >= R-i+1 then it is possible to extend the [L,R] interval
         thus we will set L as i and start matching from str[R]  onwards  and
         get new R then we will update interval [L,R] and calculate Z[i] (=R-L+1).


*/


#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false);cin.tie(false);cout.tie(false);

//Z algorithm: finds longest substring which is also a prefix in O(n).

void buildZ(int* Z, string str)
{
	int l=0;
	int r=0;

	int n=str.length();
	for(int i=1; i<n; i++)
	{
		if(i>r)
		{
			//i does not lie between l and r
			//Z for this doesnt exist
			l=i;
			r=i;
			while(r<n and str[r-l]==str[r])
			{
				r++;
			}
			Z[i]=r-l;
			r--;
		}
		else
		{
			int k=i-l;
			if(Z[k]<=r-i)
			{
				//it lies between l and r
				//z will exist previously
				Z[i]=Z[k];
			}
			else
			{
				//some part of Z is aready included
				//You have to start matching further
				l=i;
				while(r<n and str[r-l]==str[r])
				{
					r++;
				}
				Z[i]=r-l;
				r--;

			}
		}
	}
}

void search(string text, string pattern)
{
	string str = pattern+"$"+text;
	int n=str.length();
	int* Z=new int[n](); //Z array of n size initialised to 0
	buildZ(Z, str);
	for(int i=0; i<n; i++)
	{
		if(Z[i]==pattern.length())
		{
			//position of occurence of pattern in text
			cout<<i-pattern.length()-1<<endl;
		}
	}

}

signed main()
{
	string text, pattern;
	cin>>text>>pattern;
	search(text, pattern);
	return 0;
}
