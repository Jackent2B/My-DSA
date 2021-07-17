#include <bits/stdc++.h>
using namespace std;

vector<int> removeDuplicates(vector<int> &vec){

	int i = 0;
	for (int j = 0; j < count; ++j)
	{
		/* code */
		if(vec.size() == 0)
			return 0;
		if(vec[i] != vec[j]){
			i++;
			vec[i] = vec[j];
		}
	}
	return i+1;
}

int main(){
	vector<int> vec = {1,1,2,2,2,3,3};
	vector<int> ans = removeDuplicates(vec);
	return 0;
}