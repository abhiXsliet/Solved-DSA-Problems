// https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    int n;
    int dp[301][27][27];

    int getDist(int val1, int val2) {
        int x1 = val1 / 6, y1 = val1 % 6;
        int x2 = val2 / 6, y2 = val2 % 6;
        return abs(x2 - x1) + abs(y2 - y1); 
    }

    int solve(string &word, int i, int f1, int f2) {
        if (i >= n) return 0;

        if (dp[i][f1][f2] != -1) return dp[i][f1][f2];

        int curr = word[i] - 'A';

        if (f1 == 26 && f2 == 26) { // both fingers are idle, so use f1 first
            return dp[i][f1][f2] = solve(word, i + 1, curr, f2);
        }

        if (f2 == 26) { // finger f2 is idle
            int move1 = getDist(f1, curr) + solve(word, i + 1, curr, f2);
            int move2 = solve(word, i + 1, f1, curr);

            return dp[i][f1][f2] = min(move1, move2);
        }

        int move1 = getDist(f1, curr) + solve(word, i + 1, curr, f2);
        int move2 = getDist(f2, curr) + solve(word, i + 1, f1, curr);

        return dp[i][f1][f2] = min(move1, move2);
    }
public:
    int minimumDistance(string word) {
        n = word.length();
        memset(dp, -1, sizeof(dp));
        return solve(word, 0, 26, 26);  // starting from 0th char with -1 and -1 as first and second fingers resp.
    }
};