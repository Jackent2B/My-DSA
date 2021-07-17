#include <bits/stdc++.h>
using namespace std;

void allPermutations(string s, string ans){

	if(s.length() == 0){
		cout<<ans;
		return;
	}

	for(int i=0; i<s.length(); i++){
		string left_part = s.substr(0,i);
		string right_part = s.substr(i+1);
		string rest = left_part + right_part;
		ans = ans + s[i];
		allPermutations(rest, ans);
	}
}

int main(){
	string s = "abc";
	string ans = "";
	return 0;
}