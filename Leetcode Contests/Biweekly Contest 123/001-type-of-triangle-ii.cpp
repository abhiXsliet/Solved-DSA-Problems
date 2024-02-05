// https://leetcode.com/contest/biweekly-contest-123/problems/type-of-triangle-ii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool inEquality(vector<int>& nums) {
        return ( ((nums[0] + nums[1]) > nums[2]) && ((nums[1] + nums[2]) > nums[0]) && ((nums[0] + nums[2]) > nums[1]) );
    }
public:
    string triangleType(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for (int& num : nums) mpp[num]++;
  
        if (inEquality(nums)) 
        {
            if (mpp.size() == 1) return "equilateral";
            else if (mpp.size() == 2) return "isosceles";
            else if (mpp.size() == 3) return "scalene";
            else return "none";
        }
        
        return "none";
    }
};