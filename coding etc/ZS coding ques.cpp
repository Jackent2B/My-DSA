#include<bits/stdc++.h>
using namespace std;

long long Solve (int N, vector<int> task) {
   // Write your code here
   sort(task.begin(), task.end());
   vector <int> v1;
   vector <int> v2;

   v1.push_back(task[0]);
   for(int i = 1; i<task.size()-1; i++){
      int prev = task[i] - task[0];
      int next = task[task.size()-1] - task[i];
      if(prev<next) v1.push_back(task[i]);
      else v2.push_back(task[i]);
   }
   v2.push_back(task[task.size()-1]);

   int mid1 = v1.size()/2;
   long long ans1 = 0;
   for(int i = 0; i<v1.size(); i++){
      if(v1[i]<=task[mid1])   
         ans1 = ans1 + (task[mid1] - v1[i]);
      else
         ans1 = ans1 + (v1[i] - task[mid1]);
   }

   int mid2 = v2.size()/2;
   long long ans2 = 0;
   for(int i = 0; i<v2.size(); i++){
      if(v2[i]<=task[mid2])   
         ans2 = ans2 + (task[mid2] - v2[i]);
      else
         ans2 = ans2 + (v2[i] - task[mid2]);
   }
   return ans1 + ans2;
}