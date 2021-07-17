#include <bits/stdc++.h>
using namespace std;

// Lets make an array of size 5
int arr[5];
int n = 5;
int front;
int rear;
int count = 0;

void push(int x){
	if(count == n){
		cout<<"Queue Overflow"<<endl;
		return;
	}
	rear = rear%n;
	arr[rear] = x;
	rear++;
	count++;
	return;
}

void pop(){
	if(count == 0){
		cout<<"ERROR: Queue is Empty"<<endl;
		return;
	}
	arr[front%n] = INT_MIN; //any dummy number;
	front++;
	count--;
}

int front(){
	if(count != 0)
		return arr[front%n];
	else{
		cout<<"ERROR: Queue is Empty"<<endl;
	}
}

int size(){
	return count;
}

bool isEmpty(){
	return count == 0;
}

int main(){
	front = 0;
	rear = 0;
	push(1);
	push(4);
	push(5);
	int x = front();
	pop();
	int sz = size();
	bool empty_or_not = isEmpty();
	while(!isEmpty()){
	    cout<<front()<<" ";
	    pop();
	}
	
	
	return 0;
}