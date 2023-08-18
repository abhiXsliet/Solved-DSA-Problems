// https://leetcode.com/problems/next-greater-element-i/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(N^2)
    // SC = O(1)
    vector<int> better(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int m = nums1.size();
        int n = nums2.size();

        for(int i = 0; i < m; i++) {
            int tar = nums1[i];
            int idx = -1;
            for(int j = 0; j < n; j++) {
                if(tar == nums2[j]) {
                    idx = j;
                    break;
                }
            }
            int greaterEle = -1;
            for(int k = idx+1; k < n; k++) {
                if(nums2[k] > tar) {
                    greaterEle = nums2[k];
                    break;
                }
            }

            ans.push_back(greaterEle);
        }
        return ans;
    }

    // TC = O(N)
    // SC = O(1)
    vector<int> optimal(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int m = nums1.size();
        int n = nums2.size();

        stack<int> st; // to keep track of elements of nums2
        unordered_map<int, int> mpp; // to track the nge of nums2 array

        for(int i = 0; i < n; i++) {
            while(!st.empty() && st.top() < nums2[i]) {
                mpp[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }

        for(int i = 0; i < m; i++) {
            if(mpp.find(nums1[i]) != mpp.end()) {
                ans.push_back(mpp[nums1[i]]);
            } else {
                ans.push_back(-1);
            }
        }
        
        return ans;
    }
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        // return better(nums1, nums2);

        return optimal(nums1, nums2);
    }
};