// https://www.geeksforgeeks.org/problems/largest-number-in-one-swap1520/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N)
    // SC : O(1)
    string largestSwap(string &s) {
        int n = s.length();
        
        unordered_map<int, int> lastOcc;

        for (int i = 0; i < n; i ++) {
            lastOcc[s[i] - '0'] = i;
        }
        
        for (int i = 0; i < n; i ++) {
            int val = s[i] - '0';
            bool isGreaterAvail = false;
            int digit = -1;
            for (int d = 9; d >= 0; d --) {
                if (lastOcc[d] > i && d > val) {
                    isGreaterAvail = true;
                    digit = d;
                    break;
                }
            }
            if (isGreaterAvail) {
                swap(s[i], s[lastOcc[digit]]);
                break;
            }
        }
        
        return s;
    }
};