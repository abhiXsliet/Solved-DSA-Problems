// https://www.geeksforgeeks.org/problems/divisible-by-13/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N)
    // SC : O(1)
    bool divby13(string &s) {
        int n = s.length();
        int rem = 0;
        for (int i = 0; i < n; i ++) {
            int dividend = (rem * 10 + (s[i] - '0'));
            rem = dividend % 13;
        }
        return !rem;
    }
};