// https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    // TC : O(M*log(M) + N*log(N))
    // SC : O(M + N)
    vector<vector<int>> approach_1(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int m = nums1.size(), n = nums2.size();
        set<int> st;  // keys
        for (int i = 0; i < m; i ++) {
            st.insert(nums1[i][0]);
        }
        for (int i = 0; i < n; i ++) {
            st.insert(nums2[i][0]);
        }

        unordered_map<int, int> mpp;    // values
        for (int i = 0; i < m; i ++) {
            mpp[nums1[i][0]] = nums1[i][1];
        }
        for (int i = 0; i < n; i ++) {
            mpp[nums2[i][0]] += nums2[i][1];
        }

        vector<vector<int>> result;
        for (auto &it : st) {
            result.push_back({it, mpp[it]});
        }
        return result;
    }

    // TC : O(M + N)
    // SC : O(1)
    vector<vector<int>> approach_2(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> result;
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (nums1[i][0] == nums2[j][0]) {
                result.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                i ++ , j ++;
            } else if (nums1[i][0] < nums2[j][0]) {
                result.push_back(nums1[i]);
                i ++;
            } else {
                result.push_back(nums2[j]);
                j ++;
            }
        }
        while (i < m) {
            result.push_back(nums1[i]);
            i ++;
        }
        while (j < n) {
            result.push_back(nums2[j]);
            j ++;
        }
        return result;
    }
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        // return approach_1(nums1, nums2);    // Using HashMap + Set
        return approach_2(nums1, nums2);    // Array is sorted : Two Pointer
    }
};