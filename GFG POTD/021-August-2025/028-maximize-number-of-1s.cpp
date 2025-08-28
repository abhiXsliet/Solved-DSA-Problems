// https://www.geeksforgeeks.org/problems/maximize-number-of-1s0905/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N)
    // SC : O(1)
    int maxOnes(vector<int>& arr, int k) {
        int n = arr.size();
        int maxLen = 0, cntZero = 0, i = 0;
        
        for (int j = 0; j < n; j ++) {
            
            cntZero += (arr[j] == 0);
            
            while (cntZero > k) {
                cntZero -= (arr[i] == 0);
                i ++;
            }
            
            maxLen = max(maxLen, j - i + 1);
        }
        
        return maxLen;
    }
};