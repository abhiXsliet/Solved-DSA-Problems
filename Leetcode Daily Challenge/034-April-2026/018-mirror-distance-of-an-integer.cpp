// https://leetcode.com/problems/mirror-distance-of-an-integer/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mirrorDistance(int n) {
        int revN = 0;
        int temp = n;
        while (temp) {
            revN = revN * 10 + temp % 10;
            temp /= 10;
        }
        return abs(revN - n);
    }
};