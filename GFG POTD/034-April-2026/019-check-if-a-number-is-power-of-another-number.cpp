// https://www.geeksforgeeks.org/problems/check-if-a-number-is-power-of-another-number5442/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(log_x(y))
    // SC : O(1)
    bool isPower(int x, int y) {
        if (y == 1) return true;
        if (x == 1) return y == 1;
        while (y % x == 0) {
            y /= x;
        }
        return y == 1;
    }
};