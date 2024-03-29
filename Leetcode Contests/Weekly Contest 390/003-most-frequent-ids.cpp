// https://leetcode.com/problems/most-frequent-ids/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        unordered_map<int, long long> count;
        priority_queue<pair<long long, int>> pq;
        vector<long long> ans(nums.size());
        
        for (int i = 0; i < nums.size(); ++i) {
            count[nums[i]] += freq[i];
            if (count[nums[i]] > 0) {
                pq.push({count[nums[i]], nums[i]});
            }
            
            while (!pq.empty() && count[pq.top().second] != pq.top().first) {
                pq.pop();
            }
            
            ans[i] = pq.empty() ? 0 : pq.top().first;
        }
        
        return ans;
    }
};
