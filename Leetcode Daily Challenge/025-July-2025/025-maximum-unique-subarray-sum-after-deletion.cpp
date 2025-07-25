// https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N)
    int approach_1(vector<int>& nums) {
        unordered_set<int> st;
        int negMaxi = INT_MIN;
        int maxSum  = 0;
        
        for (int num : nums) {
            if (num > 0 && !st.count(num)) {
                st.insert(num);
                maxSum += num;
            } else {
                negMaxi = max(negMaxi, num);
            }
        }

        return maxSum == 0 ? negMaxi : maxSum;
    }

    // TC : O(N)
    // SC : O(1)
    int approach_2(vector<int>& nums) {
        vector<int> freq(101, -1);
        int negMaxi = INT_MIN;
        int maxSum  = 0;
        
        for (int num : nums) {
            if (num > 0) {
                if (freq[num] == -1) {
                    freq[num] = 1;
                    maxSum += num;
                }
            } else {
                negMaxi = max(negMaxi, num);
            }
        }

        return maxSum == 0 ? negMaxi : maxSum;
    }
public:
    int maxSum(vector<int>& nums) {
        // return approach_1(nums);
        return approach_2(nums);
    }
};