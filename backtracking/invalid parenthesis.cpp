#include <bits/stdc++.h>
using namespace std;

int minBracketToRemove(string s){
	
	stack<char> st;
	for (int i = 0; i < s.length(); ++i)
	{
		if(s[i]=='('){
			st.push(s[i]);
		}
		else if(s[i]==')'){
			if(st.size()==0)
				st.push(s[i]);
			else if(st.top()=='(')
				st.pop();
			else if(st.top()==')') 
				st.push(s[i]);
		}
	}
	return st.size();
}

void removeInvalidParenthesis(string s,int minrmv, set<string> &ansset){
	
	if(minrmv == 0){
		if(minBracketToRemove(s) == 0){
			if(ansset.find(s) == ansset.end())
				ansset.insert(s);
		}
		return;
	}

	for (int i = 1; i < s.length()-1; ++i)
	{
		string left = s.substr(0,i);
		string right = s.substr(i+1);
		removeInvalidParenthesis(left+right, minrmv-1, ansset);
	}

}

int main(){

    string s = "()())()";
    // Minimum removals to make string s valid
    int minrmv = minBracketToRemove(s);
 	
 	set<string> ansset;
    removeInvalidParenthesis(s,minrmv,ansset);
    
    for(auto it: ansset){
        cout<<it<<endl;
    }
  	return 0;
}