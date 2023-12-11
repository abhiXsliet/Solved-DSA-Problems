// https://leetcode.com/problems/count-the-number-of-good-partitions/



#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int MOD = 1e9 + 7;
    int numberOfGoodPartitions(vector<int>& nums) {
        int n = nums.size();

        // map to store the last index of an element
        unordered_map<int, int> lastIdx;
        for (int i = 0; i < n; i++) {
            lastIdx[nums[i]] = i;
        }

        int i = 0;
        int j = 0;
        j = max(j, lastIdx[nums[0]]);
        
        int result = 1;

        while(i < n) {
            if (i > j) { // we got the new partation

                result = (result * 2) % MOD;
            }

            j = max(j, lastIdx[nums[i]]);
            i++;
        }
        return result;
    }
};