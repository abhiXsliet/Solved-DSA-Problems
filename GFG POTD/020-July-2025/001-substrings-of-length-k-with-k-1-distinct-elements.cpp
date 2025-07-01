// https://www.geeksforgeeks.org/problems/substrings-of-length-k-with-k-1-distinct-elements/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    // TC : O(N)
    // SC : O(N)
    int approach_1(string &s, int k) {
        int n = s.length();
        unordered_map<int, int> mpp;
        int i = 0, j = 0;
        int cnt = 0;
        while (j < n) {
            mpp[s[j]] ++;
            
            while (j - i + 1 >= k || mpp.size() >= k) {
                if (j - i + 1 == k && mpp.size() == k - 1) {
                    cnt += 1;
                }
                mpp[s[i]] --;
                if (!mpp[s[i]]) mpp.erase(s[i]);
                i ++;
            }
            
            j ++;
        }
        return cnt;
    }
    
    // TC : O(N)
    // SC : O(1)
    int approach_2(string &s, int k) {
        int n = s.length();
        vector<int> freq(26, 0);
        int i = 0, j = 0;
        int cnt = 0;
        int insertEleCnt = 0;
        while (j < n) {
            freq[s[j] - 'a'] ++;
            
            if (freq[s[j] - 'a'] == 1) insertEleCnt += 1;
            
            while (j - i + 1 >= k || insertEleCnt >= k) {
                if (j - i + 1 == k && insertEleCnt == k - 1) {
                    cnt += 1;
                }
                freq[s[i] - 'a'] --;
                if (!freq[s[i] - 'a']) insertEleCnt -= 1;
                i ++;
            }
            
            j ++;
        }
        return cnt;
    }
  public:
    int substrCount(string &s, int k) {
        // return approach_1(s, k);
        return approach_2(s, k);
    }
};