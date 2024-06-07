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
    
    struct TrieNode {
        TrieNode* children[26];
        bool isTerminal;
    };

    TrieNode* getNode() {
        TrieNode* newNode = new TrieNode();
        newNode -> isTerminal = false;
        for (int i = 0; i < 26; i ++) {
            newNode -> children[i] = NULL;
        }
        return newNode;
    }
    
    TrieNode* root;
    void insert(string word) {
        TrieNode* crawler = root;

        for (int i = 0; i < word.length(); i ++) {
            int idx = word[i] - 'a';
            if (crawler -> children[idx] == NULL) {
                crawler -> children[idx] = getNode();
            }
            crawler = crawler -> children[idx];
        }

        crawler -> isTerminal = 1;
    }

    string search(string word) {
        TrieNode* crawler = root;

        for (int i = 0; i < word.length(); i ++) {
            int idx = word[i] - 'a';

            if (crawler -> children[idx] == NULL) {
                return word;
            }
            crawler = crawler -> children[idx];
            if (crawler -> isTerminal) {
                return word.substr(0, i + 1);   // shortest root of word
            }
        }

        return word;
    }

    // TC : O(N * L) Where N = Total Words of the dictionary
    // SC : O(N * L) Where L = Iterating over each chars of the word of dictionary
    string approach_2(vector<string>& dictionary, string sentence) {
        root = getNode();

        for (string& word : dictionary) {
            insert(word);
        }

        stringstream ss(sentence);
        string word;
        string result;

        while (getline(ss, word, ' ')) {
            result += search(word) + " ";
        }
        result.pop_back();
        return result;
    }
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        // return approach_1(dictionary, sentence);

        return approach_2(dictionary, sentence);
    }
};