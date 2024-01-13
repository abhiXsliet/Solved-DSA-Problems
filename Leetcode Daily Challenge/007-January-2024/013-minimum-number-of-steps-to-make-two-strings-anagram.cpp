// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(26) ~= O(1)
    int solve_approach_1(string& s, string& t) {
        int n = s.length();

        int arr_s[26] = {0};
        int arr_t[26] = {0};

        for (int i = 0; i < n; i++) {
            arr_s[s[i] - 'a']++;
            arr_t[t[i] - 'a']++;
        }

        int res = 0;
        for (int i = 0; i < 26; i++) {
            int freq_t = arr_t[i];
            int freq_s = arr_s[i];

            if (freq_t < freq_s) {
                res += freq_s - freq_t;
            }
        }
        return res;
    }

    // TC : O(N)
    // SC : O(26) ~= O(1)
    int solve_approach_2(string& s, string& t) {
        int n = s.length();

        int diff[26] = {0};

        for (int i = 0; i < n; i++) {
            diff[s[i] - 'a']++;
            diff[t[i] - 'a']--;
        }

        int res = 0;
        for (int i = 0; i < 26; i++) {
            res += max(0, diff[i]);
        }
        return res;
    }    
public:
    int minSteps(string s, string t) {
        // return solve_approach_1(s, t);

        return solve_approach_2(s, t);
    }
};