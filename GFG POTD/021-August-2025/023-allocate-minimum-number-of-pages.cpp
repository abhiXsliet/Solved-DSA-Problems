// https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    // ek bhi student ko tar se zyada pages nahi milne chahiye
    bool isPossible(vector<int> &arr, int tar, int k) {
        int sumPages = 0, students = 1;
        for (int &pages : arr) {
            if (pages + sumPages <= tar) {
                sumPages += pages;
            } else {
                students += 1;
                sumPages = pages;
                if (students > k || pages > tar) return false;
            }
        }
        return true; // students <= k
    }
  public:
    // TC : O(N * log(R)) where R = sum(arr) - max(arr)
    // SC : O(1)
    int findPages(vector<int> &arr, int k) {
        if (k > arr.size()) return -1;
        
        int low = INT_MIN, high = 0;
        for (int &val : arr) {
            low = max(low, val);
            high += val;
        }
        
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(arr, mid, k)) {
                ans  = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};