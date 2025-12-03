// https://www.geeksforgeeks.org/problems/travelling-salesman-problem2732/1/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(int mask, int curr, vector<vector<int>>& cost) {
        // if all cities visited → return cost to go back to 0
        if(mask == (1 << n) - 1)
            return cost[curr][0];

        if(dp[mask][curr] != -1)
            return dp[mask][curr];

        int ans = INT_MAX;

        // try going to every unvisited city
        for(int next = 0; next < n; next++) {
            if(!(mask & (1 << next))) { // city not visited
                ans = min(ans,
                          cost[curr][next] + solve(mask | (1 << next), next, cost));
            }
        }
        return dp[mask][curr] = ans;
    }

    int tsp(vector<vector<int>>& cost) {
        n = cost.size();
        dp.assign(1 << n, vector<int>(n, -1));

        // start from 0 with only city 0 visited
        return solve(1, 0, cost);
    }
};