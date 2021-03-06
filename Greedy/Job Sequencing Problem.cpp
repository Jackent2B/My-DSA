#include <bits/stdc++.h>
using namespace std;

// algo: sort accoring to max profit
/*Intution is that we tend to performe each job at the last day of deadline 
(same as we generally do with our tasks hahahaha)
*/


struct Job
{
   char id;     // Job Id
   int dead;    // Deadline of job
   int profit;  // Profit if job is over before or on deadline
};
 
bool comparison(Job a, Job b)
{
     return (a.profit > b.profit);
}
 
void printJobScheduling(Job arr[], int n)
{
    sort(arr, arr+n, comparison);
 
    int result[n]; // To store result (Sequence of jobs)
    bool slot[n];  // To keep track of free time slots
 
    // Initialize all slots to be free
    for (int i=0; i<n; i++)
        slot[i] = false;

     int countJobs = 0;
     int maxProfit = 0;
 
    // Iterate through all given jobs
    for (int i=0; i<n; i++)
    {
       // Find a free slot for this job (Note that we start
       // from the last possible slot)
       for (int j=arr[i].dead; j>=0; j--)
       {
          // Free slot found
          if (slot[j]==false)
          {
             result[j] = i;  // Add this job to result
             slot[j] = true; // Make this slot occupied
             maxProfit = maxProfit + arr[i].profit;
             countJobs++;
             break;
          }
       }
    }
 
    for (int i=0; i<n; i++){
      if (slot[i])
         cout << arr[result[i]].id << " ";
    }
}
 
int main()
{
    Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
                   {'d', 1, 25}, {'e', 3, 15}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Following is maximum profit sequence of jobs \n";
    printJobScheduling(arr, n);
    return 0;
}