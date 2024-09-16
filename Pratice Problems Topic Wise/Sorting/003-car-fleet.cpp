// https://leetcode.com/problems/car-fleet/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(M*log(M))
    // SC : O(1)
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int m = position.size();
        int n = speed.size();

        vector<pair<int, double>> store;   // {pos, time}
        for (int i = 0; i < m; i ++) {
            double time = (target - position[i]) / (double)speed[i];
            store.push_back({position[i], time});
        }

        sort(begin(store), end(store));

        int cntCarFleet       = 0;
        double minTimeToReach = 0.0;

        for (int i = m - 1; i >= 0; i --) {
            double currT = store[i].second;     

            // new fleet : every time we encounter a greater time than previous 
            if (currT > minTimeToReach) {   
                cntCarFleet ++;
                minTimeToReach = currT;
            }
        }

        return cntCarFleet;
    }
};