#include <bits/stdc++.h>
using namespace std;

void solve(int k, string output){
	if(k==0){
		cout<<output<<" ";
		return;
	}

	string op1 = output;
	string op2 = output;

	int n = output.length();
	if(n==0){
		op1.push_back('0');
		op2.push_back('1');
		solve(k-1,op1);
		solve(k-1,op2);
	}
	else{
		if(output[n-1]=='0'){
			op1.push_back('0');
			op2.push_back('1');
			solve(k-1,op1);
			solve(k-1,op2);		
		}
		else{
			output.push_back('0');
			solve(k-1,output);
		}
	}
	return;
}

int main(){
	int k;
	cin>>k;
	string output;
	solve(k,output);
	return 0;
}