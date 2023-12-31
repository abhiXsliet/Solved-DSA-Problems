// https://leetcode.com/problems/largest-substring-between-two-equal-characters/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N*N)
    // SC : O(1)
    int solve_brute(string& s, int n) {
        int result = -1;
        for (int i = 0; i < n-1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    result = max(result, j - i - 1);
                }
            }
        }
        return result;
    }

    // TC : O(N)
    // SC : O(N) ~ O(1) -> at worst ends-up storing 26 lowercase english alphabets
    int solve_better(string& s, int n) {
        unordered_map<char, int> mpp; // {char, indices}
        int result = -1;

        for (int i = 0; i < n; i++) {
            if (mpp.find(s[i]) == mpp.end()) {
                mpp[s[i]] = i;
            }
            else {
                result = max(result, i - mpp[s[i]] - 1);
            }
        }

        return result;
    }
    // TC : O(N)
    // SC : O(1)
    int solve_optimal(string& s, int n) {
        vector<int> freq(26, -1);
        int result = -1;

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (freq[ch - 'a'] == -1) {
                freq[ch - 'a'] = i;
            }
            else {
                result = max(result, i - freq[ch - 'a'] - 1);
            }
        }

        return result;
    }
public:
    int maxLengthBetweenEqualCharacters(string s) {
        // return solve_brute(s, s.length());

        // return solve_better(s, s.length());

        return solve_optimal(s, s.length());
    }
};