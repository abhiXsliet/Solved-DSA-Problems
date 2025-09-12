// https://www.geeksforgeeks.org/problems/minimize-the-heights3351/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N)
    // SC : O(1)
    int getMinDiff(vector<int> &arr, int k) {
        int n = arr.size();
        sort(begin(arr), end(arr));
        
        int maxi = arr[n - 1];
        int mini = arr[0];
        int maxDiff = maxi - mini;
        
        int maxEle = 0, minEle = 0;
        
        for (int i = 1; i < n; i ++) {
            if (arr[i] >= k) {
                maxEle  = max(arr[i-1] + k, maxi - k);  // try to reduce maximum
                minEle  = min(arr[i] - k  , mini + k);  // try to increase minimum
                
                maxDiff = min(maxDiff, maxEle - minEle);
            }
        }
        
        return maxDiff;
    }
};
