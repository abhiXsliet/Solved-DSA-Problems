// https://leetcode.com/problems/minimum-operations-to-make-array-equal-to-target/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;

    // TC : O(N)
    // SC : O(N)
    ll approach_1(vector<int>& nums, vector<int>& target) {
        int n = nums.size();

        vector<int> diff(n, 0);
        for (int i = 0; i < n; i ++) {
            diff[i] = target[i] - nums[i];
        }

        ll result = 0;
        int prev  = 0;
        int curr  = 0;

        for (int i = 0; i < n; i ++) {
            curr = diff[i];

            // sign changing or not?
            if ((prev < 0 && curr > 0) || (prev > 0 && curr < 0)) {
                result += abs(curr);

            } else if (abs(curr) > abs(prev)) {
                result += abs(curr - prev);
            }
            // else (abs(curr) <= abs(prev)) do nothing

            prev = curr;
        }

        return result;
    }

    // TC : O(N)
    // SC : O(1)
    ll approach_2(vector<int>& nums, vector<int>& target) {
        int n = nums.size();

        ll result = 0;
        int prev  = 0;
        int curr  = 0;

        for (int i = 0; i < n; i ++) {
            curr = target[i] - nums[i];

            // sign changing or not?
            if ((prev < 0 && curr > 0) || (prev > 0 && curr < 0)) {
                result += abs(curr);

            } else if (abs(curr) > abs(prev)) {
                result += abs(curr - prev);
            }
            // else (abs(curr) <= abs(prev)) do nothing

            prev = curr;
        }

        return result;
    }
public:
    ll minimumOperations(vector<int>& nums, vector<int>& target) {
        // return approach_1(nums, target);

        return approach_2(nums, target);
    }
};