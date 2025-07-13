// https://www.geeksforgeeks.org/problems/maximum-sum-of-elements-not-part-of-lis/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void dfs(vector<int> &arr, int curr, vector<int> &path, vector<vector<int>> &allLis, vector<int> &dp) {
        path.push_back(arr[curr]);
        
        if (dp[curr] == 1) {
            vector<int> temp = path;
            reverse(begin(temp), end(temp));
            allLis.push_back(temp);
            
        } else {
            for (int prev = curr - 1; prev >= 0; prev --) {
                if (dp[curr] - 1 == dp[prev] && arr[curr] > arr[prev]) {
                    dfs(arr, prev, path, allLis, dp);
                }
            }
        }
        
        path.pop_back();
    }
    
    void findAllLIS(vector<int> &arr, vector<int> &lexSmall) {
        int n = arr.size();
        
        vector<int> dp(n, 1);
        int maxLisLen = 1;
        
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < i; j ++) {
                if (dp[j] + 1 > dp[i] && arr[i] > arr[j]) {
                    dp[i] = 1 + dp[j];
                    maxLisLen = max(maxLisLen, dp[i]);
                }
            }
        }
        
        // generate all lis
        vector<vector<int>> allLis;
        
        for (int i = 0; i < n; i ++) {
            // Backtrack from every index with LIS length = maxLisLen
            if (dp[i] == maxLisLen) {
                vector<int> path;
                dfs(arr, i, path, allLis, dp);
            }
        }
        
        for (auto &seq : allLis) {  // store the lexiographically smallest LIS
            if (lexSmall.empty() || lexSmall > seq) {
                lexSmall = seq;
            }
        }
    }
    
    // TC : O(N^2 + K*L) where K = No. of LIS & L = length of array
    // SC : O(K*L) for storing all lis
    int approach_1(vector<int> &arr) {
        int totalSum = accumulate(begin(arr), end(arr), 0);
        
        // generate & get the lexiographically smallest lis
        vector<int> lexSmallestLIS;
        findAllLIS(arr, lexSmallestLIS);
        
        int sumLexSmallestLIS = accumulate(begin(lexSmallestLIS), end(lexSmallestLIS), 0);
        
        return (totalSum - sumLexSmallestLIS);
    }
    
    // TC : O(N*log(N))
    // SC : O(N)
    int approach_2(vector<int> &arr) {
        int n = arr.size();
        vector<int> dp;             // Stores end elements of potential LIS
        vector<int> dpIndex(n);     // Stores indices in original array for backtracking
        vector<int> parent(n, -1);  // For reconstructing the LIS
    
        int totalSum = 0;
        for (int val : arr) totalSum += val;
    
        vector<int> lisPos; // Stores positions of LIS elements
    
        for (int i = 0; i < n; ++i) {
            int pos = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
    
            if (pos == dp.size()) {
                dp.push_back(arr[i]);
                dpIndex[pos] = i;
            } else {
                dp[pos] = arr[i];
                dpIndex[pos] = i;
            }
    
            if (pos > 0)
                parent[i] = dpIndex[pos - 1];
        }
    
        // Reconstruct the LIS sequence to calculate its sum
        vector<int> lis;
        int idx = dpIndex[dp.size() - 1];
        while (idx != -1) {
            lis.push_back(arr[idx]);
            idx = parent[idx];
        }
    
        int lisSum = 0;
        for (int x : lis) {
            lisSum += x;
        }
    
        return totalSum - lisSum;
    }
  public:
    int nonLisMaxSum(vector<int>& arr) {
        // return approach_1(arr); // brute : TLE 
        return approach_2(arr);
    }
};