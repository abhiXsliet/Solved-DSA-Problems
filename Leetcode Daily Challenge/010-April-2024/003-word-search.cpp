// https://leetcode.com/problems/word-search/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int n, m;
    vector<vector<int>> dir{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    bool find(vector<vector<char>>& board, int i, int j, int idx, string& word) {
        if (idx == word.length())
            return true;

        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '$') 
            return false;
        
        if (word[idx] != board[i][j]) 
            return false;
        
        char temp = board[i][j];
        board[i][j] = '$';

        for (auto& d : dir) {
            int i_ = i + d[0];
            int j_ = j + d[1];

            if (find(board, i_, j_, idx + 1, word))
                return true;
        }
        board[i][j] = temp;
        return false;
    }
public:
    // TC : O(M × N × 4^L), where M,N = board.size() and L = length of the word to be found
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == word[0] && find(board, i, j, 0, word)) 
                    return true;
            }
        }
        return false;
    }
};