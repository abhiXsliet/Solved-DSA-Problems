// https://leetcode.com/problems/count-partitions-with-even-sum-difference/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();

        int sum = accumulate(begin(nums), end(nums), 0);

        if(sum % 2 == 0)
            return n-1; //all partitions will be possible as it only depends on sum
        
        return 0;
    }
};