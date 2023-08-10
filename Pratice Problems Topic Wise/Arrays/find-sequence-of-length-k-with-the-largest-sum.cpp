// https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> minHeap;
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < k; i++) {
            minHeap.push({nums[i], i});
        }

        for(int i = k; i < n; i++) {
            if(nums[i] > minHeap.top().first) {
                minHeap.pop();
                minHeap.push({nums[i], i});
            }
        }

        vector<pair<int, int>>store;
        while(!minHeap.empty()) {
            store.push_back(minHeap.top());
            minHeap.pop();
        }

        sort(store.begin(), store.end(), [&](pair<int, int>& a, pair<int, int>& b) {
            return a.second < b.second;
        });

        for(auto& i : store) {
            ans.push_back(i.first);
        }
        
        return ans;
    }
};