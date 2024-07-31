// https://leetcode.com/problems/filling-bookcase-shelves/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int n;
    int WIDTH;
    int dp[1001][1001];

    // TC : O(N * width)
    // SC : O(N * width)
    int solve(int i, int remWidth, vector<vector<int>>& books, int maxHt) {
        if (i == n) {
            return maxHt;
        }

        if (dp[i][remWidth] != -1) 
            return dp[i][remWidth];

        int keep  = INT_MAX;
        int skip  = INT_MAX;

        if (books[i][0] <= remWidth) { 
            keep = solve(i + 1, remWidth - books[i][0], books, max(maxHt, books[i][1]));
        }

        // new shelf
        skip = maxHt + solve(i + 1, WIDTH - books[i][0], books, books[i][1]);

        return dp[i][remWidth] = min(keep, skip);
    }
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        n = books.size();
        memset(dp, -1, sizeof(dp));
        WIDTH = shelfWidth;
        int remWidth = shelfWidth;
        int maxHeight= 0;
        return solve(0,  remWidth, books, maxHeight);
    }
};