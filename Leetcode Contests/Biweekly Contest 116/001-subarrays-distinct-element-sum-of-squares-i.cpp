// https://leetcode.com/contest/biweekly-contest-116/problems/subarrays-distinct-element-sum-of-squares-i/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        vector<set<int>> store;
        for (int i = 0; i < n; i++) {
            set<int> temp;
            for (int j = i; j < n; j++) {
                temp.insert(nums[j]);
                store.push_back(temp);
            }
        }
        
        for (int i = 0; i < store.size(); i++) {
            int uniqueEle = store[i].size();
            sum += uniqueEle * uniqueEle;
        }
        
        return sum;
    }
};