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
