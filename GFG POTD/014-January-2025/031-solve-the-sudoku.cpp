// https://www.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    bool isSafeToPlace(vector<vector<int>> &mat, int row, int col, int val) {
        for (int i = 0; i < 9; i ++) {
            // check safety in row, col and 3*3 sub-matrix
            if (mat[row][i] == val || mat[i][col] == val || 
                mat[3 * (row/3) + (i/3)][3 * (col/3) + (i%3)] == val) {
                return false;
            }
        }
        return true;
    }
    
    // TC : O(9^(m * n)) Where m = no. of rows and n = no. of cols
    // SC : O(1)
    bool solve(vector<vector<int>> &mat) {
        for (int i = 0; i < 9; i ++) {
            for (int j = 0; j < 9; j ++) {
                if (mat[i][j] == 0) {
                    
                    for (int val = 1; val <= 9; val ++) {
                        if (isSafeToPlace(mat, i, j, val)) {
                            mat[i][j] = val;
                            
                            if (solve(mat)) 
                                return true;
                            else 
                                mat[i][j] = 0;
                        }
                    }
                    
                    return false;
                }
            }
        }
        
        return true;
    }
  public:
    // Function to find a solved Sudoku.
    void solveSudoku(vector<vector<int>> &mat) {
        solve(mat);
    }
};


//{ Driver Code Starts.
vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<vector<int>> grid;
        for (int i = 0; i < 9; i++) {
            vector<int> v = inputLine();
            grid.push_back(v);
        }

        Solution ob;

        ob.solveSudoku(grid);

        for (auto v : grid) {
            for (auto elem : v) {
                cout << elem << " ";
            }
            cout << endl;
        }

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends