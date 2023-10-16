// https://leetcode.com/contest/weekly-contest-367/problems/find-indices-with-index-and-value-difference-i/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        vector<int> result(2, -1);
        for(int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (abs(i - j) >= indexDifference && abs(nums[i] - nums[j]) >= valueDifference) {
                    result[0]= i;
                    result[1]= j;
                    break;
                }
            }
        }
        return result;
    }
};