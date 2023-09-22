// https://leetcode.com/problems/is-subsequence/


#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
    // TC = O(m + n) where m, n is the length of string-1, string-2 respectively
    bool solve_brute(string s, string t) {
        int i = 0, j = 0;
        int m = s.length(), n = t.length();

        while (i < m && j < n) {
            if (s[i] == t[j]) i++;
            j++;
        }
        return i == m;
    }


    // TC = O(M * log(N)) 
    // better approach for lots of incoming s, say s1, s2, ..., sk where k >= 109
    bool solve_better(string s, string t) {
        int m = s.length(), n = t.length();
        
        map<char, vector<int>> mpp;
        int prev = -1;

        for (int i = 0; i < n; i++) {
            mpp[t[i]].push_back(i);
        }

        for (int i = 0; i < m; i++) {
            char ch = s[i];

            if (mpp.find(ch) == mpp.end())
                return false;

            vector<int> indices = mpp[ch];

            auto it = upper_bound(indices.begin(), indices.end(), prev); // log(n)

            if (it == indices.end())
                return false;
            
            prev = *it;
        }

        return true;
    }
public:
    bool isSubsequence(string s, string t) {
        // return solve_brute(s, t);

        return solve_better(s, t);
    }
};