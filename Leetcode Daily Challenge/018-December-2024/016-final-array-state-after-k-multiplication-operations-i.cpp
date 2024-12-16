// https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/?envType=daily-question&envId=2024-12-16




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef pair<int, int> P;
    
    // TC : O(N*log(N))
    // SC : O(N)
    vector<int> approach_1(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        priority_queue<P, vector<P>, greater<P>> pq;
        for (int i = 0; i < n; i ++) {
            pq.push({nums[i], i});
        }
        while (k --) {
            P it = pq.top();
            pq.pop();
            pq.push({it.first * multiplier, it.second});
        }

        vector<int> result(n, 0);
        while (!pq.empty()) {
            P it = pq.top();
            pq.pop();
            result[it.second] = it.first;
        }
        return result;
    }
public:    
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        return approach_1(nums, k, multiplier);
    }
};