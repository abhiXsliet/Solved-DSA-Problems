// https://leetcode.com/contest/biweekly-contest-114/problems/minimum-number-of-operations-to-make-array-empty/



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

public:
    int minOperations(vector<int>& nums) {
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
};
