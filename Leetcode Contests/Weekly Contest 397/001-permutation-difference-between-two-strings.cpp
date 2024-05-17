// https://leetcode.com/contest/weekly-contest-397/problems/permutation-difference-between-two-strings/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(N) Where N = is the length of the string s
    int findPermutationDifference(string s, string t) {
        int n = s.length();
        unordered_map<char, int> freq;
        for (int i = 0; i < n; i++) {
            freq[t[i]] = i;
        }
        
        int result = 0;
        for (int i = 0; i < n; i ++) {
            result += abs(freq[s[i]] - i);
        }
        return result;
    }
};