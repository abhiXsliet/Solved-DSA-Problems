// https://www.geeksforgeeks.org/problems/n-queen-problem0315/1




//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function Template for C++
class Solution{
private:
    vector<vector<int>> result;
    
    bool isPossibleToPlace(vector<string>& board, int n, int i, int j) {
        // Check the column
        for (int row = 0; row < i; row ++) {
            if (board[row][j] == 'Q')
                return false;
        }
        
        // Check the left diagonal
        for (int row = i - 1, col = j - 1; row >= 0 && col >= 0; row --, col --) {
            if (board[row][col] == 'Q') 
                return false;
        }
        
        // Check the right diagonal
        for (int row = i - 1, col = j + 1; row >= 0 && col < n; row--, col++) {
            if (board[row][col] == 'Q') 
                return false;
        }
        return true;
    }
    
    void storeAns(vector<string>& board, int n) {
        vector<int> rows;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                if (board[j][i] == 'Q') {
                    rows.push_back(j + 1);
                    break;
                }
            }
        }
        
        if (rows.size() == board.size()) // valid ans
            result.push_back(rows);
    }
    
    void solve(vector<string>& board, int n, int i) {
        if (i >= n) {
            storeAns(board, n);
            return;
        }
        
        for (int j = 0; j < n; j ++) {
            if (isPossibleToPlace(board, n, i, j)) {
                board[i][j] = 'Q';
                solve(board, n, i + 1);
                board[i][j] = '.';
            }
        }
    }
public:
    // TC : O(N!)
    // SC : O(N^2)
    vector<vector<int>> nQueen(int n) {
        vector<string> board(n, string(n, '.'));
        solve(board, n, 0);
        sort(begin(result), end(result));
        return result;
    }
};


//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends