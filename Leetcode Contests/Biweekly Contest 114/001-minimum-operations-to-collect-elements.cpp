// https://leetcode.com/contest/biweekly-contest-114/problems/minimum-operations-to-collect-elements/


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        set<int> st;
        while(k) {
            st.insert(k--);
        }
        
        for (int i = n - 1; i >= 0; i--) {
            if (st.find(nums[i]) != st.end())
                st.erase(nums[i]);
            
            cnt++;
            
            if (st.empty()) return cnt;
        }
        
        return 0;
    }
};