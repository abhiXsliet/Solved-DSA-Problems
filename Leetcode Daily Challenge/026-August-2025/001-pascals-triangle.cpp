// https://leetcode.com/problems/pascals-triangle/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(N) , SC = O(1)
    long long nCr(int row, int col) {
        long long res = 1;
        for (int i = 0; i < col; i++) {
            res *= (row - i);
            res /= (i + 1);
        }
        return res;
    }

    // TC = O(N), SC = O(1)
    vector<int> generate_nth_row(int row) {
        vector<int> result(row + 1, 1);
        long long val = 1;
        for (int i = 1; i <= row-1; i++) {
            val *= (row - (i - 1));
            val /= i;
            result[i] = val;
        }
        return result;
    }

    // TC = O(N^3)
    // SC = O(1)
    vector<vector<int>> brute(int row) {
        vector<vector<int>> ans;
        for (int i = 1; i <= row; i++) {
            vector<int> temp;
            for (int j = 1; j <= i; j++) {
                temp.push_back( nCr(i-1, j-1) );
            }
            ans.push_back(temp);
        }
        return ans;
    }

    // TC = O(N^2)
    vector<vector<int>> optimal_1(int row) {
        vector<vector<int>> result;
        for (int i = 0; i < row; i++) {
            result.push_back( generate_nth_row(i) );
        }
        return result;
    }
    
    // TC = O(N^2)
    vector<vector<int>> optimal_2(int row) {
        vector<vector<int>> result(row);
        for (int i = 0; i < row; i++) {
            result[i] = vector<int>(i+1, 1);
            for (int j = 1; j < i; j++) {
                result[i][j] = result[i-1][j] + result[i-1][j-1];
            }
        }
        return result;
    }

public:
    vector<vector<int>> generate(int numRows) {
        // return brute(numRows);

        // return optimal_1(numRows);

        return optimal_2(numRows);
    }
};