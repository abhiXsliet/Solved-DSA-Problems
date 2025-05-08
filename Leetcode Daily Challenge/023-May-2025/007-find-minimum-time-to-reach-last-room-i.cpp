// https://leetcode.com/problems/find-minimum-time-to-reach-last-room-i/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    using V = vector<int>;
    vector<vector<int>> directions {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    // TC : O(NM * log(NM))
    // SC : O(NM)
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();

        priority_queue<V, vector<V>, greater<V>> pq;
        pq.push({0, 0, 0});
        moveTime[0][0] = INT_MIN;   // visited cell

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int i = it[1];
            int j = it[2];
            int currTime = it[0];

            if (i == n - 1 && j == m - 1) {
                return currTime;
            }

            for (auto &dir : directions) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < m && moveTime[i_][j_] != INT_MIN) {
                    int time = max(currTime, moveTime[i_][j_]) + 1;
                    pq.push({time, i_, j_});
                    moveTime[i_][j_] = INT_MIN;
                }
            }
        }
        return -1;
    }
};