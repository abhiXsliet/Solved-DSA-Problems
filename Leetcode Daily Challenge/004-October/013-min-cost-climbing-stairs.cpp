// https://leetcode.com/problems/min-cost-climbing-stairs/


#include<bits/stdc++.h>
using namespace std;

class Solution {
    int t[10001];
    
    // TC = O(N)
    // SC = O(N) -> due to recursive call stack
    int solve_mem(vector<int>& cost, int idx) {
        if (idx >= cost.size()) return 0;

        if (t[idx] != -1) return t[idx];

        int option_1 = cost[idx] + solve_mem(cost, idx+1);
        int option_2 = cost[idx] + solve_mem(cost, idx+2);

        return t[idx] = min(option_1, option_2);
    }

    // TC = O(N)
    // SC = O(1)
    int solve_tab(vector<int>& cost) {
        int n = cost.size();
        
        if (n == 2) return min(cost[0], cost[1]);

        for (int i = 2; i < n; i++) {
            cost[i] = cost[i] + min(cost[i - 1], cost[i - 2]); // modified in same array 
        }

        return min(cost[n-1], cost[n-2]);
    }

    // TC = O(N)
    // SC = O(1)
    int solve_so(vector<int>& cost) {
        int n = cost.size();
        
        int prev2 = cost[0];
        int prev1 = cost[1];

        for (int i = 2; i < n; i++) {
            int curr = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return min(prev1, prev2);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        memset(t, -1, sizeof(t));
        // return  min(solve_mem(cost, 0), solve_mem(cost, 1));

        // return solve_tab(cost);

        return solve_so(cost);
    }
};