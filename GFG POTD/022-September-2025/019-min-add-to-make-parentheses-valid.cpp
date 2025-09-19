// https://www.geeksforgeeks.org/problems/min-add-to-make-parentheses-valid/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N)
    // SC : O(1)
    int minParentheses(string& s) {
        int req = 0, track = 0;
        for (char &ch : s) {
            if (ch == '(') {
                track += 1;
            } else {
                track -= 1;
            }
            if (track < 0) {
                req += 1;
                track = 0;
            }
        }
        return (req + track);
    }
};