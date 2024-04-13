// https://leetcode.com/problems/two-city-scheduling/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N*log(N))
    // SC : O(1)
    int approach_1(vector<vector<int>>& costs, int n) {
        auto cmp = [&](vector<int> a, vector<int> b) {
            return a[1] - a[0] > b[1] - b[0];
        };
        sort(begin(costs), end(costs), cmp);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += i < n/2 ? costs[i][0] : costs[i][1];
        }
        return ans;
    }

    // TC : O(N*log(N))
    // SC : O(N)
    int approach_2(vector<vector<int>>& costs, int n) {
        priority_queue<pair<int, int>> pq;
        
        for (int i = 0; i < n; i++) {
            int diff = costs[i][1] - costs[i][0];
            pq.push({diff, i});
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int topEl = pq.top().first; 
            int topId = pq.top().second;
            pq.pop();
            ans += i < n/2 ? costs[topId][0] : costs[topId][1];
        }
        return ans;
    }
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // return approach_1(costs, costs.size());

        return approach_2(costs, costs.size()); // NO ARRAY MODIFY
    }
};