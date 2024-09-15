// https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N)
    int approach_1(string& s) {
        int n = s.length();
        unordered_map<string, int> mpp;
        vector<int> freq(5, 0); // a, e, i, o, u
        
        string state = "00000";
        mpp[state] = -1;   // not seen any vowel till now

        int substrLen = 0;

        for (int i = 0; i < n; i ++) {
            if (s[i] == 'a') {
                freq[0] = (freq[0] + 1) % 2;
            } else if (s[i] == 'e') {
                freq[1] = (freq[1] + 1) % 2;
            } else if (s[i] == 'i') {
                freq[2] = (freq[2] + 1) % 2;
            } else if (s[i] == 'o') {
                freq[3] = (freq[3] + 1) % 2;
            } else if (s[i] == 'u') {
                freq[4] = (freq[4] + 1) % 2;
            }

            state = "";
            for (int j = 0; j < 5; j ++) {
                state += to_string(freq[j]);
            }

            if (mpp.find(state) != mpp.end()) {
                substrLen = max(substrLen, i - mpp[state]);
            } else {
                mpp[state] = i;
            }
        }

        return substrLen;
    }

    // TC : O(N)
    // SC : O(N)
    int approach_2(string& s) {
        int n = s.length();
        unordered_map<int, int> mpp;
        
        int state  = 00000; // a, e, i, o, u
        mpp[state] = -1;    // not seen any vowel till now

        int substrLen = 0;

        for (int i = 0; i < n; i ++) {
            if (s[i] == 'a') {
                state ^= (1 << 5);
            } else if (s[i] == 'e') {
                state ^= (1 << 4);
            } else if (s[i] == 'i') {
                state ^= (1 << 3);
            } else if (s[i] == 'o') {
                state ^= (1 << 2);
            } else if (s[i] == 'u') {
                state ^= (1 << 1);
            }

            if (mpp.find(state) != mpp.end()) {
                substrLen = max(substrLen, i - mpp[state]);
            } else {
                mpp[state] = i;
            }
        }

        return substrLen;
    }
public:
    int findTheLongestSubstring(string s) {
        // return approach_1(s);

        return approach_2(s);
    }
};