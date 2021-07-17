#include <bits/stdc++.h>
using namespace std;

// Algorithm:
// The value of C(n, k) can be recursively calculated using 
// the following standard formula for Binomial Coefficients :
// C(n, k) = C(n-1, k-1) + C(n-1, k)
// C(n, 0) = C(n, n) = 1

int t[1001][801];

// Returns value of Binomial Coefficient C(n, k)
int binomialCoeff(int n, int k)
{
    // Base Cases
    if (k > n)
        return 0;
    else if (k == 0 || k == n)
        return 1;
    else if(t[n][k] != -1)
        return t[n][k];
    // Recur
    return t[n][k] =  (binomialCoeff(n - 1, k - 1) + binomialCoeff(n - 1, k))%1000000007;
}
 
/* Driver code*/
int main()
{
    memset(t,-1,sizeof(t));
    int n = 5, k = 2;
    cout << binomialCoeff(n, k);
    return 0;
}