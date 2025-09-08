// https://leetcode.com/contest/weekly-contest-466/problems/minimum-operations-to-transform-string/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    int minOperations(string s) {
        vector<int> freq(26, -1);
        for (char &ch : s) {
            int idx = ch - 'a';
            if (freq[idx] == -1) freq[idx] = 1;
            else freq[idx] ++;
        }
        int minOpr = 0;
        for (int i = 1; i < 25; i ++) {
            if (freq[i + 1] == -1) {
                freq[i + 1] = (freq[i] == -1) ? -1 : freq[i];
            } else {
                freq[i + 1] += (freq[i] == -1) ? 0 : freq[i];
            }
            if (freq[i] != -1) minOpr += 1;
        }
        minOpr += (freq[25] == -1) ? 0 : 1;
        return minOpr;
    }
};