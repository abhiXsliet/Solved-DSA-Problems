// https://leetcode.com/problems/majority-element/


#include<bits/stdc++.h>
using namespace std;
//TC => O(N)
//SC => O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int ele;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(cnt == 0) {
                cnt = 1;
                ele = nums[i];
            } else if( ele == nums[i] ) {
                cnt++;
            } else {
                cnt--;
            }
        }

        int count = 0;
        for(int i = 0; i < n; i++) {
            if(ele == nums[i]) count++;
        }

        if(count > (n/2)) {
            return ele;
        }
        return -1;
    }
};