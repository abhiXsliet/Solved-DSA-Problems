// https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(K * N)    Where N = Length of string str
    // SC : O(N)        Space Used by string str
    char brute(int k) {
        int times = 0;
        for (int i = 0; i <= k; i ++) {
            if (pow(2, i) >= k) {
                times = i;
                break;
            } 
        }

        string str = "a";
        for (int i = 0; i < times; i ++) {
            string newStr;
            for (int j = 0; j < str.length(); j ++) {
                char ch = (str[j] - 'a' + 1) % 26 + 'a';
                newStr += ch;
            }
            str += newStr;
        }
        return str[k - 1];
    }

    char optimal(int k) {
        long long range = 1;
        while (range <= k) {
            range *= 2;
        }

        int increment = 0;
        while (range > 1) {
            long long part1 = range / 2;

            long long extra = (k - part1);
            if (extra > 0) {
                increment ++;
                k = extra;
            }
            range /= 2;
        }
        return 'a' + increment;
    }
public:
    char kthCharacter(int k) {
        // return brute(k);    // SIMULATION

        return optimal(k);  // Divide on pow(2, range) <= K
    }
};