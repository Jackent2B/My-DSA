#include <bits/stdc++.h>
using namespace std;

int solve(string s, int n){

	if(n==0)
		return 0;

	int length = INT_MIN;
	int start =0;

	int begin = 0; 
	int end = 0;

	unordered_map <char, int> mp;
	for(int i = 0; i<n; i++){
		mp[s[i]]++;
		while(mp[s[i]]>1){
			mp[s[start]]--;
			start++;
		}
		length = max(length, i - start +1);
		// if(length == i - start +1){
		// 	begin = start;
		// 	end = i;
		// }
	}

	// cout<< s.substr(begin, end-begin +1)<<endl;
	return length;
}

int main(){
	string s = "findlongestsubstring";
	int n = s.length();
	cout<<solve(s,n)<<endl;
	return 0;
}