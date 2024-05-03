// https://leetcode.com/problems/compare-version-numbers/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<string> getTokens(string version) {
        vector<string> tokens;
        stringstream ss(version);
        string token;
        while(getline(ss, token, '.')) {
            tokens.push_back(token);
        }
        return tokens;
    }
public:
    // TC : O(max(n, m)) where n, m are the length of version1, version2 resp.
    // SC : O(n + m)
    int compareVersion(string version1, string version2) {
        vector<string> v1 = getTokens(version1);
        vector<string> v2 = getTokens(version2);

        int n = v1.size(), m = v2.size();

        for (int i = 0; i < max(n, m); i++) {
            
            int a = i < n ? stoi(v1[i]) : 0;
            int b = i < m ? stoi(v2[i]) : 0;

            if (a < b) return -1;
            else if (a > b) return 1;
        }
        return 0;   // code flow reaches here only if all version numbers are equal
    }
};
