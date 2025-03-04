// https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int binarySearchRecursion(vector<int>& arr, int n, int j, int num1, int num2, int target) {
        int tar_idx = lower_bound(begin(arr) + j, end(arr), target) - begin(arr);
        if (tar_idx < n && arr[tar_idx] == target) {
            return 1 + binarySearchRecursion(arr, n, tar_idx, num2, target, num2 + target);
        }
        return 0;
    }
    
    // TC : O(N^3)
    // SC : O(1)
    int approach_1(vector<int>& arr, int n) {
        int maxLen = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int num1 = arr[i], num2 = arr[j];
                int seq = 2;
                for (int k = j + 1; k < n; k++) {
                    if (num1 + num2 == arr[k]) {
                        seq ++;
                        num1 = num2;
                        num2 = arr[k];
                    }
                }
                if (seq > 2) maxLen = max(maxLen, seq);
            }
        }
        return maxLen;
    }

    // TC : O(N^2 * log(M)) where log(m) due to fibonacci chain length
    // SC : O(N)
    int approach_2(vector<int>& arr, int n) {
        unordered_set<int> st(begin(arr), end(arr));
        int maxLen = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int num1 = arr[i], num2 = arr[j];
                int target = num1 + num2;
                int seq = 2;
                while (st.count(target)) {  // log(M)
                    seq ++;
                    num1 = num2;
                    num2 = target;
                    target = num1 + num2;
                }
                if (seq > 2) maxLen = max(maxLen, seq);
            }
        }
        return maxLen;
    }

    // TC : O(N^2 * log(N)) where log(n) due to binary search & log(m) due to fibonacci chain length
    // SC : O(1)
    int approach_3(vector<int>& arr, int n) {
        int maxLen = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int num1 = arr[i], num2 = arr[j];
                int target = num1 + num2;
                int seq = 2;
                seq += binarySearchRecursion(arr, n, j, num1, num2, target);
                if (seq > 2) maxLen = max(maxLen, seq);
            }
        }
        return maxLen;
    }

    // TC : O(N^2)
    // SC : O(N^2)
    int approach_4(vector<int>& arr, int n) {
        // dp[i][j] : Max length of fibonacci like subsequence ending at index i, j
        vector<vector<int>> dp(n, vector<int>(n, 2));   // filling 2 since each subsequence has to at least length of 2 for extending its subsequence length

        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i ++) {
            mpp[arr[i]] = i;
        }

        int maxLen = 0;
        for (int j = 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                int target = arr[k] - arr[j];
                if (mpp.count(target) && mpp[target] < j) {
                    int i = mpp[target];
                    dp[j][k] = 1 + dp[i][j];
                }
                maxLen = max(maxLen, dp[j][k]);
            }
        }
        return maxLen < 3 ? 0 : maxLen;
    }
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        // return approach_1(arr, arr.size());     // BRUTE
        // return approach_2(arr, arr.size());     // BETTER : Using Set
        // return approach_3(arr, arr.size());     // BETTER : Space Optimized binary search + recursion
        return approach_4(arr, arr.size());     // DP : Tabulation
    }
};