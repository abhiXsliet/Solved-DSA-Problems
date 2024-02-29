// https://leetcode.com/problems/hamming-distance/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(32)
    int hammingDistance(int x, int y) {
        int ans = 0;
        while (x > 0 || y > 0) {
            if( (x & 1) != (y & 1) )
                ans ++;
            x >>= 1;
            y >>= 1;
        }
        return ans;
    }
};