// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> vec(n, 0); // stores the cumm_sum till index i
        deque<int> dq;          // stores the indices of cumm_sum in increasing order
        long long sum = 0;
        int i = 0, j = 0, res = INT_MAX;
        while (j < n) {
            if (j == 0) {
                vec[j] = nums[j];
            } else {
                vec[j] = vec[j - 1] + nums[j];
            }

            if (vec[j] >= k) {
                res = min(res, j + 1);  // 'i' is at 0
            }

            while (!dq.empty() && vec[j] - vec[dq.front()] >= k) {
                res = min(res, j - dq.front());
                dq.pop_front();
            }

            while (!dq.empty() && vec[j] <= vec[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(j);
            j ++;
        }
        return res == INT_MAX ? -1 : res;
    }
};