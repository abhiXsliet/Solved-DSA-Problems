// https://www.geeksforgeeks.org/problems/n-queen-problem0315/1




//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function Template for C++
class Solution {
  private:
    // TC : O(N!)
    // SC : O(N) Recursive Depth
    void solve_optimized(vector<vector<int>> &result, vector<string> &board, int row, int n, unordered_set<int>&col, unordered_set<int>& rDiag, unordered_set<int>& lDiag) {
        if (row == n) {
            storeAns(result, board, n);
            return;
        }
        
        for (int c = 0; c < n; c ++) {
            if (!col.count(c) && !rDiag.count(row + c) && !lDiag.count(row - c)) {
                board[row][c] = 'Q';
                
                col.insert(c);
                rDiag.insert(row + c);
                lDiag.insert(row - c);
                
                solve_optimized(result, board, row + 1, n, col, rDiag, lDiag);
                
                col.erase(c);
                rDiag.erase(row + c);
                lDiag.erase(row - c);
                
                board[row][c] = '.';
            }
        }
    }
    
    // TC : O(N)
    // SC : O(N)
    void storeAns(vector<vector<int>> &result, vector<string> &board, int n) {
        vector<int> row;
        for (int c = 0; c < n; c ++) {
            for (int r = 0; r < n; r ++) {
                if (board[r][c] == 'Q') {
                    row.push_back(r + 1);   // 1-based index
                }
            }
        }
        if (row.size() == n) {
            result.push_back(row);
        }
    }
    
    // TC : O(N)
    // SC : O(1)
    bool isSafe(vector<string> &board, int row, int col, int n) {
        // check in the upward direction
        for (int r = row - 1; r >= 0; r --) {
            if (board[r][col] == 'Q') {
                return false;
            }
        }
        
        // check in diagonal upward-left direction
        for (int r = row - 1, c = col - 1; r >= 0 && c >= 0; r --, c--) {
            if (board[r][c] == 'Q') {
                return false;
            }
        }
        
        // check in diagonal upward-right direction
        for (int r = row - 1, c = col + 1; r >= 0 && c < n; r --, c ++) {
            if (board[r][c] == 'Q') {
                return false;
            }
        }
        
        return true;
    }
    
    // TC : O(N! * N)
    // SC : O(N) Recursive Depth
    void solve(vector<vector<int>> &result, vector<string> &board, int row, int n) {
        if (row == n) {
            storeAns(result, board, n);
            return;
        }
        
        for (int c = 0; c < n; c ++) {
            if (isSafe(board, row, c, n)) {
                board[row][c] = 'Q';
                solve(result, board, row + 1, n);
                board[row][c] = '.';
            }
        }
    }
    
    // TC : O(N! * N)
    // SC : O(N^2) space used by board
    vector<vector<int>> approach_1(int n) {
        vector<vector<int>> result;
        vector<string> board(n, string(n, '.'));
        solve(result, board, 0, n);
        return result;
    }
    
    // TC : O(N!)
    // SC : O(N^2 + N) space used by board and set
    vector<vector<int>> approach_2(int n) {
        vector<vector<int>> result;
        vector<string> board(n, string(n, '.'));
        
        // track the occupied upper-rows, upper-left diag and upper-right diag using set
        unordered_set<int> usedUpperCol, usedUpperRightDiag, usedUpperLeftDiag;
        
        solve_optimized(result, board, 0, n, usedUpperCol, usedUpperRightDiag, usedUpperLeftDiag);
        return result;
    }
  public:
    vector<vector<int>> nQueen(int n) {
        // return approach_1(n);
        return approach_2(n);   // is-safe optimized
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends