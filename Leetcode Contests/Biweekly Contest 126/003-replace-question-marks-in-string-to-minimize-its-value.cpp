// https://leetcode.com/contest/biweekly-contest-126/problems/replace-question-marks-in-string-to-minimize-its-value/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int, char> P;
    
    // TC : O(N*log(N))
    // SC : O(N)
    string minimizeStringValue(string s) {
        int n = s.length();
        
        unordered_map<char, int> mpp;
        priority_queue<P, vector<P>, greater<P>> pq;

        for(char& ch : s) {
            if (ch != '?') {
                mpp[ch] ++;
            }
        }
        
        for (char c = 'a'; c <= 'z'; c++) {
            if (mpp.find(c) == mpp.end()) {
                mpp[c] = 0;
            }
        }
        
        for (auto& it : mpp) {
            pq.push({it.second, it.first});
        }
        
        string res;
        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                char topC = pq.top().second; 
                int freqC = pq.top().first;
                pq.pop();

                res += topC;
                mpp[topC]++;
                pq.push({mpp[topC], topC});
            }
        }
        
        sort(begin(res), end(res));
        
        int idx = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                s[i] = res[idx++];
            }
        }
        return s;
    }
};