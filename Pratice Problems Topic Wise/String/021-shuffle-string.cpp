// https://leetcode.com/problems/shuffle-string/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC = O(N)
    // SC = O(1)
    string restoreString(string s, vector<int>& indices) {
        int n = s.length();
        
        string result(n, 0);

        for (int i = 0; i < n; i++) {
            result[indices[i]] = s[i];
        }

        return result;
    }
};