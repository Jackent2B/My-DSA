#include <bits/stdc++.h>
using namespace std;

int is_set(int xor_result,int i){
	if((xor_result & (1<<(i-1)))>0)
		return 1;
	else
		return 0;
}

vector<int> get_single_numbers(vector<int> v){

	int size = v.size();

	int xor_result = 0;
	for (int i = 0; i < size; ++i)
		xor_result = xor_result ^ v[i];

	//finding the first set bit of 6;
	int first_setbit = -1;
	for (int i = 0; i < 32; ++i)
	{
		if(is_set(xor_result,i)){
			first_setbit = i;
			break;
		}
	}

	int a = 0;
	int b = 0;

	for (int i = 0; i < size; ++i)
	{
		if(is_set(v[i],first_setbit))
			a = v[i] ^ a;
		else
			b = v[i] ^ b;
	}
	
	//answer vector
	vector<int> ans;
	ans.push_back(a);
	ans.push_back(b);
	return ans;
}

int main(){
	
	vector<int> v;	
	int n;
	cin>>n;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin>>num;
		v.push_back(num);
	}

	vector<int> result = get_single_numbers(v);

	for (int i = 0; i < result.size(); ++i)
		cout<<result[i]<<" ";
	
	return 0;
}