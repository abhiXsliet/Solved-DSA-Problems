// https://leetcode.com/problems/special-array-ii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(1)
    bool queryInRangeOfViolatingIdx(vector<int>& violatingIdx, int start, int end) {
        int n = violatingIdx.size();
        int low = 0, high = n - 1;
        while (low  <= high) {
            int mid  = low + (high - low) / 2;
            if (violatingIdx[mid]  < start) {
                low  = mid + 1;
            } else if (violatingIdx[mid] > end) {
                high = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }

    // TC : O(N + Q)
    // SC : O(N)
    vector<bool> approach_1(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), q = queries.size();
        vector<int> badIdx(n, 0);   // violating indices prefix sum
        
        // Build the prefix sum array (badIdx) to track consecutive even/odd pairs.
        for (int i = 1; i < n; i++) {
            if (nums[i] % 2 == nums[i - 1] % 2) {
                badIdx[i] = badIdx[i - 1] + 1;
            } else {
                badIdx[i] = badIdx[i - 1];
            }
        }

        vector<bool> result(q, 0);
        for (int i = 0; i < q; i++) {
            int sQuery = queries[i][0];
            int eQuery = queries[i][1];
            if (badIdx[eQuery] - badIdx[sQuery] == 0)
                result[i] = true;
        }
        return result;
    }

    // TC : O(N + Q)
    // SC : O(N)
    vector<bool> approach_2(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), q = queries.size();
        vector<int> rightMostValidIdx(n, 0);   // violating indices prefix sum
        
        int i = 0, j = 0;
        while (i < n) {
            if (i > j) j = i;

            while (j < n - 1 && nums[j] % 2 != nums[j + 1] % 2) j ++;

            rightMostValidIdx[i] = j;
            i ++;
        }

        vector<bool> result(q, 0);
        for (int i = 0; i < q; i++) {
            int sQuery = queries[i][0];
            int eQuery = queries[i][1];
            if (eQuery <= rightMostValidIdx[sQuery])
                result[i] = true;
        }
        return result;
    }

    // TC : O(N + Q*log(N))
    // SC : O(N)
    vector<bool> approach_3(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), q = queries.size();
        vector<int> violatingIdx;   // violating indices
        for (int i = 1; i < n; i++) {
            if (nums[i] % 2 == nums[i - 1] % 2) {
                violatingIdx.push_back(i);
            } 
        }

        vector<bool> result(q, 0);
        for (int i = 0; i < q; i++) {
            int sQuery = queries[i][0];
            int eQuery = queries[i][1];
            if (!queryInRangeOfViolatingIdx(violatingIdx, sQuery + 1, eQuery))
                result[i] = true;
        }
        return result;
    }
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        // return approach_1(nums, queries);    // prefix cnt of badIndices

        // return approach_2(nums, queries);    // keep the track of rightMostValid Idx

        return approach_3(nums, queries); 
    }
};