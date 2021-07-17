#include <bits/stdc++.h>
using namespace std;

int t[1001][1001];

int unboundedKnapsack(int n ,int w, int val[], int wt[]){

	if(n==0 || w==0)
		return 0;
	else if(t[n][w] != -1)
		return t[n][w];
	
	else if(wt[n-1]<= w){
		return t[n][w] = max(val[n-1]+unboundedKnapsack(val,wt,n,w - wt[n-1]),unboundedKnapsack(val,wt,n-1,w));
	}
	else if(wt[n-1]>w)
		return t[n][w] = unboundedKnapsack(val,wt,n-1,w);
}

int main(){
	memset(t,-1,sizeof(t));
	int val[] = {1, 1};
	int wt[] = {2, 1};
    int n = 2;
    int w = 3;
    cout << unboundedKnapsack(n, w, val, wt);
    return 0;
}