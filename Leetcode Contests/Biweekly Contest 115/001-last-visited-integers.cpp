// https://leetcode.com/contest/biweekly-contest-115/problems/last-visited-integers/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        vector<int> nums, res;
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            if (words[i] == "prev") {
                int k = 1;
                while (i - k >= 0 && words[i - k] == "prev") {
                    ++k;
                }
                if (k > nums.size()) {
                    res.push_back(-1);
                } else {
                    res.push_back(nums[nums.size() - k]);
                }
            } else {
                nums.push_back(stoi(words[i]));
            }
        }
        return res;
    }
};