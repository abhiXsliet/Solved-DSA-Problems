// https://www.geeksforgeeks.org/problems/count-indices-to-balance-even-and-odd-sums/1/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int cntWays(vector<int>& arr) {
        int n = arr.size();
        int leftOdd = 0, leftEven = 0;
        int rightOdd = 0, rightEven = 0;
        
        for (int i = 0; i < n; i ++) {
            if (i % 2) {
                rightOdd += arr[i];
            } else {
                rightEven += arr[i];
            }
        }
        
        
        int ans = 0;
        for (int i = 0; i < n; i ++) {
            if (i % 2) {
                rightOdd -= arr[i];
            } else {
                rightEven -= arr[i];
            }

            if (leftOdd + rightEven == leftEven + rightOdd) {
                ans += 1;
            }
            
            if (i % 2) {
                leftOdd += arr[i];
            } else {
                leftEven += arr[i];
            }
        }
        return ans;
    }
};
