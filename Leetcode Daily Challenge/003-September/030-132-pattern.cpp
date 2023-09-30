// https://leetcode.com/problems/132-pattern/


#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
    // TC = O(N * N * N), SC = O(1)
    bool solve_brute(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) { 
                
                if (nums[i] < nums[j]) {
                    for (int k = j + 1; k < n; k++) {
                        if (nums[i] < nums[k]  && nums[k] < nums[j])
                            return true;
                    }
                }
            }
        }
        return false;
    }

    // TC = O(N * N), SC = O(1)
    bool solve_better(vector<int>& nums) {
        int n = nums.size();
        int nums_i = nums[0];
        
        for (int j = 1; j < n - 1; j++) {
            nums_i = min(nums_i, nums[j]);

            for (int k = j + 1; k < n; k++) {
                if (nums_i < nums[k] && nums[k] < nums[j])
                    return true;
            }
        }
        return false;
    }

    // TC = O(N), SC = O(N)
    bool solve_optimal(vector<int>& nums) {
        int n = nums.size();

        int nums3 = INT_MIN;
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] < nums3)   
                return true;

            while(!st.empty() && st.top() < nums[i]) {
                nums3 = st.top();
                st.pop();
            }

            st.push(nums[i]);
        }
        return false;
    }
public:
    bool find132pattern(vector<int>& nums) {
        // return solve_brute(nums);

        // return solve_better(nums);

        return solve_optimal(nums);
    }
};