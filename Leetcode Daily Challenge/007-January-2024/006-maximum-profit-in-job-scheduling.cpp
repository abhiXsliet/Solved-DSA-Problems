// https://leetcode.com/problems/maximum-profit-in-job-scheduling/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    int getNextIdx(vector<vector<int>>& store, int low, int curr_job_end) {
        int high = n - 1;
        int res  = n + 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (store[mid][0] >= curr_job_end) { // take this job
                res = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return res;
    }

    int t[50001];
    
    // TC : O(N)
    // SC : O(N)
    int solve_rec(vector<vector<int>> &store, int idx) {
        if (idx >= n) return 0;

        if (t[idx] != -1) return t[idx];

        int nextElementIdx = getNextIdx(store, idx+1, store[idx][1]);

        int take = store[idx][2] + solve_rec(store, nextElementIdx); 
        int notTake = solve_rec(store, idx+1);

        return t[idx] = max(take, notTake);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();
        memset(t, -1, sizeof(t));

        // Initialize a vector to store startTime, endTime, profit of a job
        vector<vector<int>> store(n, vector<int>(3, 0));

        for (int i = 0; i < n; i++) {
            store[i][0] = startTime[i];
            store[i][1] = endTime[i];
            store[i][2] = profit[i];
        }

        auto cmp = [&](auto &vec1, auto &vec2) {
            return vec1[0] <= vec2[0];
        };

        sort(begin(store), end(store), cmp);

        return solve_rec(store, 0);
    }
};