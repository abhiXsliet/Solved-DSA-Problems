// https://leetcode.com/contest/weekly-contest-355/problems/split-strings-by-separator/


#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> ans;
        for(string word : words) {
            string newWord;
            for(char ch : word) {
                if(ch == separator) {
                    if(!newWord.empty()) {
                        ans.push_back(newWord);
                        newWord = "";
                    }
                } else {
                    newWord += ch;
                }
            } 
            if(!newWord.empty()) {
                ans.push_back(newWord);
            }
        }
        return ans;
    }
};