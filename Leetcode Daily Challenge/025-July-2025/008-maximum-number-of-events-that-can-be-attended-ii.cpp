// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int n;
    using ll = long long;

    ll mem(vector<vector<int>> &events, int k, int curr, int prev, vector<vector<ll>> &dp) {
        if (curr == n || k == 0) return 0;

        if (dp[prev + 1][k] != -1) return dp[prev + 1][k];

        ll take = 0;
        if (prev == -1 || events[curr][0] > events[prev][1]) {
            take = events[curr][2] + mem(events, k - 1, curr + 1, curr, dp);
        }

        ll notTake = mem(events, k, curr + 1, prev, dp);

        return dp[prev + 1][k] = max(take, notTake);
    }

    int binarySearch(vector<vector<int>> &events, int low, int tar) {
        int high = n - 1;
        int ans = n; // for the last event the upper bound will be n
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (events[mid][0] > tar) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    ll solve(vector<vector<int>> &events, int k, int curr, vector<vector<ll>> &dp) {
        if (curr >= n || k == 0) return 0;

        if (dp[curr][k] != -1) return dp[curr][k];

        int nextValidIdx = binarySearch(events, curr, events[curr][1]); 

        ll take     = events[curr][2] + solve(events, k - 1, nextValidIdx, dp);
        ll notTake  = solve(events, k, curr + 1, dp);

        return dp[curr][k] = max(take, notTake);
    }


    // TC : O(N * N * K)
    // SC : O(N * K)
    int approach_1(vector<vector<int>> &events, int k) {
        vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, -1));
        return mem(events, k, 0, -1, dp);   // track previous taken event
    }

    // TC : O(N * K * log(N))
    // SC : O(N * K)
    int approach_2(vector<vector<int>> &events, int k) {
        vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, -1));
        return solve(events, k, 0, dp);
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        n = events.size();
        sort(begin(events), end(events));

        // return approach_1(events, k);   // TLE -> without binarySearch : tracking previous taken index
        return approach_2(events, k);   // using binarySearch
    }
};