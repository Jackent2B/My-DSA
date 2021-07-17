//Logic: An efficient solution is to use heap data structure. The time complexity of heap based solution is O(N Log k).
// 1. Create an output array. 
// 2. Create a min heap of size k and insert 1st element of all the arrays into the heap 
// 3. Repeat following steps while priority queue is not empty. 
// …..a) Remove minimum element from heap (minimum is always at root) and store it in output array. 
// …..b) Insert next element from the array from which the element is extracted. If the array doesn’t have any more elements, then do nothing.

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int> > ppi;

vector<int> mergeKArrays(vector<vector<int> > arr)
{
    vector<int> output;

    priority_queue<ppi, vector<ppi>, greater<ppi> > pq;
 
    for (int i = 0; i < arr.size(); i++)
        pq.push({ arr[i][0], { i, 0 } });
 
    while (pq.empty() == false) {
        ppi curr = pq.top();
        pq.pop();
 
        // i ==> Array Number
        // j ==> Index in the array number
        int i = curr.second.first;
        int j = curr.second.second;
 
        output.push_back(curr.first);
 
        // The next element belongs to same array as
        // current.
        if (j + 1 < arr[i].size())
            pq.push({ arr[i][j + 1], { i, j + 1 } });
    }
 
    return output;
}
 
int main()
{
    vector<vector<int> > arr{ { 2, 6, 12 },
                              { 1, 9 },
                              { 23, 34, 90, 2000 } };
 
    vector<int> output = mergeKArrays(arr);
 
    cout << "Merged array is " << endl;
    for (auto x : output)
        cout << x << " ";
 
    return 0;
}