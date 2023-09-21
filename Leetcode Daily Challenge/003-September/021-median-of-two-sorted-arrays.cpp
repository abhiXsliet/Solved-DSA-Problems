// https://leetcode.com/problems/median-of-two-sorted-arrays/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();

        vector<int> result(m+n);
        
        int i = 0, j = 0, k = 0;
        while(i < m && j < n) {
            if (nums1[i] < nums2[j]) 
                result[k++] = nums1[i++];
            else 
                result[k++] = nums2[j++];
        }

        while (i < m) result[k++] = nums1[i++];

        while (j < n) result[k++] = nums2[j++];

        return result;
    }

    // TC = O(N + M)
    // SC = O(N + M)
    double solve_brute(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged = merge(nums1, nums2);

        int n = merged.size();

        double ans = 0;

        if (n % 2 == 0) 
            ans = ( merged[n / 2] + merged[( n - 1 )/ 2] ) / 2.0; 
        else ans = merged[n / 2];

        return ans;
    }

    // TC = O(N + M)
    // SC = O(1)
    double solve_better(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();

        int i = 0, j = 0, k = 0;
        int size = m + n;

        int idx1 = size / 2, idx2 = ( size - 1 ) / 2; 

        int ele1 = -1, ele2 = -1;
        
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {

                if (k == idx1) ele1 = nums1[i];
                if (k == idx2) ele2 = nums1[i];
                i++;
                
            } else {

                if (k == idx1) ele1 = nums2[j];
                if (k == idx2) ele2 = nums2[j];
                j++;
            }
            k++;
        }

        while (i < m) {
            if (k == idx1) ele1 = nums1[i];
            if (k == idx2) ele2 = nums1[i];
            i++, k++;
        }

        while (j < n) {
            if (k == idx1) ele1 = nums2[j];
            if (k == idx2) ele2 = nums2[j];
            j++, k++;
        }

        if (size % 2 == 1) {
            return ele1;
        } 
        else {
            return (ele1 + ele2) / 2.0;
        }
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // return solve_brute(nums1, nums2);

        return solve_better(nums1, nums2);
    }
};