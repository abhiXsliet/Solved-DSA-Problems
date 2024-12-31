// https://leetcode.com/problems/minimum-cost-for-tickets/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> t;

    int solve(vector<int>& days, vector<int>& cost, int idx) {
        if (idx >= days.size()) return 0;

        if (t[idx] != -1) return t[idx];

        // 01 - Day Pass
        int choice_1 = cost[0] + solve(days, cost, idx + 1);

        // 07 - Days Pass
        int i = idx;
        while (i < days.size() && days[i] < days[idx] + 7) i++;
        int choice_2 = cost[1] + solve(days, cost, i);

        // 30 - Days Pass
        int j = idx;
        while (j < days.size() && days[j] < days[idx] + 30) j++;
        int choice_3 = cost[2] + solve(days, cost, j);

        return t[idx] = min(choice_1, min(choice_2, choice_3));
    }

    // TC : O(N)
    // SC : O(N) Where N = Size of days array
    int approach_1(vector<int>& days, vector<int>& costs) {
        t.resize(days.size(), -1);
        return solve(days, costs, 0);
    }
    
    // TC : O(N)
    // SC : O(N)
    int approach_2(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1, 0);

        for (int k = n - 1; k >= 0; k--) {
            // 01 - Day Pass
            int choice_1 = costs[0] + dp[k + 1];

            // 07 - Days Pass
            int i = k;
            while (i < n && days[i] < days[k] + 7) i++;
            int choice_2 = costs[1] + dp[i];

            // 30 - Days Pass
            int j = k;
            while (j < n && days[j] < days[k] + 30) j++;
            int choice_3 = costs[2] + dp[j];

            dp[k] = min(choice_1, min(choice_2, choice_3));
        }
        return dp[0];
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // return approach_1(days, costs);

        return approach_2(days, costs);
    }
};
