// https://leetcode.com/problems/longest-subsequence-repeated-k-times/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int n;

    bool isSubsequence(string &s, int k, string curr) {
        int i = 0, j = 0, len = curr.length();
        while (i < n && j < len * k) {
            if (s[i] == curr[j % len]) j ++;
            i ++;
        }
        return (j == (k * len));
    }

    bool backtrackOptimized(string &s, int k, string curr, string &result, vector<int> &allowed, int maxLen) {
        if (curr.length() == maxLen) {
            if (isSubsequence(s, k, curr)) {
                result = curr;
                return true;
            }
            return false;
        }
        
        for (int i = 25; i >= 0; i --) {
            if (!allowed[i]) continue;

            allowed[i] -= 1;
            char ch = (i + 'a');
            curr.push_back(ch);
            
            if (backtrackOptimized(s, k, curr, result, allowed, maxLen)) 
                return true;

            allowed[i] += 1;
            curr.pop_back();
        }
        return false;
    }

    void backtrack(string &s, int k, string curr, string &result, vector<int> &allowed) {
        if (curr.length() * k > n) return;

        if (((curr.length() > result.length()) || (curr.length() == result.length() && curr > result)) && isSubsequence(s, k, curr)) {
            result = curr;
        }
        
        for (int i = 25; i >= 0; i --) {
            if (!allowed[i]) continue;

            allowed[i] -= 1;
            char ch = (i + 'a');
            curr.push_back(ch);
            
            backtrack(s, k, curr, result, allowed);

            allowed[i] += 1;
            curr.pop_back();
        }
    }

    // TC : O(N * (N / K)!) (N/K) total possible subsequences and N for checking isSubsequence 
    // SC : O(N / K)
    string approach_1(string &s, int k) {
        vector<int> freq(26, 0);
        for (char &ch : s) {
            freq[ch - 'a'] ++;
        }

        vector<int> allowed(26, 0);
        for (int i = 0; i < 26; i ++) {
            if (freq[i] < k) continue;
            allowed[i] = (freq[i] / k);
        }

        string result;
        backtrack(s, k, "", result, allowed);
        return result;
    }

    // TC : O(N * (N / K)!)
    // SC : O(N / K)
    string approach_2(string &s, int k) {
        vector<int> freq(26, 0);
        for (char &ch : s) {
            freq[ch - 'a'] ++;
        }

        vector<int> allowed(26, 0);
        for (int i = 0; i < 26; i ++) {
            if (freq[i] < k) continue;
            allowed[i] = (freq[i] / k);
        }

        int maxLen = n / k;
        string result;
        for (int len = maxLen; len >= 1; len --) {
            if (backtrackOptimized(s, k, "", result, allowed, len)) {
                return result;
            }
        }
        return result;
    }
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        n = s.length();

        // return approach_1(s, k);    // backtrack explore all cases
        return approach_2(s, k);    // optimized backtrack due to early termination
    }
};