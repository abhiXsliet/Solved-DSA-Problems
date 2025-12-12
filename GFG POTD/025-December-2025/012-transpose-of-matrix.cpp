// https://www.geeksforgeeks.org/problems/transpose-of-matrix-1587115621/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0, j=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        return matrix;
    }
};