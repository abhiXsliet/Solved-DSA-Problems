// https://leetcode.com/problems/count-vowels-permutation/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int MOD = 1e9 + 7;
    int a = 0, e = 1, i = 2, o = 3, u = 4;

    // TC = O(5^N)
    // SC = O(N) -> recursive depth
    long long solve_rec(char ch, int n) {
        if (n == 0) return 1;

        /* 
            According to Question
            a -> e,
            e -> ea, ei,
            i -> ia, ie, io, iu,
            o -> oi, ou,
            u -> ua
        */

        if (ch == 'a') {
            return solve_rec('e', n - 1) % MOD;
        }
        else if (ch == 'e') {
            return (solve_rec('a', n - 1) + solve_rec('i', n - 1)) % MOD;
        }
        else if (ch == 'i') {
            return (solve_rec('a', n - 1) + solve_rec('e', n - 1) + 
                   solve_rec('o', n - 1) + solve_rec('u', n - 1)) % MOD;
        }
        else if (ch == 'o') {
            return (solve_rec('i', n - 1) + solve_rec('u', n - 1)) % MOD;
        }
        else if (ch == 'u') {
            return solve_rec('a', n - 1) % MOD;
        }

        return 0;
    }

    long long solve_mem(int ch, int n, vector<vector<long long>>& dp) {
        if (n == 0) return 1;

        if (dp[ch][n] != -1) return dp[ch][n];

        long long result = 0;
        if (ch == a) {
            return dp[ch][n] = (solve_mem(e, n - 1, dp)) % MOD;
        }
        else if (ch == e) {
            return dp[ch][n] = (solve_mem(a, n - 1, dp) + solve_mem(i, n - 1, dp)) % MOD;
        }
        else if (ch == i) {
            return dp[ch][n] = (solve_mem(a, n - 1, dp) + solve_mem(e, n - 1, dp) + 
                                solve_mem(o, n - 1, dp) + solve_mem(u, n - 1, dp)) % MOD;
        }
        else if (ch == o) {
            return dp[ch][n] = (solve_mem(i, n - 1, dp) + solve_mem(u, n - 1, dp)) % MOD;
        }
        else if (ch == u) {
            return dp[ch][n] = solve_mem(a, n - 1, dp) % MOD;
        }

        return dp[ch][n] = 0;
    }

    // TC = O(N)
    // SC = O(N)
    long long solve_tabulation(int n) {
        vector<vector<long long>> dp(6, vector<long long>(n+1, 0));
        // dp[i][j] = number of string ending at i vowel having length j

        for (int vowel = 0; vowel <= 4; vowel++) { // vowel => a = 0, e = 1, ...
            dp[vowel][1] = 1;
        }

        /* 
            According to Question
            a -> e,
            e -> ea, ei,
            i -> ia, ie, io, iu,
            o -> oi, ou,
            u -> ua
        */

        for (int len = 2; len <= n; len++) {
            dp[a][len] = (dp[e][len-1] + dp[i][len-1] + dp[u][len-1]) % MOD;
            
            dp[e][len] = (dp[a][len-1] + dp[i][len-1]) % MOD;
            
            dp[i][len] = (dp[e][len-1] + dp[o][len-1]) % MOD;
            
            dp[o][len] = (dp[i][len-1]) % MOD;
            
            dp[u][len] = (dp[o][len-1] + dp[i][len-1]) % MOD;
        }

        long long result = 0;
        for (int vowel = 0; vowel <= 4; vowel++) {
            result = (result + dp[vowel][n]) % MOD;
        }

        return result;
    }

    long long solve_recursion(int n) {
        long long result = 0;
        result = (result + solve_rec('a', n - 1)) % MOD;
        result = (result + solve_rec('e', n - 1)) % MOD;
        result = (result + solve_rec('i', n - 1)) % MOD;
        result = (result + solve_rec('o', n - 1)) % MOD;
        result = (result + solve_rec('u', n - 1)) % MOD;

        return result;
    }

    // TC = O(N)
    // SC = O(N)
    long long solve_memoization(int n) {

        vector<vector<long long>> dp(5+1, vector<long long>(n+1, -1));

        long long result = 0;

        result = (result + solve_mem(a, n - 1, dp)) % MOD;
        result = (result + solve_mem(e, n - 1, dp)) % MOD;
        result = (result + solve_mem(i, n - 1, dp)) % MOD;
        result = (result + solve_mem(o, n - 1, dp)) % MOD;
        result = (result + solve_mem(u, n - 1, dp)) % MOD;

        return result;
    }

public:
    int countVowelPermutation(int n) {

        // return solve_recursion(n);

        // return solve_memoization(n);

        return solve_tabulation(n);
    }
};