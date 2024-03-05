// https://leetcode.com/problems/intersection-of-two-arrays/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(max(M, N))
    // SC : O(max(M, N))
    vector<int> solve_1(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_set<int> occ;
        
        for (int num : nums2) 
            occ.insert(num);

        for (int num : nums1) {
            if (occ.find(num) != occ.end()) {
                result.push_back(num);
                occ.erase(num);
            }
        }
        return result;
    }

    // TC : O(max(M*log(M), N*log(M)))
    // SC : O(1)
    vector<int> solve_2(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        sort(begin(nums1), end(nums1));
        sort(begin(nums2), end(nums2));

        vector<int> result;
        
        int i = 0;
        int j = 0;

        while (i < n1 && j < n2) {
            if      (nums1[i] < nums2[j]) i ++;
            else if (nums1[i] > nums2[j]) j ++;
            else {  // nums1[i] == nums2[j]
                if (result.empty() || result.back() != nums1[i]) {
                    result.push_back(nums1[i]);
                }
                i ++, j ++;
            }
        }

        return result;
    }
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // return solve_1(nums1, nums2);

        return solve_2(nums1, nums2);
    }
};