// https://leetcode.com/problems/sliding-window-maximum/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    /*
        // Approach - 1
        // TC = O(n^2)
        // SC = O(1)
        vector<int> ans;
        int n = nums.size();
        for(int i = 0; i <= n - k; i++) {
            int maxi = INT_MIN;
            for(int j = i; j < i + k; j++) {
                maxi = max(maxi, nums[j]);
            }
            ans.push_back(maxi);
        }
        return ans;

     */


    /* 
        // Approach - 2
        // TC = O(n * log(k))
        // SC = O(k)
        vector<int> ans;
        int n = nums.size();
        priority_queue<pair<int, int>> pq;  // max-heap
        
        for(int i = 0; i < k; i++)
            pq.push({nums[i], i});

        ans.push_back(pq.top().first);

        for(int i = k; i < n; i++) {
            pq.push({nums[i], i});

            while(pq.top().second <= i - k) pq.pop();
            ans.push_back(pq.top().first);
        }
        return ans;
     */

        // Approach - 3
        // TC = O(n)
        // SC = O(k)
        deque<int> dq;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            if (!dq.empty() && dq.front() == i - k) dq.pop_front();

            while(!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            dq.push_back(i);
            if (i >= k - 1) 
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};