// https://www.geeksforgeeks.org/problems/sum-of-all-substrings-of-a-number-1587115621/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N)
    // SC : O(1)
    int sumSubstrings(string &s) {
        long long result = 0;
        long long prev   = 0;
        for (int i = 0; i < s.length(); i ++) {
            int num = s[i] - '0';
            prev = prev * 10 + (num * (i + 1));
            result += prev;
        }
        return result;
    }
};