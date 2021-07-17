#include <bits/stdc++.h>
using namespace std;

void allSubsequences(string ip, string op){

	if(ip.length() == 0){
		cout<<op;
		return;
	}

	string op1 = op;
	string op2 = op;
	op2.push_back(ip[0]);
	ip.erase(ip.begin()+0);
	allSubsequences(ip,op1);
	allSubsequences(ip,op2);
	return;
}

int main(){
	string ip = "abc";
	string op=" ";
	allSubsequences(ip,op); 
	return 0;
}