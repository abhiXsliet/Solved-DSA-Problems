// https://leetcode.com/problems/sort-colors/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(1)
    void solve_1 (vector<int>& nums) {
        int zeroCount = 0, oneCount = 0, twoCount = 0;
        for(int i = 0; i < nums.size(); i ++) {
            if (nums[i] == 0)
                zeroCount ++;
            if (nums[i] == 1)
                oneCount ++;
            if (nums[i] == 2)
                twoCount ++;
        }

        for(int i = 0; i < zeroCount; i ++)
            nums[i] = 0;
        for(int i = zeroCount; i < zeroCount + oneCount; i ++)
            nums[i] = 1;
        for(int i = zeroCount + oneCount; i < nums.size(); i++)
            nums[i] = 2;
    }

    // TC : O(N)
    // SC : O(1)
    // DUTCH FLAG ALGO
    void solve_2 (vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size()-1;
        while(mid <= high) {
            if(nums[mid] == 0) {
                swap(nums[mid++], nums[low++]);
            } 
            else if(nums[mid] == 1) mid++;  
            else {
                swap(nums[mid], nums[high--]);
            }
        }
    }
public:
    void sortColors(vector<int>& nums) {
        // solve_1 (nums);

        solve_2(nums);
    }
};