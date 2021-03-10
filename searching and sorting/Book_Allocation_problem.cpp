#include <bits/stdc++.h>
using namespace std;

int solve(int books, int pages[],int students,int mid){

	int student_needed = 1;
	int pages_capacity = 0;
	for (int i = 0; i < books; ++i)
	{
	    if(pages[i]>mid)
	        return 0;
	    
		pages_capacity = pages_capacity + pages[i];
		if(pages_capacity>mid){
			pages_capacity = 0 + pages[i];
			student_needed++;

			if(student_needed > students)
				return 0;
		}
	}
	return 1;}

int main(){
	int books;
	cin>>books;

	int students;
	cin>>students;

	int pages[books];
	for (int i = 0; i < books; ++i)
		cin>>pages[i];

	int total_pages = 0;
	for (int i = 0; i < books; ++i)
		total_pages = total_pages + pages[i];

	//binary search
	int start = 0;
	int end = total_pages;
    int ans;
	while(start<=end){
		int mid = start + (end - start)/2;
		if(solve(books,pages,students,mid)){
			ans = mid;
			end = mid-1;
		}
		else
			start = mid + 1;
	}
	cout<<ans;

	return 0;
}