#include <bits/stdc++.h>
using namespace std;

// Lets make an array of size 5
int arr[5];
int tp;

void push(int x){
	if(tp == 4){
		cout<<"Stack Overflow"<<endl;
		return;
	}
	tp = tp + 1;
	arr[tp] = x;
	return;
}

void pop(){
	if(tp != -1)
		tp = tp - 1;
	else{
		cout<<"ERROR: Stack is Empty"<<endl;
	}
}

int top(){
	if(tp != -1)
		return arr[tp];
	else{
		cout<<"ERROR: Stack is Empty"<<endl;
	}
}

int size(){
	return tp+1;
}

bool isEmpty(){
	return tp == -1;
}

int main(){
	tp = -1;
	push(1);
	push(4);
	push(5);
	int x = top();
	pop();
	int sz = size();
	bool empty_or_not = isEmpty();
	while(!isEmpty()){
	    cout<<top()<<" ";
	    pop();
	}
	
	
	return 0;
}