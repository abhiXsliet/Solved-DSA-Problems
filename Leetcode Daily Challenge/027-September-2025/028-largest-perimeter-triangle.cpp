// https://leetcode.com/problems/largest-perimeter-triangle/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isPossible(int x, int y, int z) {
        if (x + y > z && x + z > y && y + z > x) {
            return true;
        } 
        return false;
    }
public:
    // TC : O(N*log(N))
    // SC : O(1)
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();

        sort(begin(nums), end(nums));
        int result = 0;

        int i = n - 1;
        while (i >= 2) {
            if (isPossible(nums[i], nums[i - 1], nums[i - 2])) {
                return (nums[i] + nums[i - 1] + nums[i - 2]);
            } else {
                i --;
            }
        }
        return 0;
    }
};