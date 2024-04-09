// https://leetcode.com/problems/minimum-operations-to-make-median-of-array-equal-to-k/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;
    
    // TC : O(N*log(N)) Where N = Size of nums array
    // SC : O(1)
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        int n  = nums.size();

        sort(begin(nums), end(nums));
        
        int idx  = floor(n/2);
    
        if (nums[idx] == k) 
            return 0LL;

        ll oper   = (ll)abs(k - nums[idx]);

        for (int i = n - 1; i >= 0; i--) {
            if (i > idx && nums[i] < k) {
                oper += (k - nums[i]);
            }
            if (i < idx && nums[i] > k) {
                oper += (nums[i] - k);
            }
        }
        
        return oper;
    }
};