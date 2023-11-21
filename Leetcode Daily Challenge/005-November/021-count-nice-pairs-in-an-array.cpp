// https://leetcode.com/problems/count-nice-pairs-in-an-array/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(log(num)) -> Ignored if small value 
    int rev(int num) {
        int ans = 0;
        while (num > 0) {
            int rem = num % 10;
            ans = ans * 10 + rem;
            num = num / 10;
        }
        return ans;
    }
public:
    int MOD = 1e9 + 7;
    // TC = O(N * log(num)) -> log(num) ignored if small value
    // SC = O(N)
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] - rev(nums[i]);
        }

        unordered_map<int, int>mpp;
        int result = 0;

        for (int i = 0; i < n; i++) {
            result = (result + mpp[nums[i]]) % MOD;

            mpp[nums[i]]++;
        }

        return result;
    }
};