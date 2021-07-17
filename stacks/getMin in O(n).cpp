#include <bits/stdc++.h>
using namespace std;

stack <int> s; //for handling push() ans pop().
stack <int> ss; //for handling getMin().

void push(int a){
	s.push(a);
	if (ss.size()==0 || ss.top()>=a)
		ss.push(a);
	return;
}

int pop(int a){	
	if (s.size()==0)
		return -1;	
	int ans = s.top();
	s.pop();
	if (ans==ss.top())
		ss.pop();
	return ans;
}

int getMin(){
	if (ss.size()==0)
		return -1;
	return ss.top();
}


int main(){

	return 0;
}