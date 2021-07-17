#include <bits/stdc++.h>
using namespace std;

int LCSubstr(string a,string b, int m, int n)
{
    int LCSuff[m + 1][n + 1];
    int result = 0; // To store length of the
                    // longest common substring
 
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;
 
            else if (a[i - 1] == b[j - 1]) {
                LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
                result = max(result, LCSuff[i][j]);
            }
            else
                LCSuff[i][j] = 0;
        }
    }
    return result;
}
 

int main(){

	int t;
	cin>>t;
	while(t--){
		string a;
		string b;
		cin>>a;
		cin>>b;
		int m = a.length();
		int n = b.length();
		int lcs = LCSubstr(a,b,m,n);
		// cout <<lcs;
		int ans = m-lcs + n-lcs; 
		cout<<ans<<endl;
	}

	return 0;
}