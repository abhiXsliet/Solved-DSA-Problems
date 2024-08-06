// https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(26) ~= O(1)
    int minimumPushes(string word) {
        int n = word.size();
        vector<int> freq(26, 0);
        for (char& ch : word) 
            freq[ch - 'a'] ++;

        sort(rbegin(freq), rend(freq));

        int minPushes = 0;
        for (int i = 0; i < 26; i ++) {
            
            if (freq[i] == 0) break;
            
            int kPress = ((i / 8) + 1);
            minPushes += freq[i] * kPress;
        }
        return minPushes;
    }
};