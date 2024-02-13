// https://leetcode.com/contest/weekly-contest-383/problems/minimum-time-to-revert-word-to-initial-state-i/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^2)
    // SC : O(N)
    int solve_brute(string& word, int k) {
        int n = word.length();
        int res = 1;
        
        string wordC = word;
        word  = word.substr(k);
        for (int i = 0; i < k; i++) {
            word += '?';
        }
        
        int i = 0, j = 0;
        while (i <= n && j <= n) {
            while ( (wordC[i] == word[j]) || ( (wordC[i] != word[j]) && (word[j] == '?') ) ) {
                i ++, j ++;
                if (i == n - 1 && j == n - 1) return res;
            }
            if (i < n && j < n) {
                i = 0; j = 0;
                word = word.substr(k);
                for (int i = 0; i < k; i++) {
                    word += '?';
                }
                res ++;
            }
        }
        
        return res;
    }
    
    // TC : O(N)
    bool check(string& word, int i, int n) {
        // word -> 0 to (n - i) length tak ka string
        // word -> i to (n - i) length tak ka string
        
        // one liner
        // return word.substr(0, n - i) == word.substr(i, n);
        
        
        int j = 0;
        while (i < n) {
            if (word[i] == word[j]) {
                i ++, j ++;
            }
            else {
                break;
            }
        }
        
        return i == n;
    }
    
    // TC : O(N^2)
    // SC : O(1)
    int solve_better_1(string& word, int k) {
        int n = word.length();
        
        int res = 1;
        int i   = k;
        
        while (i < n) {
            
            if (!check(word, i, n)) {
                
                res ++;
                i += k;
            }
            else break;
        }
        return res;
    }
    
    // TC : O(N^2)
    // SC : O(1)
    int solve_better_2(string& word, int k) {
        int n = word.length();
        
        int res = 1;
        int i   = k;
        
        while (i < n) {
            
            if (!check(word, i, n)) {
                i += k;
                res ++;
            }
            else return res;
        }
        
        return ceil(n / double(k));
    }
    
    // TC : O(N)
    // SC : O(N) -> LPS Array
    vector<int> getLps(string& s, int n) {
        vector<int> lps(n, 0);
        for (int i = 1; i < n; i++) {
            int j =  lps[i - 1];
            
            while (j > 0 && s[j] != s[i]) 
                j = lps[j - 1];
            
            if (s[i] == s[j]) j ++;
            
            lps[i] = j;
        }
        return lps;
    }

    // TC : O(N)
    // SC : O(N)
    int solve_optimal(string& word, int k) {
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
public:
    int minimumTimeToInitialState(string word, int k) {
        // return solve_brute(word, k);
        
        // return solve_better_1(word, k);
        
        // return solve_better_2(word, k);
        
        return solve_optimal(word, k);
    }
};