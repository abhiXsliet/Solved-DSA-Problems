// https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    int reversed(int num) {
        int revNum = 0;
        while (num) {
            revNum = revNum * 10 + num % 10;
            num /= 10;
        }
        return revNum;
    }

    // TC : O(N * log(N))
    // SC : O(N)
    int approach_1(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, set<int>> mpp;
        for (int i = n - 1; i >= 1; i --) {
            mpp[nums[i]].insert(i);
        }

        int minD = INT_MAX;
        for (int i = 0; i < n - 1; i ++) {
            int val = reversed(nums[i]);
            if (mpp.count(val)) {
                auto idx = mpp[val].begin();
                if (*idx == i) idx ++;
                if (idx != mpp[val].end()) 
                    minD = min(minD, *idx - i);
            }
            if (mpp[nums[i]].count(i)) mpp[nums[i]].erase(i); 
            if (mpp[nums[i]].size() == 0) mpp.erase(nums[i]);
        }
        return minD == INT_MAX ? -1 : minD;
    }

    // TC : O(N*log(N))
    // SC : O(N)
    int approach_2(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<int>> mpp;
        for (int i = 1; i < n; i ++) {
            mpp[nums[i]].push_back(i);
        }

        int minD = INT_MAX;
        for (int i = 0; i < n; i ++) {
            int val = reversed(nums[i]);
            if (!mpp.count(val)) continue;

            vector<int> &indices = mpp[val];
            int idx = lower_bound(begin(indices), end(indices), i) - begin(indices);

            if (idx < indices.size() && indices[idx] == i) idx ++;

            if (idx < indices.size()) {
                minD = min(minD, indices[idx] - i);
            }
        }
        return minD == INT_MAX ? -1 : minD;
    }
public:
    int minMirrorPairDistance(vector<int>& nums) {
        // return approach_1(nums);
        return approach_2(nums);
    }
};