// https://leetcode.com/problems/check-if-array-is-good/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

bool isGood(vector<int>& nums) {
/* 
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int maxi = INT_MIN;
    for(int i = 0; i < n; i++) {
        if(nums[i] > maxi)
            maxi = max(maxi, nums[i]);
    }
    if(n == maxi + 1) {
        if(nums[n-1] == nums[n-2])
            return true;
    }
    return false;
 */

    // different writing style
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n-1; i++) {
            if(nums[i] != i+1)
                return false;
        }
        return (nums[n-1] == n-1);
    }
};