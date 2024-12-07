// https://leetcode.com/problems/swap-adjacent-in-lr-string/

// similar : https://leetcode.com/problems/move-pieces-to-obtain-a-string/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    bool canTransform(string start, string result) {
        int n = start.length();
        int i = 0, j = 0;
        while (i < n || j < n) {
            while (i < n && start[i]  == 'X') i ++;
            while (j < n && result[j] == 'X') j ++;

            if (i == n || j == n) {
                return i == n && j == n;    // both strings should be exhausted at same time
            }

            if (start[i] != result[j]) return false;

            if (start[i] == 'L' && j > i) return false;
            if (start[i] == 'R' && i > j) return false;

            i ++, j ++;
        }
        return true;
    }
};