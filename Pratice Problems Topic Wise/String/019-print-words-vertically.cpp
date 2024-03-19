// https://leetcode.com/problems/print-words-vertically/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N*M) where n is the number of words in the string and m is the length of the longest word
    // SC : O(N*M)
    vector<string> printVertically(string s) {
        vector<string> result;
        int n = s.length();

        // Using istringstream to split the string into words
        istringstream iss(s);
        
        // // one liner
        // vector<string> words(istream_iterator<string>{iss}, istream_iterator<string>());

        vector<string> words;

        string word;
        while (iss >> word) {
            words.push_back(word);
        }

        int maxLen = 0;
        for (int i = 0; i < words.size(); i++) {
            maxLen = max(maxLen, (int)words[i].length());
        }

        // for (auto& word : words) cout << word << " ";
        
        for (int i = 0; i < maxLen; i++) {
            string str = "";
            for (int j = 0; j < words.size(); j++) {
                if (i < words[j].length()) {
                    str += words[j][i];
                } else {
                    str += ' ';
                }
            }
            // Trim the trailing spaces before adding to the result
            str.erase(str.find_last_not_of(" ") + 1);
            
            if (!str.empty())
                result.push_back(str);
        }
        
        return result;
    }
};