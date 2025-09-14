// https://leetcode.com/problems/vowel-spellchecker/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_set<string> exactMatch;
    unordered_map<string, string> capsMatch;
    unordered_map<string, string> vowelMatch;

    bool isVowel(char &ch) {
        ch = tolower(ch);
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    string toLowerCase(string word) {
        for (char &ch : word) {
            ch = tolower(ch);
        }
        return word;
    }
    
    // replace vowels with a (*)
    string replaceVowel(string word) {
        for (char &ch : word) {
            if (isVowel(ch)) {
                ch = '*';
            }
        }
        return word;
    }

    string getMatch(string &query) {
        if (exactMatch.count(query)) {
            return query;
        }

        // case error check
        string lowered = toLowerCase(query);
        if (capsMatch.count(lowered)) {
            return capsMatch[lowered];
        }

        // vowel error check
        string replaced = replaceVowel(query);
        if (vowelMatch.count(replaced)) {
            return vowelMatch[replaced];
        }
        return "";
    }
public:
    // TC : O(N) 
    // SC : O(N)
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        exactMatch.clear();
        capsMatch.clear();
        vowelMatch.clear();

        for (string &word : wordlist) {
            exactMatch.insert(word);

            string lowerWord = toLowerCase(word);
            if (!capsMatch.count(lowerWord)) {
                capsMatch[lowerWord] = word;
            }

            string vowelWord = replaceVowel(lowerWord);
            if (!vowelMatch.count(vowelWord)) {
                vowelMatch[vowelWord] = word;
            }
        }    

        vector<string> result;
        for (string &query : queries) {
            result.push_back(getMatch(query));
        }
        return result;
    }
};