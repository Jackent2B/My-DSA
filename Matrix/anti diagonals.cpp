#include <iostream>
using namespace std;
 
// function to print the diagonals
void diagonal(int A[3][3])
{
 
    int N = 3;
 
    // For each column start row is 0
    for (int col = 0; col < N; col++) {
 
        int startcol = col, startrow = 0;
 
        while (startcol >= 0 && startrow < N) {
            cout << A[startrow][startcol] << " ";
 
            startcol--;
 
            startrow++;
        }
        cout << "\n";
    }
 
    // For each row start column is N-1
    for (int row = 1; row < N; row++) {
        int startrow = row, startcol = N - 1;
 
        while (startrow < N && startcol >= 0) {
            cout << A[startrow][startcol] << " ";
 
            startcol--;
 
            startrow++;
        }
        cout << "\n";
    }
}
 
// Driver code
int main()
{
 
    // matrix iniliasation
    int A[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
 
    diagonal(A);
 
    return 0;
}