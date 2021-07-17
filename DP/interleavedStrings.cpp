#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

//Method 1: recursive
bool interLeavedStrings(string s1, string s2, string s3, int i, int j){

	if(i == s1.length() && j == s2.length()){
    		return true;
    	}
    if(i<s1.length() && s1[i] == s3[i+j]){
    	bool f1 = interLeavedStrings(s1, s2,s3,i+1,j);
    	if(f1) return true;
    }
    if(j<s2.length() && s2[j] == s3[i+j]){
    	bool f2 = interLeavedStrings(s1, s2,s3,i,j+1);
    	if(f2) return true;
    }
    return false;
}

// Method 2 : Memoized
bool interLeavedStrings(string s1, string s2, string s3, int i, int j){

	if(i == s1.length()-1 && j == s2.length()-1){
		return true;
	}
	if(dp[i][j] != -1){
		return dp[i][j];
	}
	int a=0;
	int b=0;
	if(i<s1.length() && s1[i] == s3[i+j]){
		a=interLeavedStrings(s1, s2,s3,i+1,j); 
	}
	if(j<s2.length() && s2[j] == s3[i+j]){
		b= interLeavedStrings(s1, s2,s3,i,j+1);	
	}
	return dp[i][j] = a || b;
}

int main(){
	memset(dp, -1, sizeof(dp));
	string s1 = "XY";
	string s2 = "X";
	string s3 = "XXY";
	int l = s1.length();
	int m = s2.length();
	int n = s3.length();
	if(l + m != n)
		cout<<"No";
	else if(interLeavedStrings(s1, s2,s3,0,0))
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}