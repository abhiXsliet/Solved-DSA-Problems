// https://leetcode.com/problems/arithmetic-slices-ii-subsequence/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(2^n)
    // SC : O(N) -> Recursive depth
    long long solve_rec(vector<int>& nums, int n, int idx, vector<int>& subseq, int& result) {
        // we got the one subsequence of len >= 3 
        if (subseq.size() >= 3) {
            result ++;
        }

        // Iterate over each each elements from idx
        for (int i = idx; i < n; ++i) {
            // diff b/w curr & last element of subsequence
            // is same as diff b/w the last two elements of the subsequence
            // (i.e., the current element can extend the existing slice)
            if (subseq.size() < 2 || 
               (long)nums[i] - (long)subseq.back() == 
               (long)subseq[subseq.size() - 1] - (long)subseq[subseq.size() - 2]) {
                
                subseq.push_back(nums[i]);
                solve_rec(nums, n, i + 1, subseq, result);
                subseq.pop_back();
            }
        }
        return result;
    }

    // TC : O(N*N)
    // SC : O(N)
    int solve_way_1(vector<int>& nums, int n) {
        int result = 0;

        // array of map
        unordered_map<long, int> mpp[n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                
                long diff = (long)nums[i] - nums[j];

                auto it = mpp[j].find(diff);

                int cnt_at_j = it == mpp[j].end() ? 0 : it -> second;

                mpp[i][diff] += cnt_at_j + 1;

                result += cnt_at_j;
            }
        }

        return result;
    }

    // TC : O(N*N)
    // SC : O(N)
    int solve_way_2(vector<int>& nums, int n) {
        vector<unordered_map<int, int>> dp(n);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long diff = long(nums[i]) - long(nums[j]);

                if (diff < INT_MIN || diff > INT_MAX) continue;

                int d = (int)diff;

                dp[i][d] += 1;

                if (dp[j].count(d) > 0) {

                    dp[i][d] += dp[j][d];

                    res += dp[j][d];
                }
            }
        }
        return res;
    }
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        // vector<int> subseq;
        // int result = 0;
        // return solve_rec(nums, nums.size(), 0, subseq, result);

        return solve_way_1(nums, nums.size());

        // return solve_way_2(nums, nums.size());
    }
};