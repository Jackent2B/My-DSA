#include <bits/stdc++.h>
using namespace std;
#define N 9
 
void print(int arr[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}
 
bool isValid(int grid[N][N], int row, int col, int num){
    
    for (int x = 0; x < 9; x++){
        // to check if element is already present in row 
        if (grid[row][x] == num)
            return false;
        // to check if element is already present in col
        if (grid[x][col] == num )
            return false;
   }
 
    //finding the startRow and startCol of sub matrix
    int startRow = (row/3)*3;
    int startCol = (col/3)*3;
   
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (grid[i+startRow][j + startCol] == num)
                return false;
        }
    }
 
    return true;
}
 
bool solveSuduko(int grid[N][N], int i, int j)
{
    if(i == 9)
        return true;
    //ni = next row AND nj = next col
    int ni=0;
    int nj=0;

    if(j==8)
    {
        ni = i+1;
        nj = 0;
    }
    else
    {
        ni = i;
        nj = j+1;
    }

    if(grid[i][j] == 0){
        for(int pos=1; pos<=9; pos++){
            if(isValid(grid, i, j, pos)){
                grid[i][j] = pos;
                if(solveSuduko(grid, ni, nj))
                    return true;
                //cout<<i<<" "<<j<<" "<<pos<<endl;
                else grid[i][j] = 0; //backtrack
            }
        }
    }
    else{
        return solveSuduko(grid,ni,nj);
    }
    return false;
}

int main()
{
    int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

    if(solveSuduko(grid,0,0))
        print(grid);
    //print(grid);
    return 0;
}

