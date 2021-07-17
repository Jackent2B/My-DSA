#include <bits/stdc++.h>
using namespace std;

//Refernce : Pepcodings

int ans(string s, int n){

	if(n==0)
		return 0;

	//convert 1 to -1 and,
	//convert 0 to 1
	//Now apply kadane's algorithm
	int cursum  = 0;
	int maxsum = INT_MIN;

	for(int i = 0; i<n; i++){
		if(s[i] == '1'){
			cursum = max(cursum + -1, -1);
			maxsum = max(maxsum,cursum);			
		}
		else if(s[i] == '0'){
			cursum = max(cursum + 1, 1);
			maxsum = max(maxsum,cursum);		
		}

	}
	return maxsum;
}

int main(){
	string s = "11000010001";
	int n = s.length();
	cout<<ans(s,n);
	return 0;
}