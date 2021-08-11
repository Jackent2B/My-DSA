#include <bits/stdc++.h>
using namespace std;
 
// Algo: Push all the other elements other than ')'.
// Whenever we encounter ')', pop() the elements from stack till we encounter '('.
// Then Pop() this '(' as well.

bool checkRedundancy(string str)
{
    stack<char> st;
    int n = str.length();

    for (int i = 0; i < n; ++i)
    {
        if(str[i]==')'){
            
            if(st.top() == '(')
                return true;

            int count = 0; //count of operators
            while(st.top() != '('){
                //for the case like (a+(b)/c)
                if(st.top() =='+' || st.top() =='*' || st.top() =='/' || st.top() =='-'){
                    count++;                    
                }
                st.pop();
            }
            st.pop();
            //for the case like (a+(b)/c)
            if(count==0)
                return true;
        }
        else
            st.push(str[i]);
    }

    return false;
}
  
  
int main()
{
    string str = "((a+b))";
    cout<<checkRedundancy(str)<<endl;
  
    str = "(a+(b)/c)";
    cout<<checkRedundancy(str)<<endl;
  
    str = "(a+b*(c-d))";
    cout<<checkRedundancy(str)<<endl;
  
    return 0;
}