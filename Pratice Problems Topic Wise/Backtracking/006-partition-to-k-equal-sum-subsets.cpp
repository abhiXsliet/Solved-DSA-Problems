// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int n;
    int visited[17];

    bool solve(vector<int> &nums, int k, int &subsetSum, int currSum, int start) {
        if (k == 1) return true;
        
        if (currSum == subsetSum) {
            return solve(nums, k - 1, subsetSum, 0, 0);
        }

        for (int i = start; i < n; i ++) {
            if (visited[i] || (currSum + nums[i] > subsetSum))
                continue;

            currSum += nums[i];
            visited[i] = 1;

            if (solve(nums, k, subsetSum, currSum, i + 1))
                return true;

            currSum -= nums[i];
            visited[i] = 0;
        }

        return false;
    }
public:
    // TC : O(N * 2^N)
    // SC : O(N)
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        n = nums.size();
        int total = accumulate(begin(nums), end(nums), 0);
        
        if (total % k || k > n) return false;
        
        int subsetSum = (total / k);
        memset(visited, 0, sizeof(visited));
        
        return solve(nums, k, subsetSum, 0, 0);
    }
};