// https://leetcode.com/problems/apply-operations-to-an-array/



#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    // TC : O(N)
    // SC : O(N) used result array to return 
    vector<int> approach_1(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        for (int i = 0; i < n - 1; i ++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        int idx = 0;
        for (int i = 0; idx < n && i < n; i ++) {
            if (nums[i]) {
                result[idx ++] = nums[i];
            }
        }
        return result;
    }

    // TC : O(N)
    // SC : O(N) used result array to return
    vector<int> approach_2(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        int idx = 0;
        for (int i = 0; i < n - 1; i ++) {
            if (nums[i] && nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            } 
            if (nums[i]) {
                result[idx ++] = nums[i];
            }
        }
        result[idx] = nums[n - 1];  // insert the last no.
        return result;
    }

    // TC : O(N)
    // SC : O(1)
    vector<int> approach_3(vector<int>& nums) {
        int n = nums.size();
        int j = 0;  // this ptr will stand at zero
        for (int i = 0; i < n; i ++) {
            if (i + 1 < n && nums[i] == nums[i + 1] && nums[i]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
            if (nums[i]) {
                if (i != j) {
                    swap(nums[i], nums[j]);
                }
                j ++;
            }
        }
        return nums;
    }
public:
    vector<int> applyOperations(vector<int>& nums) {
        // return approach_1(nums);    // BRUTE  : TWO PASS -> space to return result
        // return approach_2(nums);    // BETTER : ONE PASS -> space to return result
        return approach_3(nums);    // OPTIMAL: ONE PASS -> Inplace
    }
};