// https://leetcode.com/problems/minimum-length-of-anagram-concatenation/



#include <bits/stdc++.h>    
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(1)
    bool isPossible(int len, string& s) {
        vector<int> freq_1(26, 0);
        for (int i = 0; i < len; i++) {
            freq_1[s[i] - 'a'] ++;
        }

        for (int i = len; i < s.length(); i += len) {
            
            vector<int> freq_2(26, 0);

            for (int j = i; j < i + len; j++) {
                freq_2[s[j] - 'a'] ++;
            }

            if (freq_1 != freq_2) return 0;
        }
        return 1;
    }

    // TC : O(N*sqrt(N))
    // SC : O(1)
    int approach_1(string s) {
        int n = s.length();
        for (int i = 1; i < n; i ++) {
            if (n % i == 0 && isPossible(i, s)) {
                return i;
            }
        }

        return n;
    }
public:
    int minAnagramLength(string s) {
        return approach_1(s);
    }
};