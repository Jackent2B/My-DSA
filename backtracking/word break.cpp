#include <bits/stdc++.h>
using namespace std;


void wordBreak(string word,set<string> dict, string ans){
	
	if(word.length() == 0){
		cout<<ans<<endl;
		return;
	}

	for (int i = 0; i < word.length();++i)
	{
		string left = word.substr(0,i+1);
		if(dict.find(left) != dict.end()){
			string right = word.substr(i+1);
			wordBreak(right, dict, ans +" "+left);
		}
	}

}
 
int main()
{
	set <string> dict;
	dict.insert("mobile");
	dict.insert("samsung");
	dict.insert("sam");
	dict.insert("sung");
	dict.insert("man");
	dict.insert("mango");

	dict.insert("icecream");
	dict.insert("and");
	dict.insert("go");
	dict.insert("i");
	dict.insert("like");
	dict.insert("ice");
	dict.insert("cream");
	
 	string ans = " ";
 	string word = "ilikesamsung";
    wordBreak(word,dict,ans);

    return 0;
}