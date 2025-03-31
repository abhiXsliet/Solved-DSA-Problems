// https://leetcode.com/problems/partition-labels/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(1)
    vector<int> approach_1(string &s) {
        int n = s.length();
        vector<int> lastOcc(26, -1);
        for (int i = 0; i < n; i ++) {
            lastOcc[s[i] - 'a'] = i;
        }

        vector<int> result;
        int i = 0;
        while (i < n) {
            int len = lastOcc[s[i] - 'a'] - i + 1;
            int newI = i + 1;
            for (int j = i + 1; j < n && j < i + len; j ++) {
                len = max(len, lastOcc[s[j] - 'a'] - i + 1);
                newI = j + 1;
            }
            result.push_back(len);
            i = newI;
        }
        return result;
    }
public:
    vector<int> partitionLabels(string s) {
        return approach_1(s);
    }
};