// https://leetcode.com/problems/counting-words-with-a-given-prefix/



#include <bits/stdc++.h>
using namespace std;

class Trie {
    public:
    struct TrieNode {
        int isWordEnd;
        TrieNode* children[26];
    };

    TrieNode* root;
    Trie() {
        root = new TrieNode();
        root -> isWordEnd = 0;
        for (int i = 0; i < 26; i ++) {
            root -> children[i] = NULL;
        }
    }

    void insertNode(string& word, int n) {
        TrieNode* crawl = root;
        int m = word.length();
        for (int i = 0; i < min(n, m); i ++) {
            int idx = word[i] - 'a';
            if (!crawl -> children[idx]) {
                crawl -> children[idx] = new TrieNode();
            }
            crawl = crawl -> children[idx];
        }
        crawl -> isWordEnd += 1;
    }

    int searchNode(string &pref) {
        TrieNode* crawl = root;
        for (char &ch : pref) {
            int idx = ch - 'a';
            if (!crawl -> children[idx]) {
                return 0;
            }
            crawl = crawl -> children[idx];
        }
        return crawl -> isWordEnd;
    }
};

class Solution {
private:
    // TC : O(min(m, n))
    // SC : O(1)
    bool isPrefixInWord(string& s, string& p) {
        int m = s.length(), n = p.length();
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (s[i] != p[j])
                return false;
            i ++, j ++;
        }
        return j == n;
    }

    // TC : O(M * N)
    // SC : O(N) for the temporary substring
    int approach_1(vector<string>& words, string& pref) {
        int m = words.size(), n = pref.size();
        int ans = 0;
        for (string &word : words) {
            if (word.substr(0, n) == pref) {
                ans += 1;
            }
        }
        return ans;
    }

    // TC : O(M * N)
    // SC : O(1)
    int approach_2(vector<string>& words, string& pref) {
        int m = words.size(), n = pref.size();
        int ans = 0;
        for (string &word : words) {
            if (isPrefixInWord(word, pref)) {
                ans += 1;
            }
        }
        return ans;
    }

    // TC : O(M * N)
    // SC : O(M * N)
    int approach_3(vector<string>& words, string& pref) {
        int m = words.size(), n = pref.size();
        
        Trie buildTrie;
        for (string &word : words) {
            buildTrie.insertNode(word, n);
        }

        return buildTrie.searchNode(pref);
    }
public:
    int prefixCount(vector<string>& words, string pref) {
        // return approach_1(words, pref);  // Brute
        // return approach_2(words, pref);  // Extra Space Constant
        return approach_3(words, pref);  // Trie
    }
};