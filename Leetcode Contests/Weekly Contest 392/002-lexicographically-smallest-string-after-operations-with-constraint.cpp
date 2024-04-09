// https://leetcode.com/problems/lexicographically-smallest-string-after-operations-with-constraint/



#include <bits/stdc++.h>    
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    string getSmallestString(string s, int k) {
        int n = s.length();
        for (int i = 0; i < n; i++) {
            int forward  = ('z' - s[i]) + 1;
            int backward = s[i] - 'a';

            int minCost = min(forward, backward);

            if (minCost <= k) {
                s[i] = 'a';
                k -= minCost;
            }
            else {
                s[i] = s[i] - k;
                k = 0;
                break;
            }

        }
        return s;
    }
};