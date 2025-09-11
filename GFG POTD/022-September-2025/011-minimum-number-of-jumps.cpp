// https://www.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N)
    // SC : O(1)
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        int jumps = 0, maxR = 0, end = 0;
        
        for (int i = 0; i < n - 1; i ++) {
            maxR = max(maxR, i + arr[i]);
            if (i == end) {
                jumps += 1;
                end = maxR;
                if (end == i) return -1;
            }
        }
        
        return jumps;
    }
};