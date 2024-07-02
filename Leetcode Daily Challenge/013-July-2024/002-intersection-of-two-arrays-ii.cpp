// https://leetcode.com/problems/intersection-of-two-arrays-ii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(10001)
    vector<int> approach_1(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> freq(1001, 0);
        for (int& num : nums2) freq[num] ++;
        vector<int> result;
        for (int& num : nums1) {
            if (freq[num] > 0) {
                freq[num] -= 1;
                result.push_back(num);
            }
        }
        return result;
    }

    // TC : O(max(N*log(N), M*log(M)))
    // SC : O(1)
    vector<int> approach_2(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        
        sort(begin(nums1), end(nums1));
        sort(begin(nums2), end(nums2));

        vector<int> result;
        int i = 0, j = 0;

        while (i < n && j < m) {
            if (nums1[i] == nums2[j]) {
                result.push_back(nums1[i]);
                i ++, j ++;
            } else if (nums1[i] < nums2[j]) 
                i ++;
              else j ++;
        }
        return result;
    }
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // return approach_1(nums1, nums2);

        return approach_2(nums1, nums2);
    }
};