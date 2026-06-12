// https://www.geeksforgeeks.org/problems/check-if-a-string-is-repetition-of-its-substring-of-k-length3302/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool kSubstr(string &s, int k) {

        int n = s.size();

        if (n % k != 0)
            return false;

        unordered_map<string, int> mp;

        int blocks = n / k;
        int maxFreq = 0;

        for (int i = 0; i < n; i += k) {
            string sub = s.substr(i, k);
            maxFreq = max(maxFreq, ++mp[sub]);
        }

        return (blocks - maxFreq <= 1);
    }
};