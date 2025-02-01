// https://leetcode.com/problems/special-array-i/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(1)
    bool approach_1(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;
        bool isEven = nums[0] % 2;
        for (int i = 2; i < n; i += 2) {
            if (nums[i] % 2 != isEven) {
                return false;
            }
        }
        bool isOdd = nums[1] % 2;
        for (int i = 3; i < n; i += 2) {
            if (nums[i] % 2 != isOdd) {
                return false;
            }
        }
        return (isEven != isOdd);
    }

    // TC : O(N) 
    // SC : O(1)
    bool approach_2(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i ++) {
            if (nums[i] % 2 == nums[i + 1] % 2) {
                return false;
            }
        }
        return true;
    }

    // TC : O(N)
    // SC : O(1)
    bool approach_3(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i ++) {
            if ((nums[i] & 1) == (nums[i + 1] & 1)) {
                return false;
            }
        }
        return true;
    }
public:
    bool isArraySpecial(vector<int>& nums) {
        // return approach_1(nums);
        // return approach_2(nums);
        return approach_3(nums);
    }
};