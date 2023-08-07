// https://practice.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    private:
    // TC = O(9^m) where m is the number of empty cells
    // SC = O(1)
    bool isValid(int num, int grid[N][N], int row, int col) {
        for(int i = 0; i < N; i++) {
            if(grid[row][i] == num) return false;
        }
        
        for(int i = 0; i < N; i++) {
            if(grid[i][col] == num) return false;
        }
        
        int rr = row - row % 3;
        int cc = col - col % 3;
        
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(grid[rr + i][cc + j] == num) return false;
            }
        }
        
        return true;
    }
    public:
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(grid[i][j] == 0) {
                    for(int k = 1; k <= 9; k++) {
                        if(isValid(k, grid, i, j)) {
                            grid[i][j] = k;
                            bool ans = SolveSudoku(grid);
                            
                            if(ans) return true;
                            else grid[i][j] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cout << grid[i][j] << " ";
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends