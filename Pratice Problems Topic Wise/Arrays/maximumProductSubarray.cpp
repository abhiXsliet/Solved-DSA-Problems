// https://leetcode.com/problems/maximum-product-subarray/



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix = 1; 
        int suffix = 1;
        int n = nums.size();
        int ans = INT_MIN;

        for(int i=0; i<n; i++) {
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;

            prefix = prefix * nums[i];
            suffix = suffix * nums[n-i-1];

            ans = max(ans, max(prefix, suffix));
        }
        return ans;
    }
};