// https://leetcode.com/problems/minimum-index-of-a-valid-split/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    pair<int, int> getMajorityOptimized(vector<int> &nums, int n) {
        int majEle = nums[0], majCnt = 1;
        for (int i = 1; i < n; i ++) {
            if (nums[i] == majEle) {
                majCnt += 1;
            } else {
                majCnt -= 1;
                if (majCnt == 0) {
                    majEle = nums[i];
                    majCnt = 1;
                }
            }
        }
        majCnt = 0;
        for (int i = 0; i < n; i ++) {
            if (nums[i] == majEle) {
                majCnt += 1;
            }
        }
        return {majEle, majCnt};
    }

    int solve(vector<int> &nums, int n, int majEle, int majFreq) {
        int leftMaj = 0;
        int validIdx = -1;
        for (int i = 0; i < n; i ++) {
            if (nums[i] == majEle) {
                leftMaj  += 1;
            }
            int rightMaj = majFreq - leftMaj;
            if ((2 * leftMaj > (i + 1)) && (2 * rightMaj >= (n - i))) {
                validIdx = i;
                break;
            }
        }
        return validIdx;
    }

    pair<int, int> getMajority(vector<int> &nums, int n) {
        unordered_map<int, int> mpp;
        for (int num : nums) mpp[num] ++;
        int majEle = -1, majFreq = 0;
        for (auto &it : mpp) {
            if (it.second > majFreq) {
                majFreq = it.second;
                majEle  = it.first;
            }
        }
        return {majEle, majFreq};
    }

    // TC : O(N)
    // SC : O(N)
    int approach_1(vector<int> &nums) {
        int n = nums.size();

        int majEle  = getMajority(nums, n).first;
        int majFreq = getMajority(nums, n).second;
        
        return solve(nums, n, majEle, majFreq);
    }

    // TC : O(N)
    // SC : O(1)
    int approach_2(vector<int> &nums) {
        int n = nums.size();

        int majEle  = getMajorityOptimized(nums, n).first;
        int majFreq = getMajorityOptimized(nums, n).second;
        
        return solve(nums, n, majEle, majFreq);
    }
public:
    int minimumIndex(vector<int>& nums) {
        // return approach_1(nums);
        return approach_2(nums);    // optimized getMajority fn. to O(1) space
    }
};