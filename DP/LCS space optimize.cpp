#include<bits/stdc++.h>
using namespace std;
  
int lcs(string &X, string &Y)
{
      
    // Find lengths of two strings
    int m = X.length(), n = Y.length();
  
    int L[2][n + 1];
  
    for (int i = 0; i<m+1; i++)
    {
        for (int j = 0; j<n+1; j++)
        {
            if (i == 0 || j == 0)
                L[i%2][j] = 0;
  
            else if (X[i-1] == Y[j-1])
                // as (i-1)%2 == (i+1)%2
                 L[i%2][j] = L[(i+1)%2][j - 1] + 1;
  
            else
                // (i-i)%2 == (i+1)%2
                L[i%2][j] = max(L[(i+1)%2][j], 
                               L[i%2][j - 1]);
        }
    }
    return L[m%2][n];
}
  
// Driver code
int main()
{
    string X = "ABCDGH";
    string Y = "AEDFHR";
    printf("Length of LCS is %d\n", lcs(X, Y));
  
    return 0;
}