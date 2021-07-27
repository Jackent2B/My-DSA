#include <bits/stdc++.h>
using namespace std;

// reference: take u forward

void powerset(string s){
	int n = s.length();
	// 1 << n == pow(2,n)
	for(int num = 0; num < (1<<n); num++){
		
		string temp = "";
		for(int i=0; i<n; i++){
			// checking is the bit is set or not
			if(num & (1<<i)) 
				temp = temp + s[i];
		}
		cout<<temp<<" ";
	}
}

int main(){
	string s = "abc";
	powerset(s);
	return 0;
}