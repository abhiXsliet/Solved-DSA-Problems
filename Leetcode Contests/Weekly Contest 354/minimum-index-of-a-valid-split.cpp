// https://leetcode.com/contest/weekly-contest-354/problems/minimum-index-of-a-valid-split/



#include<bits/stdc++.h>
using namespace std;

class Solution {
private: 
    int getMajorityEle(vector<int>& nums) {
        int cnt = 0;
        int el;
        for(int i = 0; i < nums.size(); i++) {
            if(cnt == 0) {
                cnt = 1;
                el = nums[i];
            } else if(el == nums[i]) cnt++;
            else cnt--;
        }
        
        return el;
    }
    
    bool isMajority(int ele, int freq) {
        return (2 * (ele)) > freq;
    }
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int majorityEle = getMajorityEle(nums);
        int cntMaj = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == majorityEle) cntMaj++;
        }
        
        int ans = -1;
        int currCnt = 0;
        int subArrLen = 0;
        for(int i = 0; i < n; i++) {
            subArrLen++;
            if(nums[i] == majorityEle) currCnt++;
            if(isMajority(currCnt, subArrLen) && isMajority(cntMaj - currCnt, n - subArrLen)) 
                return i;
        }
        return ans;
    }
};