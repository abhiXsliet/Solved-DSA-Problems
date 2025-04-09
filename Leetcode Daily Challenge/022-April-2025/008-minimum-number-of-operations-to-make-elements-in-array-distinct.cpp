// https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N)
    int approach_1(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;

        int idx = 0; // erase index
        int k = 3;   // erase cnt
        int operationsCnt = 0;
        for (int i = 0; i < n; i ++) {
            while (mpp[nums[i]] >= 1) {
                while (idx < n && k --) {
                    mpp[nums[idx ++]] --;
                } 
                k = 3;
                operationsCnt ++;
            }
            mpp[nums[i]] ++;
        }
        return operationsCnt;
    }

    // TC : O(N)
    // SC : O(N)
    int approach_2(vector<int> &nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        int lastOcc = -1;
        for (int i = 0; i < n; i ++) {
            if (mpp.count(nums[i])) {
                lastOcc = max(lastOcc, mpp[nums[i]]);
            } 
            mpp[nums[i]] = i;
        }
        
        int operCnt = 0;
        if (lastOcc == -1) return operCnt;
        lastOcc += 1;
        operCnt += (lastOcc / 3);
        operCnt += (lastOcc % 3) ? 1 : 0;
        return operCnt;
    }
public:
    int minimumOperations(vector<int>& nums) {
        // return approach_1(nums); // Simulation
        return approach_2(nums); // track second last occurance of duplicates
    }
};