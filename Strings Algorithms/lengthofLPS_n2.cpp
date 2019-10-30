 #include<bits/stdc++.h>
 using namespace std;
 

 //O(n^2)-doesnt work in cp ;)
int lps(string s) //returns length of longest palindromic substring
{	
	int maxm=1;
	// int start=0;
	int n = s.length();
	for(int i=0; i<n; i++)
	{
		//Odd Length

		int l=i;
		int r=i;
		while(l>=0 and r<n and s[l]==s[r])
		{
			int curr_len = r-l+1;
			if(curr_len>maxm)
			{
				// start = l;
				maxm = curr_len;
			}
			l--; r++;
		}

		

		//Even Length

		l=i;
		r=i+1;
		while(l>=0 and r<n and s[l]==s[r])
		{
			int curr_len = r-l+1;
			if(curr_len>maxm)
			{
				// start = l;
				maxm = curr_len;
			}
			l--;r++;
		}
	}

	return maxm;

}
 
 
 void solve()
 { 
 	string s;
 	cin>>s;
 	cout<<lps(s)<<endl;
 
 }
 
 signed main(){
     ios_base::sync_with_stdio(false);
     cin.tie(nullptr);
     int t=1;
     // cin>>t;
     while(t--){
         solve();
     }
     return 0;
 }
