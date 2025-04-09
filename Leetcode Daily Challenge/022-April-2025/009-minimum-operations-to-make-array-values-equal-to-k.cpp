// https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N)
    int approach_1(vector<int> &nums, int k) {
        unordered_set<int> st;
        for (int &num : nums) {
            if (num < k) return -1;
            st.insert(num);
        }
        return st.count(k) ? st.size() - 1 : st.size();
    }
public:
    int minOperations(vector<int>& nums, int k) {
        return approach_1(nums, k);
    }
};