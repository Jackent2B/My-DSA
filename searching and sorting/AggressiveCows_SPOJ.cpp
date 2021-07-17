#include <bits/stdc++.h>
using namespace std;


int solve(int barnsCount, int barns[], int cows, int mid){

	int prev = barns[0];
	int cows_needed = 1; // cows placed till now 
	for (int i = 1; i < barnsCount; ++i)
	{
		if((barns[i] - prev) >= mid){
		    cows_needed++;
		    prev = barns[i];
				
			if(cows_needed == cows)
			return 1;
		}
	}
	return 0;
}


int main(){
	
	int t;
	cin>>t;

	while(t--){
		int barnsCount;
		cin>>barnsCount;

		int cows;
		cin>>cows;

		int barns[barnsCount];
		for (int i = 0; i < barnsCount; ++i)
			cin>>barns[i];

		//binary search
		int start = 0; //it can start from 1 as well(better) beacacuse minimum 
					   // distance between two stalls can be 1 (not lesser than that)
		int end = 1e9;
		int ans;
		
		// Importatnt to sort the barns
		sort(barns , barns + barnsCount);
		while(start<=end){
			
			int mid = start + (end - start)/2;

			if(solve(barnsCount, barns, cows, mid)){
				ans = mid;
				start = mid + 1;
			}
			else
				end = mid - 1;

		}
		cout<<ans<<endl;
	}
	return 0;
}