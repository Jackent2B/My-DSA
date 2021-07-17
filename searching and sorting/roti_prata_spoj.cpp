#include <bits/stdc++.h>
using namespace std;

//logic
int solve(int ranks[], int chef, int para_needed, int mid){
	int paranthas = 0;
	int time = 0;
	for (int i = 0; i < chef; i++)
	{
		time = ranks[i];
		int x = 2;
		while(time<=mid){
			paranthas++;
			time = time + (x*ranks[i]);
			x++;
		}
		if (paranthas>=para_needed)
			return 1;
	}
	return 0;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int para_needed;
		cin>>para_needed;

		int chef;
		cin>>chef;
		
		int ranks[chef];
		for (int i = 0; i < chef; ++i)
			cin>>ranks[i];

		int start = 0;//we have chosen 
		int end = 1e9;//start and end randomly

        int ans; 

        //binary search
		while(start<=end){
			int mid = start + (end-start)/2;
			if(solve(ranks,chef,para_needed,mid)){
				ans = mid;
				end = mid - 1;
			}
			else
				start = mid + 1;
		}
		std::cout << ans << std::endl;

	}
	return 0;
}