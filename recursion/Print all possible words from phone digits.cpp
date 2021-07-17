#include <bits/stdc++.h>
using namespace std;

unordered_map<char, string> mp;
void strings_corresponding_to_numbers(){
	mp['0']=" ";
	mp['1']=" ";
	mp['2']="abc";
	mp['3']="def";
	mp['4']="ghi";
	mp['5']="jkl";
	mp['6']="mno";
	mp['7']="pqrs";
	mp['8']="tuv";
	mp['9']="wxyz";
	return;
}

void solve(string op, string number){
	if(number.length()==0){
		cout<<op<<" ";
		return;
	}

	if(number[0] == '0' || number[0] == '1' ){
	    number.erase(number.begin()+0);
    	return solve(op,number);
	}

	string op1 = op;
	string op2 = op;
	string op3 = op;
	
	op1.push_back(mp[number[0]][0]);
	op2.push_back(mp[number[0]][1]);
	op3.push_back(mp[number[0]][2]);
	

    string op4;
	if(number[0] == '7' || number[0] == '9' )
	{
		op4 = op;
		op4.push_back(mp[number[0]][3]);
	}  

	number.erase(number.begin()+0);
    solve(op1,number);
    solve(op2,number);
    solve(op3,number);	
    if(number[0] == '7' || number[0] == '9' ){
    	solve(op4,number);
    }
	return;
}

int main(){
	strings_corresponding_to_numbers();
	string number = "034";
	int n = number.length();
	string op = " ";
	solve(op,number);
	return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// unordered_map<char, string> mp;
// void strings_corresponding_to_numbers(){
// 	mp['0']=" ";
// 	mp['1']=" ";
// 	mp['2']="abc";
// 	mp['3']="def";
// 	mp['4']="ghi";
// 	mp['5']="jkl";
// 	mp['6']="mno";
// 	mp['7']="pqrs";
// 	mp['8']="tuv";
// 	mp['9']="wxyz";
// 	return;
// }

// void solve(string op, string number){
// 	if(number.length()==0){
// 		cout<<op<<" ";
// 		return;
// 	}

// 	if(number[0] == '0' || number[0] == '1' ){
// 	    number.erase(number.begin()+0);
//     	solve(op,number);
// 	}

// 	else if(number[0] == '7' || number[0] == '9' )
// 	{
// 		string op1 = op;
// 		string op2 = op;
// 		string op3 = op;
// 		string op4 = op;
		
// 		op1.push_back(mp[number[0]][0]);
// 		op2.push_back(mp[number[0]][1]);
// 		op3.push_back(mp[number[0]][2]);
// 		op4.push_back(mp[number[0]][3]);
		
// 		number.erase(number.begin()+0);
//     	solve(op1,number);
//     	solve(op2,number);
//     	solve(op3,number);
//     	solve(op4,number);
    	
// 	}
// 	else
// 	{
// 		string op1 = op;
// 		string op2 = op;
// 		string op3 = op;
		
// 		op1.push_back(mp[number[0]][0]);
// 		op2.push_back(mp[number[0]][1]);
// 		op3.push_back(mp[number[0]][2]);
		
//     	number.erase(number.begin()+0);
//     	solve(op1,number);
//     	solve(op2,number);
//     	solve(op3,number);
// 	}  

// 	return;
// }

// int main(){
// 	strings_corresponding_to_numbers();
// 	string number = "034";
// 	int n = number.length();
// 	string op = " ";
// 	solve(op,number);
// 	return 0;
// }