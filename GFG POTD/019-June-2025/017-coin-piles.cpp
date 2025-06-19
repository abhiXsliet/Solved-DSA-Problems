// https://www.geeksforgeeks.org/problems/coin-piles5152/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    // TC : O(N * log(N))
    // SC : O(N)
    int approach_1(vector<int> &arr, int k) {
        int n = arr.size();
        sort(begin(arr), end(arr));
        
        vector<int> prefix(n, arr[0]);
        for (int i = 1; i < n; i ++) {
            prefix[i] = (prefix[i - 1] + arr[i]);
        }
        
        int ans = INT_MAX;
        for (int i = 0; i < n; i ++) {
            int base = arr[i] + k;
            
            int idx = upper_bound(begin(arr) + i, end(arr), base) - begin(arr);
            
            int no_of_ele = (n - idx);
            int expected  = (no_of_ele * base);
            int actual    = (prefix[n - 1] - prefix[idx - 1]);
            
            int prev = 0;
            if (i > 0) prev = prefix[i - 1];
            
            ans = min(ans, (actual - expected + prev));
        }
        return ans;
    }
  public:
    int minimumCoins(vector<int>& arr, int k) {
        return approach_1(arr, k);
        // return approach_2(arr, k);   // extra space optimized using sliding window
    }
};
