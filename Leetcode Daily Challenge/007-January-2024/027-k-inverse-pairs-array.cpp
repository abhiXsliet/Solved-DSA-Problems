// https://leetcode.com/problems/k-inverse-pairs-array/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int MOD = 1e9 + 7;

    // TC : O(K^N)
    // SC : O(Depth of Recursive Tree)
    int solve_rec(int n, int k) {
        if (n == 0) return 0;
        if (k == 0) return 1; // sorted array

        int result = 0;
        // For an array of 'n' length, we can have at max of n - 1 inversion
        for (int inv = 0; inv <= min(k, n - 1); inv++) {
            result = (result % MOD + solve_rec(n - 1, k - inv) % MOD) % MOD;
        }

        return result;
    }

    // TC : O(N * K * N)
    // SC : O(N * K)
    int t[1001][1001];
    int solve_mem(int n, int k) {
        if (n == 0) return 0;
        if (k == 0) return 1; // sorted array

        if (t[n][k] != -1) return t[n][k];

        int result = 0;
        // For an array of 'n' length, we can have at max of n - 1 inversion
        for (int inv = 0; inv <= min(k, n - 1); inv++) {
            result = (result % MOD + solve_mem(n - 1, k - inv) % MOD) % MOD;
        }

        return t[n][k] = result;
    }

    // TC : O(N * K * N)
    // SC : O(N * K)
    int solve_tab(int n, int k) {
        // t[i][j] = total n. of arrays having (1 to i) & exactly j inversion
        vector<vector<int>> t(n+1, vector<int>(k+1, 0));

        // for j = 0, t[i][0] = 1
        for (int i = 0; i <= n; i++) {
            t[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) { // n is replaced with i
            for (int j = 1; j <= k; j++) {  // k is replaced with j

                for (int inv = 0; inv <= min(i-1, j); inv++) {
                    t[i][j] = (t[i][j] % MOD + t[i - 1][j - inv] % MOD) % MOD;
                }
            }
        }

        return t[n][k];
    }

    // TC : O(N * N)
    // SC : O(N * K)
    int solve_tab_optimized(int n, int k) {
        // t[i][j] = total n. of arrays having (1 to i) & exactly j inversion
        vector<vector<int>> t(n+1, vector<int>(k+1, 0));

        // for j = 0, t[i][0] = 1
        for (int i = 0; i <= n; i++) {
            t[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) { // n is replaced with i

            long long cummSum = 1;
            for (int j = 1; j <= k; j++) {  // k is replaced with j

                cummSum += t[i - 1][j];

                if (j >= i) {
                    cummSum -= t[i - 1][j - i];
                }

                t[i][j] = cummSum % MOD;    
            }
        }

        return t[n][k];
    }
public:
    int kInversePairs(int n, int k) {
        // return solve_rec(n, k);

        // memset(t, -1, sizeof(t));
        // return solve_mem(n, k);

        // return solve_tab(n, k);

        return solve_tab_optimized(n, k);
    }
};