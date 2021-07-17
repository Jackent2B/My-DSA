#include <bits/stdc++.h>
using namespace std;

bool suspicious(string s, int n){

	unordered_map<char,int> mp;
	mp[s[0]]++;
	for (int i = 1; i < n; ++i)
	{
		if(mp.find(s[i]) == mp.end()){
			mp[s[i]]++;
		}
		else{
			if(s[i] == s[i-1])
				mp[s[i]]++;
			else
				return true; 
		}
	}
	return false;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		if(suspicious(s,n))
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	return 0;
}