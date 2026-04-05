// https://www.geeksforgeeks.org/problems/target-sum-1626326450/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(n*(sum of arr))
    // SC : O(sum of arr)
    int totalWays(vector<int>& arr, int target) {
        int totalSum = 0;
        for (int x : arr) totalSum += x;
        
        // invalid cases
        if (abs(target) > totalSum) return 0;
        if ((target + totalSum) % 2 != 0) return 0;
        
        int S1 = (target + totalSum) / 2;
        
        vector<int> dp(S1 + 1, 0);
        dp[0] = 1;
        
        for (int num : arr) {
            for (int j = S1; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }
        
        return dp[S1];
    }
};