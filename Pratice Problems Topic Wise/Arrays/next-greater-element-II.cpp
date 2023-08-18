// https://leetcode.com/problems/next-greater-element-ii/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(N^2)
    // SC = O(1)
    vector<int> better(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n, -1);

        for(int i = 0; i < n; i++) {
            bool isGreater = 0; 
            for(int j = i + 1; j < n; j++) {
                if(nums[j] > nums[i]) {
                    isGreater = 1;  // Set to true if a greater element is found
                    nge[i] = nums[j];
                    break;  // Break once a greater element is found
                }
            }

            if(!isGreater) {
                nge[i] = -1;  // Set to -1 if no greater element is found
            }
        }
        
        return nge;
    }

    // TC = O(N)
    // SC = O(N)
    vector<int> optimal(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n, -1);
        stack<int> st;
        
        for(int i = 2*n-1; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }

            if (i < n) 
                if (!st.empty()) 
                    nge[i] = st.top();

            st.push(nums[i % n]);
        }
        
        return nge;
    }

public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // return better(nums);

        return optimal(nums);
    }
};