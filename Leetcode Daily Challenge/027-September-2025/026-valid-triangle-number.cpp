// https://leetcode.com/problems/valid-triangle-number/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:    
    // TC : O(N^2 * log(N))
    // SC : O(1)
    int approach_1(vector<int> &nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        int result = 0;
        for (int i = 0; i < n - 2; i ++) {
            for (int j = i + 1; j < n - 1; j ++) {
                int val1 = nums[i], val2 = nums[j];
                int idx  = lower_bound(begin(nums) + j, end(nums), (val1 + val2)) - begin(nums);
                int val  = (idx - j - 1);
                result  += (val) > 0 ? val : 0;
            }
        }
        return result;
    }

    // TC : O(N^2)
    // SC : O(1)
    int approach_2(vector<int> &nums) {
        int n = nums.size();
        
        sort(begin(nums), end(nums));

        int result = 0;
        for (int k = n - 1; k >= 2; k --) {
            int i = 0, j = k - 1;
            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    result += (j - i);
                    j --;
                } else i ++;
            }
        }
        return result;
    }
public:
    int triangleNumber(vector<int>& nums) {
        // return approach_1(nums);
        return approach_2(nums);
    }
};