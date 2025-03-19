// https://leetcode.com/problems/divide-array-into-equal-pairs/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N)
    bool approach_1(vector<int> &nums) {
        int n = nums.size();

        unordered_map<int, int> freq;
        for (int &num : nums) {
            freq[num] ++;
        }

        int cntPairs = 0;
        for (auto &it : freq) {
            if (it.second % 2 == 0) {
                cntPairs += (it.second / 2);
            }
        }
        return cntPairs == n/2;
    }

    // TC : O(N*log(N))
    // SC : O(1)
    bool approach_2(vector<int> &nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        int currEqualCnt = 1, cntPairs = 0;

        for (int i = 0; i < n; i ++) {
            if (i + 1 < n && nums[i] == nums[i + 1]) {
                currEqualCnt += 1;
            } else {
                cntPairs += (currEqualCnt / 2);
                currEqualCnt = 1;
            }
        }
        return cntPairs == n/2;
    }
    
    // TC : O(N)
    // SC : O(501) ~= O(1)
    bool approach_3(vector<int> &nums) {
        int n = nums.size();
        vector<bool> freq(501, 0);

        for (int &num : nums) {
            freq[num] = !freq[num];
        }

        for (bool f : freq) {
            if (f) return false;
        }

        return true;
    }
public:
    bool divideArray(vector<int>& nums) {
        // return approach_1(nums);
        // return approach_2(nums); // sorting
        return approach_3(nums); // Using boolean of 501 length
    }
};