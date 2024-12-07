// https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isPossible(vector<int>& nums, int mid, int maxOpr) {
        int cntOpr = 0;
        for (int &num : nums) {
            int opr = num / mid;
            if (num % mid == 0) {
                opr -= 1;
            }
            cntOpr += opr;
        }
        return cntOpr <= maxOpr;
    }
public:
    // TC : O(N*log(N))
    // SC : O(1)
    int minimumSize(vector<int>& nums, int maxOperations) {
        sort(begin(nums), end(nums));
        int low = 1, high = *max_element(begin(nums), end(nums));
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(nums, mid, maxOperations)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};