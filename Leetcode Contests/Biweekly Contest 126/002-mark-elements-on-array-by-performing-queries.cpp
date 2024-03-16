// https://leetcode.com/contest/biweekly-contest-126/problems/mark-elements-on-array-by-performing-queries/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;
    typedef pair<int, int> P;
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {        
        int n = nums.size(), m = queries.size();
        
        ll sum = accumulate(begin(nums), end(nums), 0LL);
        unordered_set<int> vis;
        priority_queue<P, vector<P>, greater<P>> pq;
        
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }
        
        vector<ll> ans(m);
        
        for (int i = 0; i < m; i++) {
            int idx = queries[i][0];
            int k   = queries[i][1];
            
            if (vis.find(idx) == vis.end()) {
                sum -= nums[idx];
                vis.insert(idx);
            }
            
            while (k && !pq.empty()) {
                int val = pq.top().first;
                int ind = pq.top().second;
                pq.pop();
                
                if (vis.find(ind) != vis.end()) continue;
                else {
                    sum -= val;
                    vis.insert(ind);
                    k --;
                }
            }
            ans[i] = sum;
        }
        return ans;
    }
};
