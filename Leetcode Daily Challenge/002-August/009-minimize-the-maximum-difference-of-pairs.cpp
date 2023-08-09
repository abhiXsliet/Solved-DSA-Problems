// https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/



#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isValid(vector<int>& nums, int p, int mid) {
        int i = 0;
        int n = nums.size();
        int cntPair = 0;
        while(i < n -1) {
            if( abs(nums[i] - nums[i + 1]) <= mid ) {
                cntPair++;
                i+=2;

            } else {
                i++;
            }
        }
        return cntPair >= p;
    }
    
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int l = 0;
        int r = nums[n - 1] - nums[0];
        int result = INT_MIN;

        while(l <= r) {
            int mid = l + (r - l) / 2;

            if(isValid(nums, p, mid)) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }
};