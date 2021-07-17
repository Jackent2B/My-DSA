#include <bits/stdc++.h>
using namespace std;

int solve(string s, int n, int k){

	if(n==0)	
		return 0;

	unordered_map<char, int> mp;

	int length = 0;
	int start = 0;

	for (int i = 0; i < n; ++i)
	{
		mp[s[i]]++;

		while(mp.size()>k){
			mp[s[start]]--;

			if(mp[s[start]] == 0)
				mp.erase(s[start]);
			
			start++;
		}

		length = max(length, i - start +1);
	}
	return length;

}

int main(){

	string s = "AAAHHIBC";
	int n = s.length();
	int k = 2;
	cout<<solve(s,n,k)<<endl;
	
	return 0;
}