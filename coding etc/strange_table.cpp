#include <bits/stdc++.h>
using namespace std;

long long int solve(long long int n,long long int m,long long int x){
	
	long long int row,col;
    x--;
    col = x / n;
    row = x % n;
   	return row * m + col + 1;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		long long int n,m,x;
		cin>>n>>m>>x;
		cout<<solve(n,m,x)<<"\n";
	}
	return 0;
}