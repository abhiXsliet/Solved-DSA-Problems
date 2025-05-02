// https://leetcode.com/problems/push-dominoes/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string pushDominoes(string dom) {
        int n = dom.size();
        vector<int> leftClosestR(n, -1), rightClosestL(n, -1);
        for (int i = 0; i < n; i ++) {
            // calculate the net force from left side on current domino
            if (dom[i] == '.') {
                leftClosestR[i] = (i > 0) ? leftClosestR[i - 1] : -1;
            } else {
                leftClosestR[i] = (dom[i] == 'R') ? i : -1;
            } 
            // calculate the net force from right side on current domino
            int rIdx = n - i - 1;
            if (dom[rIdx] == '.') {
                rightClosestL[rIdx] = (rIdx + 1 < n) ? rightClosestL[rIdx + 1] : -1;
            } else {
                rightClosestL[rIdx] = (dom[rIdx] == 'L') ? rIdx : -1;
            }
        }

        string result;
        for (int i = 0; i < n; i ++) {
            int rPushFromL = abs(i - leftClosestR[i]);
            int lPushFromR = abs(i - rightClosestL[i]);

            if (leftClosestR[i] == rightClosestL[i]) {
                result += '.';
            } else if (leftClosestR[i] == -1) {
                result += 'L';
            } else if (rightClosestL[i] == -1) {
                result += 'R';
            } else if (rPushFromL == lPushFromR) {
                result += '.'; 
            } else {
                result += (rPushFromL > lPushFromR) ? 'L' : 'R';
            }
        }
        return result;
    }
};