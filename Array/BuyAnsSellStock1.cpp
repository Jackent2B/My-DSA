#include <bits/stdc++.h>
using namespace std;

int bestPrice(int stocks[], int n){
	int minimumPrice = INT_MAX;
	int maxProfit = 0; //minimum profit can be zero.

	for (int i = 0; i < n; ++i)
	{
		if(stocks[i]<minimumPrice)
			minimumPrice = stocks[i];
		else{
			maxProfit = max(maxProfit, stocks[i]-minimumPrice);
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