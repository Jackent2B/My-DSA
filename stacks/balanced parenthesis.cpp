#include <bits/stdc++.h>
using namespace std;

bool parenthesisChecker(string exp){
	stack <char> s;
	char x;
	if (exp.size()==0)
		return false;

	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i]=='{' || exp[i]=='[' || exp[i]=='(')
			{
				s.push(exp[i]);
				continue;
			}	

		// IF current current character is not opening 
        // bracket, then it must be closing. So stack 
        // cannot be empty at this point.
		
		if (s.size()==0)
			return false;

		switch(exp[i])
		{
		case ')': 
		     x=s.top();
		     s.pop();
		     if (x=='{' || x=='[')
		     	return false;
			 break;
		case '}': 
		     x=s.top();
		     s.pop();
		     if (x=='(' || x=='[')
		     	return false;
			 break;
		case ']': 
		     x=s.top();
		     s.pop();
		     if (x=='{' || x=='(')
		     	return false;
			 break;
		}

	}

	//check stack becomes empty or not.
	return s.empty();
}

int main(){
	string exp = "[()]{}{[()()]()}";
	if(parenthesisChecker(exp))
		cout<<"Balanced"<<endl;
	else
		cout<<"Unbalanced"<<endl;
	return 0;
}