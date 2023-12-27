// https://www.geeksforgeeks.org/problems/print-diagonally1623/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    // TC : O(N*N)
    // SC : O(N*N) -> to return the ans
    vector<int> solve_approach_1(vector<vector<int>>& matrix) {
        int n = matrix.size(); // rows == cols
        
        vector<int> ans;
        
        // First-Half : Traverse all cols of 0th row anti-diagonally
        for (int j = 0; j < n; j++) {
            int row = 0;
            int col = j;
            
            // Traverse anti-diagonal elements
            while (row < n && col >= 0) {
                ans.push_back(matrix[row][col]);
                row ++;
                col --;
            }
        }
        
        // Second-Half : Traverse right half of 2D Matrix anti-diagonal
        for (int i = 1; i < n; i++) {
            int row = i;
            int col = n - 1;    // always
            
            while (row < n && col >= 0) {
                ans.push_back(matrix[row][col]);
                row ++;
                col --;
            }
        }
        
        return ans;
    }
    
    // TC : O(N*N)
    // SC : O(N*N) -> to return ans
    vector<int> solve_approach_2(vector<vector<int>>& matrix) {
        int n = matrix.size();  // row == col
        
        vector<int> result;
        
        int row = 0;
        int col = 0;
        int step = 1;
        while (row < n && col < n) {
            int i = row;
            int j = col;
            
            while (i < n && j >= 0) {
                result.push_back(matrix[i][j]);
                i ++;
                j --;
            }
            
            if (col < n - 1) col ++;    
            else row ++;    // when col gets out of bound 
        }
        return result;
    }
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
        // return solve_approach_1(matrix);
        
        return solve_approach_2(matrix);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends