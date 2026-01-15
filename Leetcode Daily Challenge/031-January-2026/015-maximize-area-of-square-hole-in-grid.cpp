// https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(1)
    int getMaxSequentialCnt(vector<int>& bars) {
        int len = bars.size();

        int cntSequentialBars = INT_MIN;
        int cntSeq            = 1;

        for (int i = 1; i < len; i++) {
            if (bars[i] == bars[i - 1] + 1) cntSeq ++;
            else {
                cntSequentialBars = max(cntSequentialBars, cntSeq);
                cntSeq = 1;
            }
        }
        return max(cntSequentialBars, cntSeq);
    }
public:
    // TC : max(O(N * log(N), O(M * log(M)) 
    // SC : O(1)
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(begin(hBars), end(hBars));
        sort(begin(vBars), end(vBars));

        int maxHorizontalCnt = getMaxSequentialCnt(hBars);
        int maxVerticalCnt   = getMaxSequentialCnt(vBars);

        int squareArea       = min(maxHorizontalCnt, maxVerticalCnt) + 1;

        return squareArea * squareArea;
    }
};