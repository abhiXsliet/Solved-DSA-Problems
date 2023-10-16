// https://leetcode.com/problems/pascals-triangle-ii/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    long long getNCR(int row, int col) {
        long long ans = 1;
        for (int i = 0; i < col; i++) {
            ans = ans * (row - i);
            ans = ans / (i + 1);
        }
        return ans;
    }

    // TC = O(N^2)
    vector<int> get_nth_row_brute(int row) {
        vector<int> ans;
        for (int i = 0; i < row; i++) {
            ans.push_back(getNCR(row-1, i));
        }
        return ans;
    }

    // TC = O(N)
    vector<int> get_nth_row_optimal(int row) {
        vector<int> result;
        long long ans = 1;
        result.push_back(ans);
        for (int i = 1; i < row; i++) {
            ans *= (row - i);
            ans /= i;
            result.push_back(ans);
        }
        return result;
    }

    // TC = O(N^2)
    // SC = O(N^2)
    vector<int> solve_approach_2_brute(int row) {
        vector<vector<int>> store(row);
        for (int i = 0; i < row; i++) {
            store[i] = vector<int>(i+1, 1);
            for (int j = 1; j < i; j++) {
                store[i][j] = store[i-1][j] + store[i-1][j -1];
            }
        }

        return store[row-1];
    }

    // TC = O(N^2)
    // SC = O(N^2)
    vector<int> solve_approach_2_better(int row) {
        vector<int> prev;
        for (int i = 0; i < row; i++) {
            vector<int> curr(i+1, 1);
            for (int j = 1; j < i; j++) {
                curr[j] = prev[j] + prev[j - 1];
            }
            prev = curr;
        }
        return prev;
    }
public:
    vector<int> getRow(int rowIndex) {
        // return get_nth_row_brute(rowIndex+1);

        return get_nth_row_optimal(rowIndex+1);

        // return solve_approach_2_brute(rowIndex + 1);

        // return solve_approach_2_better(rowIndex + 1);
    }
};