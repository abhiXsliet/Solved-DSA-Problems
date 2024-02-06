// https://leetcode.com/problems/group-anagrams/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N * M(logM)) Where N = vector size & M = Max length of individuals strings of vector
    // SC : O(N)
    vector<vector<string>> solve_approach_1(vector<string>& strs, int n) {
        vector<vector<string>> result;

        unordered_map<string, vector<string>> mpp; // {sorted-string, {strings}}

        for (auto& str : strs) {
            string s = str;
            sort(begin(s), end(s));
            mpp[s].push_back(str);
        }

        for (auto& it : mpp) {
            result.push_back(it.second);
        }

        return result;
    }

    // TC : O(M) Where M = string length
    // SC : O(M)
    string generateWord(string& str) {
        int freq[26] = {0};

        for (char& ch : str) {
            freq[ch - 'a'] ++;
        }

        string generatedWord;
        for (int i = 0; i < 26; i++) {

            if (freq[i] != 0) {
                generatedWord += string(freq[i], i + 'a');
            }
        }
        return generatedWord;
    }

    // TC : O(N*M) Where N = input size and M = max length of string in input size 
    // SC : O(N)
    vector<vector<string>> solve_approach_2(vector<string>& strs, int n) {
        vector<vector<string>> result;

        unordered_map<string, vector<string>> mpp;

        for (string& str : strs) {

            string s = generateWord(str);

            mpp[s].push_back(str);
        }

        for (auto& it : mpp) {
            result.push_back(it.second);
        }

        return result;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // return solve_approach_1(strs, strs.size());

        return solve_approach_2(strs, strs.size());
    }
};
