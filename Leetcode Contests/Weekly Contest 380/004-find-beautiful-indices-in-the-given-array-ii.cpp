// https://leetcode.com/contest/weekly-contest-380/problems/find-beautiful-indices-in-the-given-array-ii/



#include <bits/stdc++.h>    
using namespace std;

class Solution {
private:
    vector<int> prefixStore(string s) {
        int n = s.length();
        vector<int> prefix_idx(n, 0);

        for (int i = 1; i < n; i++) {
            int j = prefix_idx[i - 1];

            while (j > 0 && s[i] != s[j]) {
                j = prefix_idx[j - 1];
            }

            if (s[i] == s[j]) j ++;
            prefix_idx[i] = j;
        }
        return prefix_idx;
    }
    
    vector<int>search(string pat, string txt) {
            vector<int> prefix = prefixStore(pat);
            
            vector<int> result;
            int i = 0, j = 0;
            
            while (i < txt.size()) {
                if (txt[i] == pat[j]) {
                    i++, j++;
                }
                else {
                    if (j != 0) {
                        j = prefix[j - 1];
                    }
                    else {
                        i ++;
                    }
                }
                
                if (j == pat.size()) {
                    result.push_back(i - j);
                    j = prefix[j - 1];
                }
            }
            return result;
        }
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> storeIndices_a = search(a, s);
        vector<int> storeIndices_b = search(b, s);
        
        vector<int> result;
        int i = 0, j = 0;
        
        while (i < storeIndices_a.size() && j < storeIndices_b.size()) {
            if (abs(storeIndices_a[i] - storeIndices_b[j]) <= k) {
                result.push_back(storeIndices_a[i]);
                i++;
            } else if (storeIndices_a[i] < storeIndices_b[j]) {
                i++; 
            } else {
                j++; 
            }
        }
        
        return result;
    }
};