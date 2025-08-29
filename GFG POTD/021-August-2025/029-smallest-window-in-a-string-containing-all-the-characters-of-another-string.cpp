// https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    bool allAvailable(vector<int> &f1, vector<int> &f2) {
        for (int i = 0; i < 26; i ++) {
            if (f2[i] && f1[i] < f2[i])
                return false;
        }
        return true;
    }
    
    // TC : O(N + M)
    // SC : O(1)
    string approach_1(string &s, string &p) {
        int n = s.length(), m = p.length();
        
        vector<int> freqP(26, 0);
        for (char &ch : p) {
            freqP[ch - 'a'] ++;
        }
        
        int i = 0, j = 0;
        vector<int>freqS(26, 0);
        int idx = -1, minLen = n;
        
        while (j < n) {
            freqS[s[j] - 'a'] ++;
            
            while (allAvailable(freqS, freqP)) {
                if (minLen > j - i + 1) {
                    minLen = j - i + 1;
                    idx = i;
                }
                
                freqS[s[i] - 'a'] --;
                i ++;
            }
            
            j ++;
        }
        
        if (idx == -1) return "";
        return s.substr(idx, minLen);
    }
    
    // TC : O(N + M)
    // SC : O(1)
    string approach_2(string &s, string &p) {
        int n = s.length(), m = p.length();
        
        unordered_map<char, int> mpp;
        for (char &ch : p) mpp[ch] ++;
        
        int count = mpp.size(), i = 0, j = 0, minLen = n, startIdx = -1;
        
        while (j < n) {
            if (mpp.count(s[j])) {
                mpp[s[j]] --;
                if (mpp[s[j]] == 0) count --;
            }
            
            while (!count) {
                if (mpp.count(s[i])) {
                    mpp[s[i]] ++;
                    if (mpp[s[i]] > 0) count ++;
                }
                
                if (minLen > j - i + 1) {
                    minLen = j - i + 1;
                    startIdx = i;
                }
                
                i ++;
            }
            
            j ++;
        }
        
        return (startIdx == -1) ? "" : s.substr(startIdx, minLen);
    }
  public:
    string smallestWindow(string &s, string &p) {
        // return approach_1(s, p);    // simple simulation
        return approach_2(s, p);    // little optimize
    }
};