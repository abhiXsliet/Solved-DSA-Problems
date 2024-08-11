// https://leetcode.com/problems/convert-a-number-to-hexadecimal/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(log(n) base 16)
    // SC : O(1)
    string toHex(int num) {
        if (num == 0) return "0";

        unsigned int n = num;
        string digit   = "0123456789abcdef";
        string res;

        while(n) {
            int rem = n % 16;
            if (rem < 10) {
                res += (rem + '0');
            } else {
                res += digit[rem];
            }
            n /= 16;
        }
        
        reverse(begin(res), end(res));
        return res;
    }
};