//Refer: code library

unordered_map<string,int> mp;
string solve(Node* root){
    if(root == NULL)
        return "$"; // to differ the case of:   2     and    2
                                        //     / \            \                              
                                        //   4   5             4
                                        //                      \
                                        //                       5
    string s = " ";
    //to avoid leaf node in map(becoz min size 2 is given in ques), we are just returning it noy includig in map.
    if(root->left == NULL && root->right == NULL){
        s = to_string(root->data);
        return s;
    }
    s = s + to_string(root->data);
    s = s + solve(root->left);
    s = s + solve(root->right);
    mp[s]++;
    return s;   
}

bool dupSub(Node *root)
{
     //your code here
     mp.clear();
     solve(root);
     for(auto i:mp){
         if(i.second >= 2)
            return true;
     }
     return false;
}