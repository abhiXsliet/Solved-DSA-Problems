// https://leetcode.com/problems/largest-3-same-digit-number-in-string/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(1)
    string brute(string num) {
        int n = num.length();

        int i = 0, j = 0;
        string result;
        unordered_map<char, int> mpp;

        while (j < n) {
            mpp[num[j]] ++;
            while (mpp.size() > 1) {
                mpp[num[i]] --;
                if (!mpp[num[i]]) mpp.erase(num[i]);
                i ++;
            }
            for (auto &it : mpp) {
                if (it.second == 3) {
                    string str(3, it.first);
                    if (result < str) {
                        result = str;
                    }
                }
            }
            j ++;
        }

        return result;
    }

    // TC : O(N)
    // SC : O(1)
    string optimal(string num) {
        int n = num.length();
        string result;
        for (int i = 0; i < n - 2; i ++) {
            if (num[i] == num[i + 1] && num[i + 1] == num[i + 2]) {
                result = max(result, num.substr(i, 3));
            }
        }
        return result;
    }
public:
    string largestGoodInteger(string num) {
        // return brute(num);
        return optimal(num);
    }
};