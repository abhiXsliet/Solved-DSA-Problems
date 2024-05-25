// https://leetcode.com/problems/word-break-ii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(2^N)
    // S.C : max depth of recursion is n (length of string s). You can say O(n) . You also have to store those sentences which is O(2^n)
    vector<string> solveNew(string s, unordered_set<string>& st, unordered_map<string, vector<string>>& mpp) {
        if (s.empty()) {
            return {""};
        }

        if (mpp.count(s)) {
            return mpp[s];
        }

        vector<string> result;
        for (int l = 1; l <= s.length(); l ++) {
            string currWord = s.substr(0, l);
            if (st.count(currWord)) {
                string remWord = s.substr(l);
                vector<string> remResult = solveNew(remWord, st, mpp);

                for (string& str : remResult) {
                    string toAdd = currWord + (str.empty() ? "" : " ") + str;
                    result.push_back(toAdd);
                }
            }
        }
        return mpp[s] = result;
    }

    // TC : O(2^N)
    // S.C : max depth of recursion is n (length of string s). You can say O(n) . You also have to store those sentences which is O(2^n)
    void solve(string& s, int n, vector<string>& res, unordered_set<string>& st, int i, string result) {
        if (i == n) {
            // Base case: If we have processed the entire string, add the result to the list
            res.push_back(result);
            return;
        }

        for (int j = i; j < n; j++) {
            string word = s.substr(i, j - i + 1);
            if (st.find(word) != st.end()) {
                // If the current substring is a valid word, recursively process the remaining part
                string newResult = result.empty() ? word : result + " " + word;
                solve(s, n, res, st, j + 1, newResult);
            }
        }
    }

    vector<string> approach_1(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<string> result;
        unordered_set<string> st(wordDict.begin(), wordDict.end());

        solve(s, n, result, st, 0, ""); // Start solving from index 0 with an empty result
        return result;
    }

    vector<string> approach_2(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> st(wordDict.begin(), wordDict.end());

        unordered_map<string, vector<string>> mpp;  // memoize

        return solveNew(s, st, mpp);
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // return approach_1(s, wordDict);

        return approach_2(s, wordDict);
    }
};