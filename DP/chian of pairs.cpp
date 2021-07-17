#include <bits/stdc++.h>
using namespace std;

int ChainOfPairs(vector<vector> &A){
	int n = A.size();
    int output[n+1];
    output[0] = 1;
    
    for(int i=1; i<n; i++){
        output[i] = 1;
        for(int j=0; j<i; j++ ){
            if(A[j][1] < A[i][0])   
                output[i] = max(1+output[j],output[i]);
        }
    }
    
    int ans = INT_MIN;
    for(int i=0; i<n; i++){
        ans = max(ans,output[i]);
    }
    return ans;
}

int main(){
	
	int n;
	cin>>n;
	vector<vector<int>> A;
	for (int i = 0; i < n; ++i)
	{
		vector<int> temp;
		for (int i = 0; i < 2; ++i)
		{
			int num;
			cin>>num;
			temp.push_back(num);
		}
		A.push_back(temp);
	}
	cout<<ChainOfPairs(A);
	return 0;
}