// https://leetcode.com/problems/count-complete-subarrays-in-an-array/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int>st;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }
        
        int cnt = 0;
        int left = 0;
        int right = 0;
        unordered_map<int, int> window;

        while (right < n) {
            window[nums[right]]++;

            while (window.size() == st.size()) {
                cnt += (n - right);
                window[nums[left]]--;

                if (window[nums[left]] == 0) {
                    window.erase(nums[left]);
                }

                left++;
            }

            right++;
        }

        return cnt;
    }
};