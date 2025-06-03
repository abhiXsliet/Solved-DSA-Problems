// https://www.geeksforgeeks.org/problems/count-number-of-substrings4528/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int getCntSubstr(string &s, int n, int k) {
        int cntSubstr = 0;
        int i = 0, j = 0;
        vector<int> freq(26, 0);
        int count = 0;
        while (j < n) {
            freq[s[j] - 'a'] ++;
            if (freq[s[j] - 'a'] == 1) count ++;
            while (i <= j && count > k) {
                freq[s[i] - 'a'] --;
                if (!freq[s[i] - 'a']) count --;
                i ++;
            }
            cntSubstr += (j - i + 1);
            j ++;
        }
        return cntSubstr;
    }
    
    // TC : O(N)
    // SC : O(1)
    int approach_1(string &s, int k) {
        int n = s.length();
        int totalCntK = getCntSubstr(s, n, k);  // cnt of substrings with at most k-distinct characters
        int remainCnt = getCntSubstr(s, n, k - 1); // cnt of substrings with at most (k - 1)distinct characters
        
        return (totalCntK - remainCnt); // cnt of exactly k substrings
    }
    
    // TC : O(N)
    // SC : O(1)
    int approach_2(string &s, int k) {
        int n = s.length();
        int i = 0, j = 0, prev_i = 0;
        int cntSubStr = 0;
        unordered_map<char, int> mpp;
        int count = 0;
        
        while (j < n) {
            mpp[s[j]] ++;
            
            while (mpp.size() > k) {
                mpp[s[i]] --;
                if (!mpp[s[i]]) mpp.erase(s[i]);
                i ++;
                prev_i = i; 
            }
            
            while (mpp[s[i]] > 1) { // shrink if char pointed by i has freq > 1
                mpp[s[i]] --;
                i ++;
            }
            
            if (mpp.size() == k) 
                cntSubStr += (i - prev_i + 1);
            
            j ++;
        }
        
        return cntSubStr;
    }
  public:
    int countSubstr(string& s, int k) {
        // return approach_1(s, k);
        return approach_2(s, k);     // ONE PASS
    }
};