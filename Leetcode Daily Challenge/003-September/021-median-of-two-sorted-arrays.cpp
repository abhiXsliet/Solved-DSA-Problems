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

    // TC = O(min(logm, logn))
    // SC = O(1)
    double solve_optimal(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();

        // Always choose the smallest array for making left half
        if (m > n) return solve_optimal(nums2, nums1);

        int low  = 0;
        int high = m;

        // no. of elements in the left halfe
        int left = (m + n + 1) / 2;

        int size = m + n;

        while(low <= high) {
            int mid1 = low + (high - low) / 2;
            int mid2 = left - mid1;

            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            if (mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0) l2 = nums2[mid2 - 1];

            if (mid1 < m) r1 = nums1[mid1];
            if (mid2 < n) r2 = nums2[mid2];

            if (l1 <= r2 && l2 <= r1) {

                if (size % 2 == 0) {
                    return (double)((max(l1, l2) + min(r1, r2)) / 2.0);
                }
                else {
                    return max(l1, l2);
                }
            }
            else if (l1 > r2) high = mid1 - 1;
            else low =  mid1 + 1;
        }
        return 0;
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // return solve_brute(nums1, nums2);

        // return solve_better(nums1, nums2);

        return solve_optimal(nums1, nums2);
    }
};