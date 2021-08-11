#include <bits/stdc++.h>
using namespace std;

int evaluateExpression(string A){
	if(A.length() == 0)
		return 0;
	stack <int> s;

	int n = A.length();
	for (int i = 0; i < n; ++i)
	{
		if(A[i]=='+' || A[i]=='-' || A[i]== '*' || A[i]== '/'){
			if(s.size()<=1)
				return 0;
			int num1 = s.top();
			s.pop();
			int num2 = s.top();
			s.pop();
            
            int num;
			switch(A[i])
			{
				case '+': 
				    num = num1 + num2;
				    break; 
				case '-': 
					num = num1 - num2;
					break;
				case '*': 
					num = num1 * num2;
					break;
				case '/': 
					num = num1 / num2;
					break;
			}

			s.push(num);
		}
		else
		{
			s.push((int)A[i] - '0');
		}
	}

	if(s.size()<1)
		return 0;
	else
		return s.top();
}

int main()
{
	/* code */
	string A = "21+3*";
	cout<<evaluateExpression(A)<<endl;
	return 0;
}