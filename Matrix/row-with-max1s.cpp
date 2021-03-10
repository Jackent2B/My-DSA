#include <bits/stdc++.h>
using namespace std;

//method 1	: using only one while loop (better)
int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	// code here
	int c = 0;
	int r = 0;
    while(r<n && c<m )
    {
        if(arr[r][c]==1) //if arr[r][c] then return row number. (as rows are sorted so if we encounter a '1' then all the elements after this '1'  will also be '1' as all rows are sorted) 
            return r;
        else
        { 
	      	r++;
	      	if((r)%n==0) // if r reaches to end(i.e last row) it means we haven't found any row woth max no. of '1' , so we starts again from row '0' and increases the column number. 
	      	{
	      	    c++;
	      	    r=0;
	      	}
	    }
	}
	return -1;
}

//method 2 : using two while loop
int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	// code here
	int c = 0;
	int r = 0;
	while(c<m)
	{
		while(r<n && c<m )
		{
		    if(arr[r][c]==1)
		        return r;
		    else
		        r++;
		}
	c++;
	r=0;
    }	    
    return -1;
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> arr;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin>arr[i][j];
		}
	}

	rowWithMax1s(arr,n,m);

	return 0;
}