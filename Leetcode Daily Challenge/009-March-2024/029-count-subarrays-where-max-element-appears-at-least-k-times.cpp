// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;

    // TC : O(N)
    // SC : O(N)
    ll solve_1(vector<int>& nums, int k) {
    int n    = nums.size();
    int maxi = *max_element(begin(nums), end(nums));

    vector<int> maxIndices;
    ll cntSubArray = 0; // Change this line

    for (int i = 0; i < n; i++) {
        if (nums[i] == maxi) {
            maxIndices.push_back(i);
        }
        int size = maxIndices.size();
        if (size >= k) {
            int prevIdx = maxIndices[size - k];

            cntSubArray += (prevIdx + 1);
        }
    }
    return cntSubArray;
    }

    // TC : O(N)
    // SC : O(1)
    int solve_2(vector<int>& nums, int k) {
        int n = nums.size();

        int maxi = *max_element(begin(nums), end(nums));
        int i = 0, j = 0, cntMaxi = 0;
        ll cntSubArray = 0;

        while(j < n) {
            if (nums[j] == maxi) {
                cntMaxi ++;
            }
            while (cntMaxi >= k) {
                cntSubArray += n - j;
                if (nums[i] == maxi) {
                    cntMaxi --;
                }
                i++;
            }
            j ++;
        }
        return cntSubArray;
    }
public:
    ll countSubarrays(vector<int>& nums, int k) {
        return solve_1(nums, k);

        // return solve_2(nums, k);
    }
};