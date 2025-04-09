// https://leetcode.com/contest/weekly-contest-444/problems/minimum-pair-removal-to-sort-array-i/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isAscending(vector<int> &nums) {
        int n = nums.size();
        for (int i = 1; i < n; i ++) {
            if (nums[i - 1] > nums[i])
                return false;
        }
        return true;
    }
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        int cntOper = 0;
        vector<int> temp;
        while (true) {
            temp.clear();

            if (isAscending(nums)) {
                return cntOper;
            }
            
            int idx  = 0;
            int minS = nums[0] + nums[1];
            for (int i = 0; i < nums.size() - 1; i ++) {
                int sum = nums[i] + nums[i + 1];
                if (minS > sum) {
                    minS = sum;
                    idx = i;
                }
            }

            if (nums.size() == 1) return cntOper;

            for (int i = 0; i < nums.size(); i ++) {
                if (i == idx) {
                    temp.push_back(minS);
                    i ++;
                    continue;
                }  
                temp.push_back(nums[i]);
            }
            cntOper += 1;
            nums = temp;
        }
        return cntOper;
    }
};