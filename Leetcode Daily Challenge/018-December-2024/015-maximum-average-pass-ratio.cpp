// https://leetcode.com/problems/maximum-average-pass-ratio/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef pair<double, int> P;

    double getGainedRatio(int pass, int total) {
        double currRatio = (double) pass / total;
        double newRatio  = ((double) pass + 1) / (total + 1);
        return newRatio - currRatio;
    }

    // TC : O(N*log(N))
    // SC : O(N)
    double approach_1(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        // Prioritize classes with max-gain
        priority_queue<P> pq;   // Catch : taking minimum ratio of each classes and increment it is wrong
        for (int i = 0; i < n; i ++) {
            double gainRatio = getGainedRatio(classes[i][0], classes[i][1]);
            pq.push({gainRatio, i});
        }

        while (extraStudents --) {
            P it = pq.top();
            pq.pop();

            int idx = it.second;
            classes[idx][0] ++;
            classes[idx][1] ++;

            double gainRatio = getGainedRatio(classes[idx][0], classes[idx][1]);
            pq.push({gainRatio, idx});
        }

        double maxRatio = 0.0;
        for (auto& cls : classes) {
            maxRatio += (double)cls[0] / cls[1];
        }
        return maxRatio/n;
    }
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        return approach_1(classes, extraStudents);
    }
};