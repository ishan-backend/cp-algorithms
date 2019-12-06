#include<bits/stdc++.h>
using namespace std;

int mex(unordered_set<int> s){
    int MEX = 0;
    while(s.find(MEX)!=s.end()){
        MEX++;
    }
    return (MEX);
}

int grundy(int n){
    if(n==0)
        return (0);
    unordered_set<int> s;
    s.insert(grundy(n/2));
    s.insert(grundy(n/3));
    s.insert(grundy(n/6));
    return (mex(s));
}

int main() {
	int n;
    cin>>n;
    cout<<grundy(n)<<endl;
}
