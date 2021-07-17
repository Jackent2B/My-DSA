#include <bits/stdc++.h>
using namespace std;

int maxSubStr(string s, int n){
	int count0 = 0;
	int count1 = 0;
	int cnt = 0;

	for (int i = 0; i < n; ++i)
	{
		if(s[i]=='0')
			count0++;
		else if(s[i]=='1')
			count1++;

		if(count0 == count1)
			cnt;;
	}


	// It is not possible to
    // split the string
    if (count0 != count1) {
        return -1;
    }
  
    return cnt;
}

int main(){
    string str = "0100110101";
    int n = str.length();
    cout << maxSubStr(s, n);
	return 0;
}