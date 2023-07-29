// https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int maxLength = 0;
        for(int i = 0; i < nums.size(); i++) {
            nums[i] += k;
            maxLength = max(maxLength, nums[i]);
        }

        vector<int> count(maxLength+k+2);

        for(int i = 0; i < nums.size(); i++) {
            count[nums[i]-k]++;
            count[nums[i]+k+1]--;
        }

        int ans = 1;
        int tot = 0;
        for(int i = 0; i < maxLength; i++) {
            tot += count[i];
            ans = max(ans, tot);
        }
        return ans;
    }
};