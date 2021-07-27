#include <bits/stdc++.h>
using namespace std;

stack<int> st;

void insertAtBottom(int data){
	if(st.size()==0)
		st.push(data);
	else{
		int a = st.top();
		st.pop();
		insertAtBottom(data);
		st.push(a);
	}
}

void reverse(){
	if(st.size()==0){
		return;
	}
	int x = st.top();
	st.pop();
	reverse();
	insertAtBottom(x);
}

int main(){
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);

	reverse();
	cout<<"Reversed stack : "<<" ";
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
	return 0;
}
