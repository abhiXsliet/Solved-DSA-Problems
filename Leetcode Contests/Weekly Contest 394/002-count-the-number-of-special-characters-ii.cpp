// https://leetcode.com/problems/count-the-number-of-special-characters-ii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    int numberOfSpecialChars(string word) {
        vector<int> lower(26, -1), upper(26, -1);

        for (int i = 0; i < word.length(); i++) {
            if (islower(word[i])) {
                lower[word[i] - 'a'] = i;
            }
            else {
                if (upper[word[i] - 'A'] == -1) {
                    upper[word[i] - 'A'] = i;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (lower[i] != -1 && upper[i] != -1 && lower[i] < upper[i]) {
                ans += 1;
            }
        }
        return ans;
    }
};