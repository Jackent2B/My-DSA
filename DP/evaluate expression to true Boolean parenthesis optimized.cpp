#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> mp;

int solve_ans(string s, int i, int j, bool isTrue){
	if(i>j)
		return false;
	if(i==j){
		if(isTrue)
			return s[i]=='T';
		else
			return s[i]=='F';
	}

	// we are using map insted of 3D matrix to store the already computed value
	string temp = to_string(i);
	temp.push_back(' ');
	temp.append(to_string(j));
	temp.push_back(' ');
	temp.append(to_string(isTrue));

	if(mp.find(temp) != mp.end())
		return mp[temp];

	int ans = 0;
	for (int k = i+1; k <= j-1; k=k+2)
	{
		int lt = solve_ans(s,i,k-1,true);
		int lf = solve_ans(s,i,k-1,false);
		int rt = solve_ans(s,k+1,j,true);
		int rf = solve_ans(s,k+1,j,false);	

		if(s[k]=='&'){
			if(isTrue)
				ans = ans + (lt*rt);
			else
				ans = ans + (lf*rf) + (lf*rt) + (lt*rf);
		}
		else if(s[k]=='^'){
			if(isTrue)
				ans = ans + (lt*rf) + (lf*rt);
			else
				ans = ans + (lt*rt) + (lf*rf);	
		}
		else if(s[k]=='|'){
			if(isTrue)
				ans = ans + (rt*lt) + (lt*rf) + (lf*rt);
			else
				ans = ans + (lf*rf);	
		}
	}
    return mp[temp] = ans;
}

int solve(string s){
	int n = s.length();
	return solve_ans(s,0,n-1,true);
}

int main(){
	mp.clear();
	string s = "T|F";
	cout<<solve(s);
	return 0;
}
