#include <bits/stdc++.h>
using namespace std;

vector<int> max_subarrays_k(int arr[], int n, int k){

	vector<int> ans;
	if(n==0) return ans;

	priority_queue<int> maxh;

	int i = 0;
	int j=0;
	while(j<n){
		//calculation
		if(maxh.size()>0 && maxh.top()<arr[j]){
				maxh = priority_queue <int>(); 
				maxh.push(arr[j]);
			}
			else{
				maxh.push(arr[j]);
		}

		//sliding the window till we achieve the window size of k
		if(j-i+1<k){			
			j++;
		}

		//getting the ans based on calucalation calculations 
		else if(j-i+1 == k){
			ans.push_back(maxh.top());
			if(arr[i]==maxh.top()){
				maxh.pop();
			}
			i++;
			j++;
		}
	}
	return ans; 
}

int main()
{
	int arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    // Size of array
    int n = 9;  
    int k = 3;
    vector <int> ans = max_subarrays_k(arr, n, k);
    for (int i = 0; i < ans.size(); ++i)
    	cout<<ans[i]<<" ";
    return 0;
}