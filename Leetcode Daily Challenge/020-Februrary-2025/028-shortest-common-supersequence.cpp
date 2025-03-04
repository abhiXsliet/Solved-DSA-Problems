// https://leetcode.com/problems/shortest-common-supersequence/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    int getLCSLength(string &s1, string &s2, int i, int j, int n1, int n2, vector<vector<int>> &dp) {
        if (i >= n1 || j >= n2) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i] == s2[j]) {
            return dp[i][j] = 1 + getLCSLength(s1, s2, i + 1, j + 1, n1, n2, dp);
        } else {
            return dp[i][j] = max(getLCSLength(s1, s2, i + 1, j, n1, n2, dp),
                                    getLCSLength(s1, s2, i, j + 1, n1, n2, dp));
        }
    }

    string reconstructLCS(string &s1, string &s2, vector<vector<int>> &dp) {
        int i = 0, j = 0;
        int n1 = s1.size(), n2 = s2.size();
        string lcs = "";

        while (i < n1 && j < n2) {
            if (s1[i] == s2[j]) {
                lcs += s1[i];
                i++, j++;
            // dp[i + 1][j] represents the LCS if we skip s1[i].
            // dp[i][j + 1] represents the LCS if we skip s2[j].                
            } else if (dp[i + 1][j] >= dp[i][j + 1]) {
                i++;
            } else {
                j++;
            }
        }
        return lcs;
    }

    // TC : O(N1 * N2)
    // SC : O(N1 * N2)
    string approach_1(string &s1, string &s2) {
        int n1 = s1.length(), n2 = s2.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));

        getLCSLength(s1, s2, 0, 0, n1, n2, dp);
        string lcs = reconstructLCS(s1, s2, dp);

        int n3 = lcs.length(); 
        string result;
        int i = 0, j = 0, k = 0;
        while (i < n1 && j < n2 && k < n3) {
            if (s1[i] == s2[j] && s2[j] == lcs[k]) {
                result += s2[j];
                i++, j++, k++;
            } else if (s1[i] != s2[j] && s1[i] == lcs[k]) {
                result += s2[j];
                j++;
            } else if (s1[i] != s2[j] && s2[j] == lcs[k]) {
                result += s1[i];
                i++;
            } else {
                result += s1[i];
                i++;
            }
        }
        while (i < n1) result += s1[i++];
        while (j < n2) result += s2[j++];

        return result;
    }

public:
    string shortestCommonSupersequence(string str1, string str2) {
        return approach_1(str1, str2);
    }
};