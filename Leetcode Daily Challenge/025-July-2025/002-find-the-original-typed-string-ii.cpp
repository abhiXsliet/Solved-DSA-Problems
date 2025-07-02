// https://leetcode.com/problems/find-the-original-typed-string-ii/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    const int M = 1e9 + 7;
    typedef long long ll;

    ll solve(int i, int cnt, vector<int> &freq, int k, vector<vector<int>> &dp) {
        if (i >= freq.size()) {
            return cnt < k;
        }

        if (dp[i][cnt] != -1)
            return dp[i][cnt];

        ll res = 0;
        for (int take = 1; take <= freq[i]; take ++) {
            if (take + cnt < k) {
                res = (res + solve(i + 1, cnt + take, freq, k, dp)) % M;
            } else break;
        }
        return dp[i][cnt] = res;
    }

    // TC : O(N * K * max(freq[i]))
    // SC : O(N * K) Where N = size of freq
    ll approach_1(vector<int> &freq, int k) {
        int n = freq.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return solve(0, 0, freq, k, dp);
    }

    // TC : O(N * K * max(freq[i]))
    // SC : O(N * K) Where N = size of freq
    ll approach_2(vector<int> &freq, int k) {
        int n = freq.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int i = 0; i < k; i ++) {
            dp[n][i] = 1;
        }

        for (int i = n - 1; i >= 0; i --) {
            for (int count = k - 1; count >= 0; count --) {

                ll res = 0;
                for (int take = 1; take <= freq[i]; take ++) {
                    if (take + count < k) {
                        res = (res + dp[i + 1][count + take]) % M;
                    } else break;
                }

                dp[i][count] = res;
            }
        }

        return dp[0][0];
    }

    // TC : O(N * K)
    // SC : O(N * K) Where N = size of freq
    ll approach_3(vector<int> &freq, int k) {
        int n = freq.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int i = 0; i < k; i ++) {
            dp[n][i] = 1;
        }

        for (int i = n - 1; i >= 0; i --) {
            
            vector<int> prefix(k + 1, 0);
            for (int h = 1; h <= k; h ++) {
                prefix[h] = (prefix[h - 1] + dp[i + 1][h - 1]) % M;
            }

            for (int count = k - 1; count >= 0; count --) {

                int l = count + 1;
                int r = count + freq[i];

                if (r >= k) {
                    r = k - 1;
                }

                if (l <= r) {
                    dp[i][count] = (prefix[r + 1] - prefix[l] + M) % M;
                }
            }
        }

        return dp[0][0];
    }
public:
    int possibleStringCount(string word, int k) {
        int n = word.length();

        if (n < k) return 0;

        vector<int> freq;
        int count = 1;
        for (int i = 1; i < n; i ++) {
            if (word[i] == word[i - 1]) {
                count += 1;
            } else {
                freq.push_back(count);
                count = 1;
            }
        }
        freq.push_back(count);

        ll total = 1;
        for (int &f : freq) {
            total = (total * f) % M;
        }

        if (freq.size() >= k)
            return total;

        // remove invalid string of len < k

        // ll invalid = approach_1(freq, k);    // TLE : memoized
        // ll invalid = approach_2(freq, k);    // TLE : bottomUp
        ll invalid = approach_3(freq, k);    // Optimized bottomUp using prefixSum

        return (total - invalid + M) % M;
    }
};