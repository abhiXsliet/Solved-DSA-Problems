// https://leetcode.com/contest/weekly-contest-381/problems/minimum-number-of-pushes-to-type-word-ii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N*log(N))
    // SC : O(1)
    int minimumPushes(string word) {
        vector<int> freq(26, 0);

        for (char& ch : word) {
            freq[ch - 'a'] ++;
        }

        sort(begin(freq), end(freq), greater<int>());
        
        int result = 0;

        for (int i = 0; i < 26; i++) {
            int num = freq[i];
            
            int times_key_press = i / 8 + 1;

            result += num * times_key_press;
        }

        return result;
    }
};