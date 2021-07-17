#include <bits/stdc++.h>
using namespace std;

//reference: Pepcoding youtube 
int potentialCelebrity(bool knows[][4], int person){

	stack <int> s;
	for (int i = 0; i < person; ++i)
		s.push(i);

	while(s.size()>1){

		int first = s.top();
		s.pop();
		int second = s.top();
		s.pop();

		if(knows[first][second] == 1){
			//first knows second ==> first is not a celebrity;
			s.push(second);
		}
		else{
			//first don't know second ==> second is not a celebrity;
			s.push(first);
		}
	}

	return s.top();

}

int isCelebrity(bool knows[][4], int potential_candidate, int person){
	
	int ans = potential_candidate;
	for (int i = 0; i < person; ++i)
	{
		if(i != potential_candidate){
			if(knows[potential_candidate][i] == 1 || knows[i][potential_candidate] ==0  ){
				ans = -1;
				return ans;
			}
		}
	}

	return ans;
}


int main(){
	int person = 4;
	//matrix
	bool knows[4][4]= {{0, 0, 1, 0},
			         {0, 0, 1, 0},
			         {0, 0, 0, 0},
			         {0, 0, 1, 0}};


	int potential_candidate = potentialCelebrity(knows,person);
	int actualCelebrity = isCelebrity(knows,potential_candidate, person);
	if(actualCelebrity == -1)
		cout<<"there is no celebrity"<<endl;
	else
		cout<<actualCelebrity<<" is the Celebrity"<<endl;
	return 0;
}