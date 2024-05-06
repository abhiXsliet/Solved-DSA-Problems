// https://leetcode.com/problems/minimum-number-of-operations-to-make-word-k-periodic/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(N)
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int n = word.length();
        unordered_map<string, int> mpp;
        for (int i = 0; i < n; i+=k) {
            mpp[word.substr(i, k)] ++;
        }
        
        int max_occ = INT_MIN;
        string max_str = "";
        for (auto& it : mpp) {
            if (it.second > max_occ) {
                max_occ = it.second;
                max_str = it.first;
            }
        }
        
        mpp.erase(max_str);
        
        int ans = 0;
        for (auto& it : mpp) {
            ans += it.second;
        }
        return ans;
    }
};