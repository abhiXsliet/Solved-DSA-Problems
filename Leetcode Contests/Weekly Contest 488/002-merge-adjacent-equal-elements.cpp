// https://leetcode.com/problems/merge-adjacent-equal-elements/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;
    vector<ll> mergeAdjacent(vector<int>& nums) {
        int n = nums.size();
        vector<ll> ans;
        int i = 0, j = 1;
        while (i < n) {
            if (j < n && nums[i] == nums[j]) {
                ll sum = 2 * nums[i];
                j ++;
                while (!ans.empty() && ans.back() == sum) {
                    sum *= 2;
                    ans.pop_back();
                }
                while (j < n && sum == nums[j]) {
                    j ++;
                    sum *= 2;
                    while (!ans.empty() && ans.back() == sum) {
                        sum *= 2;
                        ans.pop_back();
                    }
                }
                ans.push_back(sum);
                i  = j;
                j += 1;
            } else {
                ans.push_back(nums[i]);
                i += 1, j += 1;
            }
        }
        return ans;
    }
};

// [2,2,4,1,1,2,1,1,2,4,4]