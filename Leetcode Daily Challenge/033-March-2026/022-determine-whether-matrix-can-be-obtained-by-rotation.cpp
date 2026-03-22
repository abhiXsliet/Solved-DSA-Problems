// https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    void rotateCW90(vector<vector<int>>& mat) {
        int n = mat.size();
        // transpose
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        
        // reverse each row
        for (int i = 0; i < n; i++) 
            reverse(mat[i].begin(), mat[i].end());
    }
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& tar) {
        int step = 3;
        while (step --) {
            if (mat == tar) return true;
            else rotateCW90(mat);
        }
        return mat == tar;
    }
};