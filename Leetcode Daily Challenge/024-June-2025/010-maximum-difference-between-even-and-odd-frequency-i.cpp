// https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(1)
    int way_1(string s) {
        int n = s.length();
        vector<int> freq(26, 0);
        for (char &ch : s) {
            freq[ch - 'a'] ++;
        }
        int maxDiff = INT_MIN;
        for (int i = 0; i < 26; i ++) {
            for (int j = 0; j < 26; j ++) {
                if (!freq[i] || !freq[j] || i == j) continue;
                if ((freq[i] % 2) && (freq[j] % 2 == 0)) {
                    maxDiff = max(maxDiff, freq[i] - freq[j]);
                }
            }
        }
        return maxDiff;
    }

    // TC : O(N)
    // SC : O(1)
    int way_2(string s) {
        int n = s.length();
        vector<int> freq(26, 0);
        for (char &ch : s) {
            freq[ch - 'a'] ++;
        }

        int maxOdd = 0, minEven = n;
        for (int i = 0; i < 26; i ++) {
            if (!freq[i]) continue;
            
            if (freq[i] % 2) {
                maxOdd = max(maxOdd, freq[i]);
            } else {
                minEven = min(minEven, freq[i]);
            }
        }
        return maxOdd - minEven;
    }
public:
    int maxDifference(string s) {
        // return way_1(s);
        return way_2(s);
    }
};