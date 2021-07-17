#include <bits/stdc++.h>
using namespace std;

int rotOranges(vector<vector<int>> &vec){
    int n = vec.size();
	int m = vec[0].size();

	queue<pair<int,int>> q;
	int fresh = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(vec[i][j] == 2){
				q.push({i,j});
			}
			else if(vec[i][j] == 1)
				fresh++;
		}
	}

	if(fresh == 0)
		return -1;

	int r[] = { 0, -1, 0, +1};
	int c[] = {+1, 0, -1, 0 };

	int level = -1;
	while(!q.empty()){
		int size = q.size();
		level++;
		while(size--){
			for (int i = 0; i < 4; ++i)
			{
				auto p = q.front();
				int newr = p.first + r[i];
				int newc = p.second + c[i];
				q.pop();
				if( newr>=0 && newc>=0 && newr < vec.size() && newc < vec[0].size() && vec[newr][newc] == 1){
					q.push({newr,newc});
					// So that we don't process it again
					vec[newr][newc]=2; 
					fresh--;
				}
			}
		}
	}

	if(fresh>0)
		return -1;
	else 
		return level; 
}

int main(){
	vector<vector<int>> vec = { {2, 1, 0, 2, 1},
                     			{1, 0, 1, 2, 1},
                     			{1, 0, 0, 2, 1}};
    cout<<rotOranges(vec);
    return 0;
}