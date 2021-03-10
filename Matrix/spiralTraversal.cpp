#include <bits/stdc++.h>
using namespace std;

vector <int> spiralOrder(vector<vector<int>> vec, int R, int C){
	     
    int top = 0;
	int left = 0;
	int right = C-1;
	int bottom = R-1;

	int flag = 0;
	vector<int> spiral;

	while(left<=right && top<=bottom){

		if(flag==0){
			for (int i = left; i <= right; i++)
			{
				spiral.push_back(vec[top][i]);
			}
			top++;
		}
		else if(flag==1){
			for (int i = top; i <= bottom; i++)
			{
				spiral.push_back(vec[i][right]);
			}	
			right--;
		}
		else if(flag==2){
			for (int i = right; i >=left; i--)
			{
				spiral.push_back(vec[bottom][i]);
			}	
			bottom--;
		}
		else if(flag==3){
			for (int i = bottom; i>=top; i--)
			{
				spiral.push_back(vec[i][left]);
			}
			left++;
		}
		flag=(flag+1)%4;
	}
	return spiral;
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
	vector <int> spiral_matrix =  spiralOrder(vec,R,C);

	//print matrix
	for (int i = ; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout<<vec[i][j];
		}
	}

	return 0;
}