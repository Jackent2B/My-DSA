#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
bool interleaving(string a, string b, string c, int i, int j){

	if(i == a.length() && j == b.length())
		return true;
	
	if(dp[i][j]!=-1)
		return dp[i][j];

	// i+j = k (index pointing to c string)         
	if(i<a.length() && a[i] == c [i+j]){
		bool temp1 = interleaving(a, b, c, i+1, j);
		dp[i][j] = temp1;
		if(temp1) return dp[i][j] = true;
	}

	// i+j = k (index pointing to c string)         
	if(j<b.length() && b[j] == c [i+j]){
		bool temp2 = interleaving(a, b, c, i, j+1);
		dp[i][j] = temp2;
		if(temp2) return true;
	}
	
	return dp[i][j] = false;
}

int main(){
	string a = "yx";
	string b = "x";
	string c = "xxy";
	memset(dp, -1; sizeof(dp));
	int x = a.length();
	int y = b.length();
	int z = c.length();

	if(x + y != z)
		cout<<"Not interleaving"<<endl;
	else
		interleaving(a,b,c,0,0);
	return 0;
}