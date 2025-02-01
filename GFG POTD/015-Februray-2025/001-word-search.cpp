// https://www.geeksforgeeks.org/problems/word-search/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    vector<vector<int>> directions {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    // TC : O(3^L)
    // SC : O(L) Due to recursive call stack space
    bool solve(vector<vector<char>> &mat, string &word, int i, int j, int m, int n, int idx) {
        if (idx >= word.length()) return true;
        char temp = mat[i][j];
        mat[i][j] = '$'; // visited
        bool flag = false;
        for (vector<int>& dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && mat[i_][j_] == word[idx]) {
                bool ans = solve(mat, word, i_, j_, m, n, idx + 1);
                if (ans) return true;
                else flag |= ans;
            }
        }
        mat[i][j] = temp;
        return flag;
    }
  public:
    // TC : O(M * N * 3^L) There are 3^L possible directions to explore at each step, rather than 4^L, because once a position is left, it is marked as visited.
    // SC : O(L) Due to recursive stack space, Where L = length of the word
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        int m = mat.size(), n = mat[0].size();
        int idx = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (idx < word.length() && mat[i][j] == word[idx]) {
                    if (solve(mat, word, i, j, m, n, idx + 1))
                        return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends