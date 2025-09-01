// https://leetcode.com/problems/maximum-average-pass-ratio/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using T = pair<double, pair<int, int>>;

    // TC : O(N*log(N))
    // SC : O(N)
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto gain = [&](int pass, int total) {
            return ((double)(pass + 1) / (total + 1)) - ((double)pass / total);
        };

        priority_queue<T> pq;

        for (vector<int> &cls : classes) {
            int pass  = cls[0];
            int total = cls[1];
            pq.push({gain(pass, total), {pass, total}});
        }

        while (extraStudents --) {
            auto it = pq.top();
            pq.pop();

            double maxGain = it.first;
            int pass  = it.second.first;
            int total = it.second.second;

            pass ++, total ++;
            pq.push({gain(pass, total), {pass, total}});
        }

        double totalRatio = 0.0;
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            
            int pass  = it.second.first;
            int total = it.second.second;
            totalRatio += ((double)pass / total);
        }

        return (totalRatio / classes.size());
    }
};