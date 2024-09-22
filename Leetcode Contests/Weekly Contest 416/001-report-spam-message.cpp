// https://leetcode.com/contest/weekly-contest-416/problems/report-spam-message/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N + M) Where M = message array size
    // SC : O(N)     Where N = bannedWords array size
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_map<string, int> m2;
        for (string& s : bannedWords) {
            m2[s] ++;
        }

        int cnt = 0;
        for (string& s : message) {
            if (m2.count(s)) {
                cnt ++;
            }
        }
        return cnt >= 2;
    }
};