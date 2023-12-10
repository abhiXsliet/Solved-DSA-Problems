// https://leetcode.com/problems/transpose-matrix/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(M*N)
    // SC = O(M*N) -> to store and return the answer
    vector<vector<int>> solve_brute(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> result;

        if (n == m) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j <= i; j++) {
                    swap(matrix[i][j], matrix[j][i]);
                }
            }

            for (int i = 0; i < m; i++) {
                vector<int> temp;
                for (int j = 0; j < n; j++) {
                    temp.push_back(matrix[i][j]);
                }
                result.push_back(temp);
            }
        }
        else {
            for(int j = 0; j < n; j++) {
                vector<int> temp;
                for (int i = 0; i < m; i++) {
                    temp.push_back(matrix[i][j]);
                }
                result.push_back(temp);
            }
        }
        
        return result;
    }

    // TC = O(M*N)
    // SC = O(M*N) -> to store and return the answer
    vector<vector<int>> solve_better(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // after transpose the size of matrix will be n*m
        vector<vector<int>> result(n, vector<int>(m, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[j][i] = matrix[i][j];
            }
        }

        return result;
    }
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        // return solve_brute(matrix);

        return solve_better(matrix);
    }
};