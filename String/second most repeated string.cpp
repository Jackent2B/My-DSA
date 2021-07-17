#include <bits/stdc++.h>
using namespace std;

string secondMostRepeated(string arr[], int n){

	unordered_map<string,int> mp;    
    
    for(int i=0; i<n; i++){
        mp[arr[i]]++;
    }
        

    int first_max = INT_MIN, sec_max = INT_MIN;
    
    for (auto i = mp.begin(); i != mp.end(); i++) {
        
        if (i->second > first_max) {
            sec_max = first_max;
            first_max = i->second;
        }
        else if (i->second > sec_max && i->second != first_max)
            sec_max = i->second;
    }
  
    // Return string with occurrence equals
    // to sec_max
    for (auto it = mp.begin(); it != mp.end(); it++){
        if (it->second == sec_max)
            return it->first;
    }
}

int main(){
	string arr[] = {aaa, bbb, ccc, bbb, aaa, aaa};
	int  n = 6;
	cout<<secondMostRepeated(arr,n);
	return 0;
}