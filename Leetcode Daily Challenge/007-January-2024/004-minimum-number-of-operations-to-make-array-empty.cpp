// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int findMinimumXY(int n) {
        for (int x = 0; x <= n; x++) {
            int y = (n - 2 * x) / 3;

            if (n == (2 * x + 3 * y)) {
                return x + y;
            }
        }
        return -1; // No solution found
    }

    // TC : O(N)
    // SC : O(N)
    int solve_approach_1(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        int a = 0;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            int val = it->second;
            if (findMinimumXY(val) == -1)
                return -1;
            a += findMinimumXY(val);
        }
        return a;
    }

    // TC : O(N)
    // SC : O(N)
    int solve_approach_2(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }
        
        int result = 0;
        for (auto &it : mp) {
            if (it.second == 1)
                return -1;

            result += ceil((double)it.second/3);
        }
        return result;
    }
public:
    int minOperations(vector<int>& nums) {
        // return solve_approach_1(nums);

        return solve_approach_2(nums);
    }
};