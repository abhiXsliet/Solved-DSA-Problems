// https://www.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countSetBits(int n) {
        if (n == 0) return 0;
        
        // largest power of 2 <= n
        int x = log2(n);
        int highestPow = 1 << x; // 2^x
        
        // bits from 1 to (2^x - 1)
        int bitsTillPow = x * (highestPow >> 1);
        
        // MSB contribution from 2^x to n
        int msbContribution = n - highestPow + 1;
        
        // count recursively for remaining part
        int remaining = n - highestPow;
        
        return bitsTillPow + msbContribution + countSetBits(remaining);
    }
};