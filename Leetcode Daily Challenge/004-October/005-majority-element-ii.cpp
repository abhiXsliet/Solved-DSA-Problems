// https://leetcode.com/problems/majority-element-ii/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
/* 
        //TC => O(N*log(N))
        //SC => O(N)
        vector<int> ans;
        int n = nums.size();
        int m = (int)(n/3) + 1;
        map<int, int>mpp;
        for(int i = 0; i < n; i++) {
            mpp[nums[i]]++;

            if(mpp[nums[i]] == m) ans.push_back(nums[i]);
            if(ans.size() == 2)break;
        }
        return ans;
         */

        //TC => O(N)
        //SC => O(1)
        vector<int> ans;
        int n = nums.size();
        int m = (int)(n/3) + 1;
        int cnt1 = 0, cnt2 = 0;
        int ele1 = INT_MIN, ele2 = INT_MIN;
        for(int i = 0; i < n; i++) {
            if(cnt1 == 0 && ele2 != nums[i]) {
                cnt1 = 1;
                ele1 = nums[i];
            } else if(cnt2 == 0 && ele1 != nums[i]) {
                cnt2 = 1;
                ele2 = nums[i];
            } 
            else if(nums[i] == ele1) cnt1++;
            else if(nums[i] == ele2) cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < n; i++) {
            if(ele1 == nums[i])cnt1++;
            if(ele2 == nums[i])cnt2++;
        }

        if(cnt1 >= m) ans.push_back(ele1);
        if(cnt2 >= m) ans.push_back(ele2);

        return ans;
    }
};