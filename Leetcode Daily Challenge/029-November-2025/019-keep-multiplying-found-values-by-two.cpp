// https://leetcode.com/problems/keep-multiplying-found-values-by-two/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> s(nums.begin(), nums.end());
        while (s.contains(original)) {
            original <<= 1;
        }
        return original;
    }
};