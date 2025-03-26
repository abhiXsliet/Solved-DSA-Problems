// https://leetcode.com/problems/choose-k-elements-with-maximum-sum/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;
    typedef pair<ll, ll> P;
public:
    // TC : O(N*log(N))
    // SC : O(N)
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<P, vector<P>, greater<P>> pq; 
        for (int i = 0; i < nums1.size(); i ++) {
            pq.push({(ll)nums1[i], (ll)i});
        }

        priority_queue<ll> mx; 
        priority_queue<ll, vector<ll>, greater<ll>> mn; 
        ll topKSum = 0;
        vector<ll> result(nums1.size(), 0);
        int prevEl = -1, prevIdx = -1;
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            ll ele = it.first;
            ll idx = it.second;

            if (prevEl == ele) {
                result[idx] = result[prevIdx];
            } else {
                result[idx] = topKSum;
            }

            topKSum += nums2[idx];
            mn.push(nums2[idx]);
            
            if (mn.size() > k) {
                topKSum -= mn.top();
                mn.pop();
            }
            prevEl = ele;
            prevIdx = idx;
        }

        return result;
    }
};