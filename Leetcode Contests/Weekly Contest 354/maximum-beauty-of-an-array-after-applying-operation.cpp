// https://leetcode.com/contest/weekly-contest-354/problems/maximum-beauty-of-an-array-after-applying-operation/



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int maxLen = 0;
        for(auto& i:nums) {
            i += k;
            maxLen = max(maxLen, i);
        }
        
        vector<int> count(maxLen+k+2);
        
        for(auto& i:nums) {
            count[i-k]++;
            count[i+k+1]--;
        }
        
        int ans = 1;
        int total = 0;
        for(int i = 0; i < maxLen; i++) {
            total += count[i];
            ans = max(ans, total);
        }
        return ans;
    }
};