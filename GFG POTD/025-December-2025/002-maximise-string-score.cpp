// https://www.geeksforgeeks.org/problems/maximise-string-score--172902/1/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(string &s, vector<vector<char>> &jumpsPairs) {
        int n = s.size();

        // Build adjacency: can[from] contains target characters allowed from 'from'
        vector<vector<int>> can(26);
        for (auto &pr : jumpsPairs) {
            int a = pr[0] - 'a';
            int b = pr[1] - 'a';
            can[a].push_back(b);
        }
        
        // Also allow jumping forward to same character
        for (int c = 0; c < 26; ++c) {
            can[c].push_back(c);
        }

        // Prefix sum of ascii values: p[k] = sum of s[0..k-1]
        vector<long long> p(n+1, 0);
        for (int i = 0; i < n; ++i) p[i+1] = p[i] + (int)s[i];

        // occSum[ch][k] = sum of ascii of positions < k where s[pos]==ch
        vector<vector<long long>> occSum(26, vector<long long>(n+1, 0));
        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            for (int ch = 0; ch < 26; ++ch) occSum[ch][i+1] = occSum[ch][i];
            if (0 <= c && c < 26) occSum[c][i+1] += (int)s[i];
        }

        const long long NEG = LLONG_MIN / 4;
        vector<long long> best(26, NEG);
        vector<long long> dp(n, 0);

        // Scan from right to left
        for (int i = n-1; i >= 0; --i) {
            int from = s[i] - 'a';
            long long bestVal = NEG;

            // For each allowed target character ch, use precomputed best[ch]
            for (int ch : can[from]) {
                if (ch < 0 || ch >= 26) continue;
                if (best[ch] != NEG) {
                    // candidate = occSum[ch][i] + best[ch]
                    bestVal = max(bestVal, occSum[ch][i] + best[ch]);
                }
            }

            if (bestVal == NEG) {
                dp[i] = 0; // no valid forward jump
            } else {
                dp[i] = bestVal - p[i];
            }

            // Update best for the character s[i], so earlier indices can jump to this i
            int chHere = from;
            long long valForBest = p[i] - occSum[chHere][i] + dp[i];
            best[chHere] = max(best[chHere], valForBest);
        }

        // We start at index 0
        long long res = dp[0];
        if (res < INT_MIN) return INT_MIN;
        if (res > INT_MAX) return INT_MAX;
        return (int)res;
    }
};