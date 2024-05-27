// https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N*log(N))
    int approach_1(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        for(int x = 0; x <= n; x ++) {
            int i = lower_bound(begin(nums), end(nums), x) - begin(nums);
            if(n - i == x) {
                return x;
            }
        }
        return -1;
    }
public:
    int specialArray(vector<int>& nums) {
        return approach_1(nums);
    }
};