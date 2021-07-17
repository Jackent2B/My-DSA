#include <bits/stdc++.h>
using namespace std;

long long int paintFence(int n, int k){
        if(n==1){
            return k;
        }
    
    	long long int same_color = k * 1;
    	long long int diff_color = k * (k-1);
    	long long int total = same_color + diff_color;
    
    	for (int i = 3; i<=n; ++i)
    	{
    		same_color = diff_color * 1;
    		diff_color = total * (k-1);
    		total = (same_color + diff_color) % 1000000007;
    	}
    	return total;
}

int main(){
	return 0;
	int n = 3;
	int k = 2;
	cout<<paintFence(n,k);
}