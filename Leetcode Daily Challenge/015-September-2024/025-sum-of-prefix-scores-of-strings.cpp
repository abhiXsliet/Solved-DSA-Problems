// https://leetcode.com/problems/sum-of-prefix-scores-of-strings/




#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    int count;
    TrieNode* children[26]; // a, b, c, ...., z
};

class Solution {
private:
    TrieNode* getTrieNode() {
        TrieNode* node = new TrieNode();
        node -> count  = 0;
        for (int i = 0; i < 26; i ++) {
            node -> children[i] = NULL;
        }
        return node;
    }

    void insertInTrie(TrieNode* root, string& s) {
        TrieNode* crawl = root;

        for (char& ch : s) {
            int idx = ch - 'a';
            if (!crawl -> children[idx]) {
                crawl -> children[idx] = getTrieNode();
            } 

            crawl -> children[idx] -> count += 1;
            crawl  = crawl -> children[idx];
        }
    }

    int searchInTrie(TrieNode* root, string& s) {
        TrieNode* crawl = root;
        int score = 0;

        for (char& ch : s) {
            int idx = ch - 'a';
            score += crawl -> children[idx] -> count; 
            crawl  = crawl -> children[idx];
        }

        return score;
    }
public:
    // TC : O(N * M) Where N = Words array size and M = Max Length of individual word
    // SC : O(N * M)
    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode* root = getTrieNode();

        for (string& word : words) {
            insertInTrie(root, word);
        }

        int n = words.size();
        vector<int> result(n, 0);
        
        for (int i = 0; i < n; i ++) {
            result[i] = searchInTrie(root, words[i]);
        }

        return result;
    }
};