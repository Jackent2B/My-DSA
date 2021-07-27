#include <bits/stdc++.h>
using namespace std;

int longestValidParenthesis(string s){
	stack<int> st; // store the index of brackets 
	st.push(-1); // for this case only = "()""

	int maxans = 0;
	for(int i=0; i<s.length(); i++){
		if(s[i]=='('){
			st.push(i);
		}
		else{
			// )))()
			if(!st.empty()){
				st.pop();
			}

			if(!st.empty())
				maxans = max(maxans, i - st.top());
			else
				st.push(i);
		
		}
	}
	return maxans;
}
int main(){
	string s = "(()(()";
	cout<<longestValidParenthesis(s);
	return 0;
}