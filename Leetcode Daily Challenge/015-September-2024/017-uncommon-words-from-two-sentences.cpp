// https://leetcode.com/problems/uncommon-words-from-two-sentences/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(M + N)
    // SC : O(M + N)
    vector<string> approach_1(string& s1, string& s2) {
        vector<string> res;
        unordered_map<string, int> mpp;

        stringstream ss(s1);
        string word;
        while (getline(ss, word, ' ')) {
            mpp[word] ++;
        }

        stringstream strS(s2);
        
        while (getline(strS, word, ' ')) {
            mpp[word] ++;
        }

        for (auto& it : mpp) {
            if (it.second == 1) {
                res.push_back(it.first);
            }
        }

        return res;
    }
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        return approach_1(s1, s2);
    }
};