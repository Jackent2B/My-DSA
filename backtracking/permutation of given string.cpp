#include <bits/stdc++.h>
using namespace std;

void findPermutation(string s, vector<string> &ans, string permutation){

	if(s.length()==0){
		ans.push_back(permutation);
		return;
	}

	for (int i = 0; i < s.length(); ++i)
	{
		string prefix = s.substr(0,i);
		char c = s[i];
		string postfix = s.substr(i+1);
		string newStr = prefix + postfix;
		findPermutation(newStr,ans,permutation + c);
	}
}

int main(){
	string s;
	cin>>s;
	vector<string> ans;
	findPermutation(s,ans," ");
	sort(ans.begin(),ans.end());
	for (int i = 0; i < ans.size(); ++i)
		cout<<ans[i]<<endl;
	return 0;
}