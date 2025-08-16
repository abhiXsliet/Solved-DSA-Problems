// https://leetcode.com/problems/maximum-69-number/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximum69Number (int num) {
        int temp = num, cnt = 0, idx = -1;
        while (temp) {
            int rem = temp % 10;
            if (rem == 6) idx = cnt;
            temp /= 10;
            cnt  += 1;
        }
        return (idx == -1) ? num :  num + (3 * pow(10, idx));
    }
};