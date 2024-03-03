// https://leetcode.com/contest/weekly-contest-387/problems/distribute-elements-into-two-arrays-i/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> result;
        vector<int> arr1;
        vector<int> arr2;
        
        int n = nums.size();
        
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        
        for (int i = 2; i < n; i++) {
            int val1 = arr1.back();
            int val2 = arr2.back();
            
            if (val1 > val2) {
                    arr1.push_back(nums[i]);
            }
            else {
                arr2.push_back(nums[i]);
            }
        }
        for (int num: arr1) {
            result.push_back(num);
        }
        for (int num: arr2) {
            result.push_back(num);
        }
        return result;
    }
};