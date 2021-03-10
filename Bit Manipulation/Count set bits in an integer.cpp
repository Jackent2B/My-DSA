#include <bits/stdc++.h>
using namespace std;

unsigned int count_set_bits(int n)
{
    unsigned int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}

int main(){
	int x = 7;
	cout<<count_set_bits(x);
	return 0;
}