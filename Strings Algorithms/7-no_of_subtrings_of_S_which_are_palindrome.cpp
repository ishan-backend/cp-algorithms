#include<bits/stdc++.h>
using namespace std;

int countnoofpalindromes(string s)
{
	int count=0;
	int len = s.length();
	for(int i=0; i<len; i++)
	{

		//Odd Length:
		//setting left and right pointers around that i
		int l=i-1;
		int r=i+1;
		count++; //wo charcater akela nhi ek palindrome hai

		while(l>=0 and r<len)
		{
			if(s[l]==s[r])
			{
				count++;
				l--;r++;
			}
			else
			{
				break;
			}
		}


		//Even Length:
		if(i<len-1 and s[i]==s[i+1])
		{
			l=i-1;
			r=i+2;
			count++;

			while(l>=0 and r<len)
			{
				if(s[l]==s[r])
			{
				count++;
				l--;r++;
			}
			else
			{
				break;
			}

			}
		}

	}
	return count;
}


signed main()
{
	string s;
	cin>>s;
	cout<<countnoofpalindromes(s)<<endl;
	return 0;
}
