// https://leetcode.com/problems/shortest-matching-substring/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(M)
    // SC : O(M)
    vector<int> getLps(string pattern) {
        int m = pattern.length();
        vector<int> lps(m, 0);
        int i = 1, len = 0;
        while (i < m) {
            if (pattern[i] == pattern[len]) {
                len ++;
                lps[i] = len;
                i ++;
            } else {
                if (len != 0) 
                    len = lps[len - 1];
                else {
                    lps[i] = 0;
                    i ++;
                }
            }
        }
        return lps;
    }
public:
    // TC : O(M + N)
    // SC : O(M + N)
    int shortestMatchingSubstring(string s, string p) {
        int m = s.length();
        int n = p.length();

        if (n == 0) return 0;   // only two stars are available

        vector<int> starIdx;
        for (int i = 0; i < n; i ++) {
            if (p[i] == '*') {
                starIdx.push_back(i);
            }
        }   

        string p1 = p.substr(0, starIdx[0]);
        string p2 = p.substr(starIdx[0] + 1, starIdx[1] - starIdx[0] - 1);
        string p3 = p.substr(starIdx[1] + 1, n - starIdx[1] - 1);

        int p1_len = p1.length();
        int p2_len = p2.length();
        int p3_len = p3.length();

        string prefix = (p1 + "$" + s);
        string middle = (p2 + "$" + s);
        string suffix = (p3 + "$" + s);

        vector<int> prefixLps = getLps(prefix);
        vector<int> middleLps = getLps(middle);
        vector<int> suffixLps = getLps(suffix);

        prefixLps = vector<int>(begin(prefixLps) + p1_len + 1, end(prefixLps));
        middleLps = vector<int>(begin(middleLps) + p2_len + 1, end(middleLps));
        suffixLps = vector<int>(begin(suffixLps) + p3_len + 1, end(suffixLps));

        int i = 0, j = 0, k = 0;
        int result = INT_MAX;
        while (i + p2_len + p3_len < m) {
            while (i < m && prefixLps[i] != p1_len) i ++;
            if (i >= m) break;

            while (j < m && (j < i + p2_len || middleLps[j] != p2_len)) j ++;
            if (j >= m) break;

            while (k < m && (k < j + p3_len || suffixLps[k] != p3_len)) k ++;
            if (k >= m) break;

            result = min(result, k - i + p1_len);
            i ++;
        }
        return result == INT_MAX ? -1 : result;
    }
};