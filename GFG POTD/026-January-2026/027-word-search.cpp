// https://www.geeksforgeeks.org/problems/word-search/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    vector<vector<int>> directions {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
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
    // TC : O(m * n * 4^L) Where L = Recursive Stack Space
    // SC : O(L)
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