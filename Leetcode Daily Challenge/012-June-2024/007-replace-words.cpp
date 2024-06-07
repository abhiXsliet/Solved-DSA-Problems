// https://leetcode.com/problems/replace-words/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(L*N) Where L = Length of Sentence & N = Max Length of Individual Words of Sentences
    // SC : O(M)   Where M = Size of Dictionary
    string approach_1(vector<string>& dictionary, string sentence) {
        unordered_set<string> dict(begin(dictionary), end(dictionary));
        string result;

        stringstream ss(sentence);
        string word = "";
        
        while(getline(ss, word, ' ')) {     // ss >> word : we can use instead of getline(ss, word, ' ')
            int n = word.length();
            bool found = 0;
            for (int i = 0; i <= word.length(); i ++) {
                string prefix = word.substr(0, i);
                if (dict.find(prefix) != dict.end()) {
                    if (!result.empty()) {
                        result += " ";
                    } 
                    result += prefix;
                    found = 1;
                    break;
                } 
            }
            if (found == 0) {
                if (!result.empty()) {
                    result += " ";
                } 
                result += word;
            }
        }
        
        return result;
    }
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        return approach_1(dictionary, sentence);
    }
};