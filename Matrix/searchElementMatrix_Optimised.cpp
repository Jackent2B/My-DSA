#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& vec, int target){
            
    //if the element is less than the first element i.e. vec[0][0], then the element is not         present
	if(target<vec[0][0])
		return false;

	int r = 0;
	int row = vec.size();

	//to find the first row (i.e 'r') whose element is greater than the target
	while(r < row){
        if(vec[r][0] <= target)
            r++;
        else break;
    }

    int c = vec[0].size(); 
    for (int x = 0; x < c; x++)
    {
    	//'r-1' is the row in which the target should be present
    	if(vec[r-1][x] == target)
    		return true;
    }
    return false;
}

int main(){
	int R = 3;
	int C = 4;  
	vector<vector<int>> vec;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin>>vec[i][j];
		}
	}
	int target;
	cin>>target;
	if(Searchtarget(vec,target))
		cout<<"true";
	else
		cout<<"false";
	return 0;
}