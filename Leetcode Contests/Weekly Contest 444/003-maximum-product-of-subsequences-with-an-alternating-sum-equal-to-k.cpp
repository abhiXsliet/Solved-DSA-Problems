// https://leetcode.com/contest/weekly-contest-444/problems/maximum-product-of-subsequences-with-an-alternating-sum-equal-to-k/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int n, k, limit;
    unordered_map<int, unordered_map<int, unordered_map<int, unordered_map<int, int>>>> mpp;

    int solve(vector<int> &nums, int i, int flag, int sum, int prod) {
        if (i == n) {
            if (flag != 0 && sum == k && prod <= limit) // flag == 0 : empty subseq
                return prod;
            return -1;
        }

        if (mpp.count(i) && mpp[i].count(flag) && mpp[i][flag].count(sum) && mpp[i][flag][sum].count(prod))
            return mpp[i][flag][sum][prod];

        int ans = solve(nums, i + 1, flag, sum, prod);
        
        if (flag == 0) {    // flag == 0 => 1st elment : add in sum
            ans = max(ans, solve(nums, i + 1, 1, sum + nums[i], nums[i]));
        } else if (flag == 1) { // 2nd element : subract from sum (alternate sign for 2nd element)
            ans = max(ans, solve(nums, i + 1, 2, sum - nums[i], min(prod * nums[i], limit + 1)));
        } else {  // similarly alternate sign for 3rd element
            ans = max(ans, solve(nums, i + 1, 1, sum + nums[i], min(prod * nums[i], limit + 1)));
        }

        return mpp[i][flag][sum][prod] = ans;
    }

    // TC : O(N * 3 * sum * limit)
    // SC : O(N * 3 * sum * limit)
    int top_down(vector<int> &nums) {
        int sum = accumulate(begin(nums), end(nums), 0);
        if (k > sum || k < -sum) return -1;
        mpp.clear();
        return solve(nums, 0, 0, 0, 0);
    }
public:
    int maxProduct(vector<int>& nums, int k, int limit) {
        n = nums.size();
        this -> k = k;
        this -> limit = limit;

        return top_down(nums);
    }
};