#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

ll euclidianGCD(int a, int b)
{
    if(b == 0)
        return a;
    else
        return euclidianGCD(b, a%b);
    
}

ll reducedB(int a, string b)
{
    ll ans = b[0] - '0';
    for(ll i=1; b[i]!='\0'; i++)
    {
        ans = (ans*10 + (b[i] - '0'))%a;
    }
    //cout<<"ans : "<<ans<<"\n";
    return ans;
}

ll advanceGCD(int a, string b)
{
    ll bAfterMod = reducedB(a, b);
    //cout<<bAfterMod<<"\n";
    
    return euclidianGCD(a, bAfterMod);
}

signed main(){
    int a;
    string b;
    int t;
    cin>>t;
    
    while(t--){
        cin>>a;
        cin>>b;
        cout<<advanceGCD(a, b)<<endl;
    }
	
	return 0;
}
