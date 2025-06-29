// https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N*log(N))
    // SC : O(N)
    vector<int> approach_1(vector<int> &nums, int k) {
        int n = nums.size();

        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i ++) {
            pq.push({nums[i], i});
        }

        vector<int> result;
        while (k --) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        sort(begin(result), end(result));
        for (int &idx : result) {
            idx = nums[idx];
        }
        return result;
    }

    // TC : O(N) Average time complexity of nth_element is O(N)
    // SC : O(N)
    vector<int> approach_2(vector<int> &nums, int k) {
        int n = nums.size();

        vector<int> temp = nums;

        nth_element(begin(temp), begin(temp) + (k - 1), end(temp), greater<int>());
        
        int kthLargestEle   = temp[k - 1];
        int countKthLargest = count(begin(temp), begin(temp) + k, kthLargestEle);
        
        vector<int> result;
        for (int &num : nums) {
            if (num == kthLargestEle && countKthLargest) {
                result.push_back(num);
                countKthLargest -= 1;
            } else if (num > kthLargestEle) {
                result.push_back(num);
            }
        }
        return result;
    }
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        // return approach_1(nums, k);
        return approach_2(nums, k);
    }
};