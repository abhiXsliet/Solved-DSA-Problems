// https://leetcode.com/problems/knight-dialer/


#include <bits/stdc++.h>
using namespace std;

class Solution {
    int M = 1e9+7;

    vector<vector<int>> adj = {
        {4, 6}, 
        {6, 8},
        {7, 9}, 
        {4, 8}, 
        {3, 9, 0},
        {}, 
        {1, 7, 0}, 
        {2, 6}, 
        {1, 3}, 
        {2, 4}
    };

    int t[5001][10];

    // T.C  : O(n*9) Total n*k states
    // S.C  : O(n*9)
    // NOTE : T.C Without Memoization - O(10 * 3^n). This is because each cell has upto 3-Possible next cells (neighbors)

    int solve(int n, int cell) {
        if (n == 0) return 1;

        if (t[n][cell] != -1)
            return t[n][cell];

        int ans = 0;

        for (int &nextCell : adj[cell]) {

            ans = (ans + solve(n - 1, nextCell)) % M;
        }

        return t[n][cell] = ans;
    }

    int solve_mem(int n) {
        memset(t, -1, sizeof(t));

        int result = 0;

        for (int cell = 0; cell <= 9; cell++) {

            result = (result + solve(n - 1, cell)) % M;
        }

        return result;
    }

    int solve_tab(int n) {
        vector<vector<int>> t(n, vector<int>(10, 0));

        // Base Case
        for (int cell = 0; cell <= 9; cell++) {
            t[0][cell] = 1; // [n][cell]
        }

        for (int i = 1; i <= n - 1; i++) {
            
            for (int cell = 0; cell <= 9; cell++) {

                int ans = 0;

                for (int &nextCell : adj[cell]) {

                    ans = (ans + t[i - 1][nextCell]) % M; // solve(n - 1, cell)
                }

                t[i][cell] = ans;
            }
        }

        int result = 0;

        for (int cell = 0; cell <= 9; cell++) {

            result = (result + t[n - 1][cell]) % M; // result + solve(n-1, cell)
        }

        return result;
    }

public:
    int knightDialer(int n) {
        // return solve_mem(n);

        return solve_tab(n);
    }
};