#include <bits/stdc++.h>
using namespace std;

vector<int> nodeToRootPath(Node* root, int num){
	if(root->data == num){
		vector<int> ans;
		ans.push_back(root->data);
		return ans;
	}

	for(auto child: root->children){
		vector<int> ptc = nodeToRootPath(child,num);
		if(ptc.size() > 0){
			ptc.push_back(root->data);
			return ptc;
		}
	}
	return list;
}

int main(){

	return 0;
}