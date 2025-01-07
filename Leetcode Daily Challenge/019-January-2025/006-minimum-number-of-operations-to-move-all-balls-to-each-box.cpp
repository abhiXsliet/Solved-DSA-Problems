// https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int> result(n, 0);
        int baseInc = 0;
        int baseSum = 0;
        for (int i = 0; i < n; i ++) {
            if (boxes[i] == '1') {
                baseInc ++;
                baseSum += i;
            }
        }

        result[0] = baseSum;
        int adjInc = boxes[0] == '1' ? 1 : 0;
        baseInc = boxes[0] == '1' ? baseInc - 1 : baseInc;

        for (int i = 1; i < n; i ++) {
            result[i] = result[i - 1] + adjInc - baseInc;
            adjInc  = boxes[i] == '1' ? adjInc + 1  : adjInc;
            baseInc = boxes[i] == '1' ? baseInc - 1 : baseInc; 
        }
        return result;
    }
};