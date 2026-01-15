// https://www.geeksforgeeks.org/problems/candy/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N)
    // SC : O(1)
    int minCandy(vector<int> &arr) {
        int n = arr.size();
        int candyCnt = n;
        int i = 1;
        
        while (i < n) {
            while (i < n && (arr[i] == arr[i - 1])) {
                i ++;
                continue;
            } 
            
            int peak = 0;
            // Increasing Slope
            while (i < n && (arr[i] > arr[i - 1])) {
                peak += 1;
                candyCnt += peak;
                i ++;
            }
            
            int dip = 0;
            // Decreasing Slope
            while (i < n && (arr[i - 1] > arr[i])) {
                dip += 1;
                candyCnt += dip;
                i ++;
            }
            
            candyCnt -= min(peak, dip);
        }
        
        return candyCnt;
    }
};