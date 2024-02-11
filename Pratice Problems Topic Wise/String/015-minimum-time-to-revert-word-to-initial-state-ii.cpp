// https://leetcode.com/contest/weekly-contest-383/problems/minimum-time-to-revert-word-to-initial-state-ii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> getLps(string& s, int n) {
        vector<int> lps(n, 0);
        for (int i = 1; i < n; i++) {
            int j =  lps[i - 1];
            
            while (j > 0 && s[j] != s[i]) j = lps[j - 1];
            
            if (s[i] == s[j]) j ++;
            
            lps[i] = j;
        }
        return lps;
    }
public:
    // TC : O(N)
    // SC : O(N)
    int minimumTimeToInitialState(string word, int k) {
        int n = word.length();
        
        vector<int> lps = getLps(word, n);
        
        int suffix_len = lps[n - 1];
        
        while ( (suffix_len > 0) && ((n - suffix_len) % k != 0) ) {
            
            suffix_len = lps[suffix_len - 1];
        }
        
        if ((n - suffix_len) % k == 0) {
            
            return (n - suffix_len) / k;
        }
        
        // e.g., -> b a b a
        // lps   -> 0 0 0 0
        // k     -> k = 3
        return ceil(n / (double) k);  // ceil val => [n + k - 1] / k;
    }
};