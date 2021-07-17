#include <bits/stdc++.h>
using namespace std;

// Note: ask interviewer Pow(x,n), is the value of n can be negative?
//Pow(x,-n) = 1/Pow(x,n) , use long long to avoid overflow


double pow(double x, int n){
	double ans = 1.0;
	long long nn = n;
	if(n<0) nn = -1 * n;

	while(nn){
		if(nn%2 == 0){
			x = x*x;
			nn = nn/2;
		}
		else{
			ans = ans * x;
			nn = nn-1;
		}
	}
	if(n<0) ans = (double)(1.0)/ (double)(ans);
	return ans;
}

int main(){

	return 0;
}