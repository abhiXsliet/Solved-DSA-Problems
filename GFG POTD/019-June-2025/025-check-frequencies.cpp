// https://www.geeksforgeeks.org/problems/check-frequencies4211/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isEqualFreq(vector<int> &freq) {
        int nonZeroFreq = -1;
        for (int i = 0; i < freq.size(); i ++) {
            if (freq[i] == 0) continue;
            else if (nonZeroFreq == -1) nonZeroFreq = freq[i];
            else if (nonZeroFreq != freq[i]) return false;
        }
        return true;
    }
    
    // TC : O(N)
    // SC : O(1)
    bool approach_1(string &s) {
        int n = s.length();
        
        vector<int> freq(26, 0);
        for(char &ch : s) {
            freq[ch - 'a'] ++;
        }
        
        if (isEqualFreq(freq)) return true;

        for (int i = 0; i < freq.size(); i ++) {
            if (freq[i] > 0) {
                freq[i] -= 1;
                if (isEqualFreq(freq)) return true;
                freq[i] += 1;
            }
        }
        
        return false;
    }
    
    bool sameFreq(string& s) {
        return approach_1(s);
    }
    
};