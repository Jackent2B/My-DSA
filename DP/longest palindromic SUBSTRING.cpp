#include <bits/stdc++.h>
using namespace std;


int LPSubStr(string s1, string s2, int m, int n){
	
    int arr[m+1][n+1];
    int ans =0;
    for(int i=0; i<m+1; i++){
        for(int j =0; j<n+1; j++){
            if(i == 0 || j == 0)
        		arr[i][j]= 0;
        	else if(s1[i-1] == s2[j-1]){
        		arr[i][j] = 1 + arr[i-1][j-1];
        		ans = max(ans,arr[i][j]);
        	}
        	else
        		arr[i][j] = 0;       
        }
    }
    return ans;
}

int main(){
	string s1 = "GEEKSFORGEEKS";
	int m = s1.length();
	string s2 = s1;
	reverse(s2.begin(),s2.end());
	int n = s2.length();
	cout<<LPSubStr(s1,s2,m,n);
	return 0;
}