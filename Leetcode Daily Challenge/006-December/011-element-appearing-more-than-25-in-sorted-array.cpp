// https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(N)
    // SC = O(N)
    int solve_brute(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> freq;
        for (int i : arr) {
            freq[i]++;
        }

        int ans = 0;
        for (auto num : arr) {
            if (freq[num] > n/4) {
                ans = num;
            } 
        }
        return ans;
    }

    // TC = O(N)
    // SC = O(1)
    int solve_better(vector<int>& arr) {
        int n = arr.size();
        int val = n/4;
        int ans = 0;

        for (int i = 0; i < n - val; i++) {
            if (arr[i] == arr[i + val]) {
                ans = arr[i];
                break;
            }
        }
        return ans;
    }

    // TC = O(log(N))
    int getLeftIdx(vector<int>& arr, int tar, int n) {
        int l = 0;
        int h = n - 1;
        int res_idx = -1;

        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (arr[mid] == tar) {
                res_idx = mid;
                h = mid - 1;
            }
            else if (arr[mid] < tar) {
                l = mid + 1;
            }
            else h = mid - 1;
        }
        return res_idx;
    }
   
    // TC = O(log(N))
    int getRightIdx(vector<int>& arr, int tar, int n) {
        int l = 0;
        int h = n - 1;
        int res_idx = -1;

        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (arr[mid] == tar) {
                res_idx = mid;
                l = mid + 1;
            }
            else if (arr[mid] < tar) {
                l = mid + 1;
            }
            else h = mid - 1;
        }
        return res_idx;
    }

    // TC = O(log(N))
    // SC = O(1)
    int solve_optimal(vector<int>& arr) {
        int n = arr.size();
        int freq = n/4;     // 25 %

        vector<int> candidates{arr[n/4], arr[n/2], arr[3*n/4]};

        int ans = 0;
        for (int& cand : candidates) {
            int left_idx  = getLeftIdx (arr, cand, n);
            int right_idx = getRightIdx(arr, cand, n);

            if (right_idx - left_idx + 1 > freq) { 
                ans = cand;
                break;
            }
        }
        return ans;
    }
public:
    int findSpecialInteger(vector<int>& arr) {
        // return solve_brute(arr);

        // return solve_better(arr);

        return solve_optimal(arr);
    }
};