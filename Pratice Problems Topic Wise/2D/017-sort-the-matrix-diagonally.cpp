// https://leetcode.com/problems/sort-the-matrix-diagonally/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:   
    // TC : O(N*M*log(N*M))
    // SC : O(N*M)
    vector<vector<int>> solve_1(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        map<int, vector<int>> mpp;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mpp[i - j].push_back(mat[i][j]);
            }
        }

        vector<vector<int>> result;
        for (auto& it : mpp) {
            sort(begin(it.second), end(it.second));
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                auto& vec  = mpp[i - j];
                mat[i][j] = vec[0];
                vec.erase(vec.begin());
            }
        }
        return mat;
    }

    // TC : O(K*log(K))
    // SC : O(K) Where K = Max No. of Elements in a diagonal (i.e., K = min(M, N))
    void sortFunc(vector<vector<int>>& mat, int row, int col, int m, int n) {
        vector<int> diagonalEle;
        int i = row, j = col, idx = 0;

        while (i < m && j < n) {
            diagonalEle.push_back(mat[i][j]);
            i ++, j ++;
        }

        sort(begin(diagonalEle), end(diagonalEle));

        i = row, j = col;
        while (i < m && j < n) {
            mat[i][j] = diagonalEle[idx];
            i ++, j ++, idx ++;
        }
    }

    // TC : O((M + N)*Klog(K)) Where M = No. of Rows & N = No. of Cols
    // SC : O(K)               Where K = Max no. elements present in a diagonal (i.e., K = min(M, N))
    vector<vector<int>> solve_2(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        for (int col = 0; col < n; col ++) {
            sortFunc(mat, 0, col, m, n);
        }

        for (int row = 1; row < m; row ++) {
            sortFunc(mat, row, 0, m, n);
        }

        return mat;
    }

    // TC : O(K) Where K = min(M, N)
    // SC : O(1)
    void countingSort(vector<vector<int>>& mat, int row, int col, int m, int n) {
        vector<int> values(101, 0);
        int i = row, j = col;
        while (i < m && j < n) {
            values[mat[i][j]] ++;   
            i ++, j ++;
        }

        i = row, j = col;
        for (int val = 1; val < 101; val ++) {
            if (values[val] > 0) {
                int count = values[val];
                while (count --) {
                    mat[i][j] = val;
                    i ++, j ++;
                }
            }
        }
    }

    // TC : O((M + N) * K)  Where M = No. of Rows & N = No. of Cols
    // SC : O(1)            Where K = Max no. elements present in a diagonal (i.e., K = min(M, N))
    vector<vector<int>> solve_3(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        for (int col = 0; col < n; col ++) {
            countingSort(mat, 0, col, m, n);
        }

        for (int row = 1; row < m; row ++) {
            countingSort(mat, row, 0, m, n);
        }

        return mat;
    }
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        // return solve_1(mat);     // HASHTABLE : Easiest

        // return solve_2(mat);     // SIMULATION

        return solve_3(mat);        // COUNTING SORT
    }
};