#include <bits/stdc++.h>
using namespace std;

int stockcount(int price[],int k, int n){

	// vector <price,index+1>
	vector<pair<int,int>> v;

	for (int i = 0; i < n; i++)
		v.push_back({price[i],i+1});

	sort(v.begin(), v.end());
	
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = ans + min(v[i].second, k / v[i].first);
        k = k - v[i].first * min(v[i].second, (k / v[i].first));
    }
 
    return ans;
}

int main(){
	int price[] = { 7, 10, 4 }; 
    int n = sizeof(price)/sizeof(price[0]);
    int k = 100;
    cout<<stockcount(price,k,n);
	return 0;
}