// https://leetcode.com/problems/furthest-building-you-can-reach/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // MLE -> Bricks & ladder constraint are very high
    // TC : O(N * N)
    int solve_mem(vector<int>& heights, int n, int bricks, int ladders, int i, vector<vector<int>>& dp) {
        if (i == n - 1) return 0;

        if (dp[bricks][ladders] != -1)
            return dp[bricks][ladders];

        if (heights[i + 1] <= heights[i]) {
            return dp[bricks][ladders] = 1 + solve_mem(heights, n, bricks, ladders, i + 1, dp);
        }
        else {
            int byBricks = 0;
            int byLadder = 0;
            int diff     = heights[i + 1] - heights[i];

            if (bricks >= diff) 
                byBricks = 1 + solve_mem(heights, n, bricks - diff, ladders, i + 1, dp);

            if (ladders > 0)
                byLadder = 1 + solve_mem(heights, n, bricks, ladders - 1, i + 1, dp);

            return dp[bricks][ladders] = max(byBricks, byLadder);
        }
        return -1;
    }

    // TC : O(N * log(N))
    // SC : O(N)
    int solve_optimal(vector<int>& heights, int n, int bricks, int ladders) {
        priority_queue<int> pq;
        int i = 0;
        for (; i < n - 1; i++) {

            if (heights[i + 1] <= heights[i])
                continue;

            int diff = heights[i + 1] - heights[i];

            if (bricks >= diff) {
                bricks -= diff;
                pq.push(diff);
            }
            else if (ladders > 0){
                if (!pq.empty()) {
                    int max_past_bricks = pq.top();

                    if (max_past_bricks > diff) {
                        
                        bricks += max_past_bricks;
                        pq.pop();
                        bricks -= diff;
                        pq.push(diff);  // insert the bricks used later
                    }
                }
                ladders --;
            }
            else break;
        }

        return i;
    }
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // vector<vector<int>> dp(bricks + 1, vector<int>(ladders + 1, -1));
        // return solve_mem(heights, heights.size(), bricks, ladders, 0, dp);


        return solve_optimal(heights, heights.size(), bricks, ladders);
    }
};