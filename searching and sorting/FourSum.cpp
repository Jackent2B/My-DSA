#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> getAnswer(int arr[], int n, int target){

	vector<vector<int>> ans;

	if(n==0)
		return ans;

	sort(arr,arr+n);

	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			int target_remaining = target - arr[i] - arr[j];
			
			int front = j+1;
			int last = n-1;

			while(front < last){
				int sum_2 = arr[front] + arr[last]; 
				
				if(sum_2 < target_remaining)
					front++;
				else if(sum_2 > target_remaining)
					last--;
				else{

					vector<int> quadraple(4,0);
				
					quadraple[0] = arr[i];
					quadraple[1] = arr[j];
					quadraple[2] = arr[front];
					quadraple[3] = arr[last];
				
					ans.push_back(quadraple);	

					while(front<last && arr[front] == quadraple[2])
						front++;
					
					while(front<last && arr[front] == quadraple[3])
						last--;
				
				}

			}

			while((j+1<n) && (arr[j+1] == arr[j]))
				j++;

		 }
		while((i+1<n) && (arr[i+1] == arr[i]))
			i++;
	}
	return ans;
}


int main(){
	int arr[] = {10,2,3,4,5,7,8};
	int n = sizeof(arr)/sizeof(arr[0]);
	int target = 3;

	vector<vector<int>> v = getAnswer(arr,n,target);
	for(int i = 0; i<v.size(); i++){
	    for(int j = 0; j<v[0].size(); j++){
	       cout<<v[i][j]; 
	    }
	}

	return 0;
}