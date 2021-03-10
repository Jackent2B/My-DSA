#include <bits/stdc++.h>
using namespace std;

int bestPrice(int stocks[], int n){
	
	int maxProfit = 0; //minimum profit can be zero.
	for (int i = 0; i < n-1; ++i)
	{
		if(stocks[i+1]>stocks[i]){
			maxProfit = maxProfit + (stocks[i+1]-stocks[i]);
		}
	}
	return maxProfit;

}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int stocks[n];
		for (int i = 0; i < n; ++i)
			cin>>stocks[i];
		bestPrice(stocks,n);
	}
	return 0;
}