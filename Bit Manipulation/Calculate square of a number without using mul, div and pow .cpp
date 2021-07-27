 /*Algorihtm:
If n is even, it can be written as
  n = 2*x 
  n2 = (2*x)2 = 4*x2
If n is odd, it can be written as 
  n = 2*x + 1
  n2 = (2*x + 1)2 = 4*x2 + 4*x + 1
*/

#include <bits/stdc++.h>
using namespace std;

int square(int n){
	if(n<0)
		n = -1*n;

    // Get n/2 using right shift
	int x = n>>1;

	// If n is even
	if((n & 1) == 0){
		return square(x) << 2;
	}
	// If n is odd
	else{
		return ((square(x) << 2) + (square(x) << 1) + 1); 
	}
}

int main(){
	int n = 5;
	cout<<square(n)<<endl;
	return 0;
}