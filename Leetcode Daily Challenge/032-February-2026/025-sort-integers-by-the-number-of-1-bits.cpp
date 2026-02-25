// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N*log(N))
    // SC : O(1)
    vector<int> sortByBits(vector<int>& arr) {
        auto lambda = [&] (int& a, int& b) {
            int a_setbits = __builtin_popcount(a);
            int b_setbits = __builtin_popcount(b);

            if (a_setbits == b_setbits) 
                return a < b;

            return a_setbits < b_setbits;
        };

        sort(begin(arr), end(arr), lambda);

        return arr;
    }
};