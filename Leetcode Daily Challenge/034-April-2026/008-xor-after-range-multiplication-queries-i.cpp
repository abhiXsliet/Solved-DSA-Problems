// https://leetcode.com/problems/xor-after-range-multiplication-queries-i/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int M = 1e9 + 7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int q = queries.size();

        for (vector<int> &query : queries) {
            int l = query[0], r = query[1];
            int k = query[2], v = query[3];

            for (int idx = l; idx <= r; idx += k) {
                nums[idx] = (1LL * nums[idx] * v) % M;
            }
        }

        int ans = 0;
        for (int &v : nums) ans ^= v;
        return ans;
    }
};