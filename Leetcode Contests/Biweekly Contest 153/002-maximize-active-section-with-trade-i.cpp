// https://leetcode.com/problems/maximize-active-section-with-trade-i/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
        // TC : O(N)
        // SC : O(N)
        int approach_1(string &s) {
            int n = s.length();
    
            vector<pair<int, int>> store;
    
            int cntOne  = s[0] == '1' ? 1 : 0;
            int cntZero = s[0] == '0' ? 1 : 0;
            int totalOnes = s[0] == '1' ? 1 : 0;
            for (int i = 1; i < n; i ++) {
                if (s[i] == '0') {
                    if (s[i] == s[i - 1]) cntZero += 1;
                    else {
                        cntZero = 1;
                        store.push_back({1, cntOne});
                        cntOne = 0;
                    }
                } else {
                    if (s[i] == s[i - 1]) cntOne += 1;
                    else {
                        cntOne = 1;
                        store.push_back({0, cntZero});
                        cntZero = 0;
                    }
                    totalOnes += 1;
                }
            }
    
            if (cntZero > 0) store.push_back({0, cntZero});
            if (cntOne  > 0) store.push_back({1,  cntOne});
    
            int len = store.size();
            int ans = 0;
            for (int i = 0; i < len; i ++) {
                if (store[i].first == 1) {
                    int leftZero  = (i > 0)       ? store[i - 1].second : 0;
                    int rightZero = (i + 1 < len) ? store[i + 1].second : 0;
                    
                    int leftRightZeros       = (leftZero && rightZero) ? (leftZero + rightZero) : 0;
    
                    int largestActiveSegment = leftRightZeros + totalOnes;
    
                    ans = max(ans, largestActiveSegment);
                }
            }
            return ans;
        }
    
        // // TC : O(N)
        // // SC : O(1)
        // int approach_2(string &s) {
        //     int n = s.length();
    
    
        // }
    public:
        int maxActiveSectionsAfterTrade(string s) {
            return approach_1(s);
            // return approach_2(s);   // pending : optimized space to O(1)
        }
    };