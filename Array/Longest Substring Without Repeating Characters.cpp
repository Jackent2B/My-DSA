#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s, int n){
	if(n<=1) return n;

	unordered_map<char,int> mp;
	int length = 1;
	int left = 0;
	for(int i=0; i<n; i++){
		if(mp.find(s[i]) != mp.end()){
			left = max(mp[s[i]] + 1, left);
		}
		mp[s[i]] = i;
		length = max(length, i - left + 1);
	} 
	return length;
}

int main(){
	string s = "abcabcbb";
	int n = s.length();
	cout<<lengthOfLongestSubstring(s,n)<<endl;
	return 0;
}