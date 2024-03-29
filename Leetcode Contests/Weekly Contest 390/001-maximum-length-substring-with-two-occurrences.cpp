// https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^3)
    // SC : O(N)
    int solve_1(string s) {
        int n = s.length();
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                string subStr = s.substr(i, j-i+1);
                unordered_map<int, int> mpp;
                for(char& ch : subStr) {
                    mpp[ch] ++;
                }
                bool flag = 0;
                for (auto& it : mpp) {
                    if (it.second > 2) {
                        flag = 1;
                        break;
                    }
                }
                int len = subStr.length();
                if (flag == 0) {
                    ans = max(ans, len);
                }
            }
        }
        return ans;
    }

    // TC : O(N^2)
    // SC : O(26)
    int solve_2(string s) {
        int n = s.length();
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> count; // max-size : 26
            for (int j = i; j < n; j++) {
                count[s[j]] ++;
                if (count[s[j]] > 2) break;
                ans = max(ans, j - i + 1);
            }
            count.clear();
        }
        return ans;
    }

    // TC : O(N)
    // SC : O(26) ~= O(1)
    int solve_3(string s) {
        int n = s.length();
        unordered_map<char, int> count;

        int i = 0, j = 0;
        int maxLen = INT_MIN;

        while (j < n) {
            count[s[j]] ++;
            while(count[s[j]] > 2) {
                count[s[i]] --;
                i ++;
            }
            maxLen = max(maxLen, j - i + 1);
            j ++;
        }
        return maxLen;
    }
public:
    int maximumLengthSubstring(string s) {
        // return solve_1(s);

        // return solve_2(s);

        return solve_3(s);      // SLIDING WINDOW
    }
};