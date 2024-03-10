// https://leetcode.com/contest/weekly-contest-388/problems/shortest-uncommon-substring-in-an-array/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(n * (m^3 + m^2*log(m) + m^2*n*m)) ~= O(n^2 * m^2)
    // SC : O(N) + O(m^2) Where N = arr.size() & M = max length of individual strings of arr
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n = arr.size();
        vector<string> res(n, "");
        for (int i = 0; i < n; i++) {
            vector<string> st;
            
            int m = arr[i].length();
            // O(m^3)
            for (int j = 0; j < m; j++) {
                for (int len = 1; len <= m - j; len++) {
                    string substr = arr[i].substr(j, len);
                    st.push_back(substr);
                }
            }
            
            auto cmp = [&](string s1, string s2) {
                if (s1.length() == s2.length())
                    return s1 < s2;
                return s1.length() < s2.length();
            };
            sort(begin(st), end(st), cmp); // O(m^2 * log(m))
            
            for (auto& str : st) {  // O(m^2)
                bool flag = 0;
                for (int k = 0; k < n; k++) { // O(n)
                    if (k != i && (arr[k].find(str) != string::npos)) { // O(m)
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    res[i] = str;
                    break;
                }
            }
        }
        return res;
    }
};