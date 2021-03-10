#include <bits/stdc++.h> 
using namespace std; 
  
int isPowerOfTwo(int n)  
{  
    return n && (!(n & (n - 1)));  
}  
  
int findPosition(int n)  
{  
    if (!isPowerOfTwo(n))  
        return -1;  
    
    for (int i = 1; i < 32; ++i)
      {
          if((n & 1<<(i-1))>0)
            return i;
      }    
}  
  
// Driver code  
int main()  
{  
    int a = 27;
    cout<<findPosition(a)<<endl;

    int b = 16;
    cout<<findPosition(b)<<endl;

    return 0;  
}  