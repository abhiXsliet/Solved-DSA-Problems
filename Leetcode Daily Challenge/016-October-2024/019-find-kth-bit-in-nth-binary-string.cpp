// https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(N) due to recursive depth
    char findKthBit(int n, int k) {
        if (n == 1) return '0';
        
        int len = (1 << n) - 1;     // pow(2, n)
        
        if (k == ceil(len / 2.0)) {
            return '1';
        } else if (k < ceil(len / 2.0)) {
            return findKthBit(n - 1, k);
        } else {
            char ch = findKthBit(n - 1, len - (k - 1));
            return (ch == '0') ? '1' : '0';
        }
    }
};