// https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    // TC : O(N * K)
    // SC : O(1)
    int approach_1(string &s, int k) {
        int n = s.length();
        int minPaintReq = n;
        for (int i = 0; i <= n - k; i ++) {
            int paintBlack = 0;
            for (int j = i; j < i + k; j ++) {
                if (s[j] == 'W') {
                    paintBlack ++;
                }
            }
            if (minPaintReq > paintBlack) {
                minPaintReq = paintBlack;
            }
        }
        return minPaintReq;
    }

    // TC : O(N)
    // SC : O(1)
    int approach_2(string &s, int k) {
        int n = s.length();
        int minPaintReq = n;
        int paintBlack = 0;
        int i = 0, j = 0;
        while (j < n) {
            if (s[j] == 'W') {
                paintBlack ++;
            }
            if (j - i + 1 == k) {
                minPaintReq = min(minPaintReq, paintBlack);
                if (s[i] == 'W') paintBlack --;
                i ++;
            }
            j ++;
        }
        return minPaintReq;
    }
public:
    int minimumRecolors(string blocks, int k) {
        // return approach_1(blocks, k);
        return approach_2(blocks, k);
    }
};