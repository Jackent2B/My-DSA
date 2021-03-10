#include <iostream>
using namespace std;
 
// A structure to store an element and its current count
struct eleCount {
    int e; // Element
    int c; // Count
};

void moreThanNdK(int arr[], int n, int k)
{
    // k must be greater than
    // 1 to get some output
    if (k < 2)
        return;

    struct eleCount temp[k - 1];
    for (int i = 0; i < k - 1; i++)
        temp[i].c = 0;
 
    for (int i = 0; i < n; i++) 
    {
        int j;
        for (j = 0; j < k - 1; j++) 
        {
            if (temp[j].e == arr[i]) 
            {
                temp[j].c += 1;
                break;
            }
        }
 
        if (j == k - 1) {
            int l;
 
            for (l = 0; l < k - 1; l++)
            {
                if (temp[l].c == 0) 
                {
                    temp[l].e = arr[i];
                    temp[l].c = 1;
                    break;
                }
            }
 
            if (l == k - 1)
                for (l = 0; l < k; l++)
                    temp[l].c -= 1;
        }
    }
 
    for (int i = 0; i < k - 1; i++)
    {
        // Calculate actual count of elements
        int ac = 0; // actual count
        for (int j = 0; j < n; j++)
            if (arr[j] == temp[i].e)
                ac++;
 
        // If actual count is more than n/k,
       // then print it
        if (ac > n / k)
            cout << "Number:" << temp[i].e
                 << " Count:" << ac << endl;
    }
}

int main()
{
    cout << "First Test\n";
    int arr1[] = { 4, 5, 6, 7, 8, 4, 4 };
    int size = sizeof(arr1) / sizeof(arr1[0]);
    int k = 3;
    moreThanNdK(arr1, size, k);
     return 0;
}