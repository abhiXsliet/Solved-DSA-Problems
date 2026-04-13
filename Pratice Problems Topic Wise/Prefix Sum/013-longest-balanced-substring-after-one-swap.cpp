// https://leetcode.com/problems/longest-balanced-substring-after-one-swap/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();

        int tZeros = 0, tOnes = 0;
        for (char &ch : s) {
            if (ch == '0') tZeros += 1;
            else tOnes += 1;
        }

        unordered_map<int, vector<int>> mpp;
        mpp[0].push_back(-1);
        int sum = 0;
        int maxL = 0;

        for (int i = 0; i < n; i ++) {
            sum += (s[i] == '0') ? -1 : 1;

            if (mpp.count(sum)) {
                maxL = max(maxL, i - mpp[sum][0]);
            }

            if (mpp.count(sum - 2)) {
                for(int &id : mpp[sum - 2]){
                    int len = i - id;
                    int bLen = len - 2;
                    int zeros = bLen / 2;
                    if (tZeros > zeros) {
                        maxL = max(maxL, len);
                        break;
                    }
                }
            }

            if (mpp.count(sum + 2)) {
                for(int &id : mpp[sum + 2]){
                    int len = i - id;
                    int bLen = len - 2;
                    int ones = bLen / 2;
                    if (tOnes > ones) {
                        maxL = max(maxL, len);
                        break;
                    }
                }
            }

            mpp[sum].push_back(i);
        }

        return maxL;
    }
};