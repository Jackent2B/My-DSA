#include <bits/stdc++.h>
using namespace std;

bool interleaving(string a, string b, string c, int i, int j){

	if(i == a.length() && j == b.length())
		return true;

	// i+j = k (index pointing to c string)         
	if(i<a.length() && a[i] == c [i+j]){
		bool temp1 = interleaving(a, b, c, i+1, j);
		if(temp1) return true;
	}

	// i+j = k (index pointing to c string)         
	if(j<b.length() && b[j] == c [i+j]){
		bool temp1 = interleaving(a, b, c, i, j+1);
		if(temp2) return true;
	}
	
	return false;
}

int main(){
	string a = "yx";
	string b = "x";
	string c = "xxy";

	int x = a.length();
	int y = b.length();
	int z = c.length();

	if(x + y != z)
		cout<<"Not interleaving"<<endl;
	else
		interleaving(a,b,c,0,0);
	return 0;
}