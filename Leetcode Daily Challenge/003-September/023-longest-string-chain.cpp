// https://leetcode.com/problems/longest-string-chain/


#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
    bool isPredecessor(string& prev, string& curr) {
        int m = prev.length(), n = curr.length();

        if (m >= n || n - m != 1) return false;

        int i = 0, j = 0;

        while (i < m && j < n) {
            if (prev[i] == curr[j])
                i++;
            j++;
        }

        return i == m;
    }

    // TC = O(2^N)
    // SC = O(N) maximum recursion depth
    int solve_rec(vector<string>& words, int prev, int curr) {
        if (curr == words.size())
            return 0;
        
        int take = 0, not_take = 0;
        if ( prev == -1 || isPredecessor(words[prev], words[curr]) ) {
            take = 1 + solve_rec(words, curr, curr + 1);
        }

        not_take = 0 + solve_rec(words, prev, curr + 1);

        return max(take, not_take);
    }

    // TC = O(N * N)
    // SC = O(N * N)
    int solve_mem(vector<string>& words, int prev, int curr, vector<vector<int>>& dp) {
        if (curr == words.size())
            return 0;

        if (prev != -1 && dp[prev][curr] != -1) 
            return dp[prev][curr];
        
        int take = 0, not_take = 0;
        if ( prev == -1 || isPredecessor(words[prev], words[curr]) ) {
            take = 1 + solve_mem(words, curr, curr + 1, dp);
        }

        not_take = 0 + solve_mem(words, prev, curr + 1, dp);

        if (prev != -1)
            dp[prev][curr] = max(take, not_take);

        return max(take, not_take);
    }
    
    // TC = O(N * N)
    // SC = O(N * N)
    int solve_tab(vector<string>& words, int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for (int curr = n - 1; curr >= 0; curr--) {
            for (int prev = curr - 1; prev >= -1; prev--) {
                
                int take = 0, not_take = 0;

                if ( prev == -1 || isPredecessor(words[prev], words[curr]) ) 
                    take = 1 + dp[curr + 1][curr + 1];

                not_take = 0 + dp[prev + 1][curr + 1];

                dp[prev + 1][curr] = max(take, not_take);
            }
        }

        return dp[0][0];
    }

    // TC = O(N * N)
    // SC = O(N)
    int solve_so(vector<string>& words, int n) {
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);

        for (int curr = n - 1; curr >= 0; curr--) {
            for (int prev = curr - 1; prev >= -1; prev--) {
                
                int take = 0, not_take = 0;

                if ( prev == -1 || isPredecessor(words[prev], words[curr]) ) 
                    take = 1 + nextRow[curr + 1];

                not_take = 0 + nextRow[prev + 1];

                currRow[prev + 1] = max(take, not_take);
            }
            nextRow = currRow;
        }

        return nextRow[0];
    }
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        auto cmp = [&](string& word1, string& word2) {
            return word1.length() < word2.length();
        };
        
        sort(begin(words), end(words), cmp);

        // // Recursive -> TLE
        // return solve_rec(words, -1, 0);


        // // Memoization
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return solve_mem(words, -1, 0, dp);


        // // Tabulation
        // return solve_tab(words, n);


        // Space - Optimization
        return solve_so(words, n);
    }
};