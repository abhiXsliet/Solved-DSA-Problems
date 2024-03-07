// https://leetcode.com/problems/sum-of-two-integers/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(1)
    int getSum(int a, int b) {
        while (b != 0) {
            int temp = a;
            a    = a ^ b;
            b    = ((temp & b) << 1);   // carry = (temp & b)
        }
        return a;
    }
};