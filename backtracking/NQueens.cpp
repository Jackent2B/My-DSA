#include <bits/stdc++.h>
using namespace std;
#define N 4
  
void print(int board[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout<<board[i][j];
       cout<<endl;
    }
}
  
bool solveNQ(int board[N][N], int row, int cols[], int normal_dagonal[], int reverse_diagonal[]){
	
	if(row == N) 
		return true;

	for(int col = 0; col<N; col++){
		
		if(cols[col]== 0 && normal_dagonal[row+col] == 0 && reverse_diagonal[row-col + N -1] == 0){

			board[row][col] = 1;
			cols[col] = 1;
			normal_dagonal[row+col] = 1;
			reverse_diagonal[row-col+N-1] = 1;
			if(solveNQ(board,row+1,cols,normal_dagonal, reverse_diagonal))
			    return true;
			board[row][col] = 0; //Backtrack
			cols[col] = 0; //Backtrack
			normal_dagonal[row+col] = 0; //BackTrack
			reverse_diagonal[row-col+N-1] = 0; //BackTrack
		
		}
	}
	return false;	
}
  

int main()
{
    int board[N][N] = { { 0, 0, 0, 0 },
                    	{ 0, 0, 0, 0 },
                    	{ 0, 0, 0, 0 },
                    	{ 0, 0, 0, 0 } };
    
    // Visted column
    int cols[N] = {0};
    // Visited normal_diagonal
    int normal_dagonal[2*N-1] = {0};
    // Visited reverse_diagonal
    int reverse_diagonal[2*N-1] = {0};

    if(solveNQ(board,0,cols, normal_dagonal, reverse_diagonal));
   	    print(board);
    return 0;
}