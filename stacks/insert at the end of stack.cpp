#include <bits/stdc++.h>
using namespace std;

stack<int> st;

void insertAtBottom(int data){
	if(st.size()==0){
		st.push(data);
	}
	else{
		int x = st.top();
		st.pop();
		insertAtBottom(data);
		st.push(x);
	}
}

int main(){
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	insertAtBottom(6);
	while(!st.empty()){
	    cout<<st.top()<<" ";
	    st.pop();
	}
	return 0;
}

