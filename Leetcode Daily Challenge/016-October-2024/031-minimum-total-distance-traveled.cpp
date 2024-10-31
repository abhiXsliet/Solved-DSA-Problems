// https://leetcode.com/problems/minimum-total-distance-traveled/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Greedy Fails here : robot = [9,11,99,101], factory = [[10,1],[7,1],[14,1],[100,1],[96,1],[103,1]]

    typedef long long ll;

    // TC : O(M * N)
    // SC : O(M * N) 
    ll solve(vector<int> & robot, vector<int>& position, int i, int j, vector<vector<ll>>& dp) {
        if (i >= robot.size()) return 0;
        if (j >= position.size()) return 1e12;

        if (dp[i][j] != -1) return dp[i][j];

        ll skip = solve(robot, position, i, j + 1, dp);
        ll take = abs(robot[i] - position[j]) + solve(robot, position, i + 1, j + 1, dp);

        return dp[i][j] = min(skip, take);
    }

    // TC : O(M*log(M) + N*log(N))
    // SC : O(N)
    ll mem(vector<int>& robot, vector<vector<int>>& factory) {
        sort(begin(robot), end(robot));

        vector<int> position;
        for (vector<int>& f : factory) {
            int pos = f[0];
            int lim = f[1];
            for (int j = 0; j < lim; j ++) {
                position.push_back(pos);
            }
        }
        sort(begin(position), end(position));
        
        int m = robot.size(), n = position.size();
        vector<vector<ll>> dp(m + 1, vector<ll>(n + 1, -1));
        return solve(robot, position, 0, 0, dp);
    }
public:
    ll minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        return mem(robot, factory);
    }
};