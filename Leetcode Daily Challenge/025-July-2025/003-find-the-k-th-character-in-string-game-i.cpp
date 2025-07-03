// https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N * K)
    // SC : O(K)
    char approach_1(int k) {
        string s = "a";
        while (s.length() < k) {
            int n = s.length();
            for (int i = 0; i < n; i ++) {
                char ch = (s[i] == 'z') ? 'a' : (s[i] + 1);
                s.push_back(ch);
            }
        }
        return s[k - 1];
    }

    // TC : O(log(K))
    // SC : O(1)
    char approach_2(int k) {
        int range = 1;
        while (range < k) {
            range *= 2;
        }

        int increment = 0;
        while (range > 1) {
            int leftHalf = range / 2;
            int extra    = k - leftHalf;
            if (extra > 0) {
                increment += 1;
                k = extra;
            }
            range /= 2;
        }
        return ('a' + increment);
    }

    // TC : O(log(k))
    // SC : O(1)
    char approach_3(int k) {
        int cntSetBits = __builtin_popcount(k - 1);
        return ('a' + cntSetBits);
    }
public:
    char kthCharacter(int k) {
        // return approach_1(k);   // Simulation
        // return approach_2(k);   // backtrack to original char
        return approach_3(k);   // Count of set bits in (k - 1) indicates shift steps for 'a'
    }
};