// https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/

#include <bits/stdc++.h>
using namespace std;



class Trie {
    public:
    struct TrieNode {
        bool isTerminal;
        TrieNode* children[26];
    };

    TrieNode* getNode() {
        TrieNode* newNode = new TrieNode();
        newNode -> isTerminal = 0;
        for (int i = 0; i < 26; i ++) {
            newNode -> children[i] = NULL;
        }
        return newNode;
    }

    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    void insertInTrie(string &word) {
        TrieNode* crawl = root;
        for (char &ch : word) {
            int idx = ch - 'a';
            if (!crawl -> children[idx]) {
                crawl -> children[idx] = getNode();
            }
            crawl = crawl -> children[idx];
        }
        crawl -> isTerminal = true;;
    }

    int searchInTrie(string &word) {
        TrieNode* crawl = root;
        for (char &ch : word) {
            int idx = ch - 'a';
            if (!crawl -> children[idx])
                return 0;
            crawl = crawl -> children[idx];
        }
        return true;
    }
};

class Solution {
private:
    // TC : O(m1 + m2)
    // SC : O(1)
    bool isPrefixAndSuffix(string& pat, string& text) {
        int m1 = pat.length(), m2 = text.length();
        int i = 0, j = 0;
        while (i < m1 && j < m2) {
            if (pat[i] != text[j] || pat[m1 - i - 1] != text[m2 - j - 1]) {
                return false;
            }
            i ++, j ++;
        }
        return i == m1;
    }

    // TC : O(N * N * M)
    // SC : O(1)
    int approach_1(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    ans ++;
                }
            }
        }
        return ans;
    }

    // TC : O(N^2 * M) Where N = No. of words & M = Avg. length of each word
    // SC : O(N * M)
    int approach_2(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        
        for (int j = 0; j < n; j ++) {
            Trie prefixTrie;
            Trie suffixTrie;
            
            string rev_word_j = words[j];
            reverse(begin(rev_word_j), end(rev_word_j));
            
            prefixTrie.insertInTrie(words[j]);
            suffixTrie.insertInTrie(rev_word_j);

            for (int i = 0; i < j; i ++) {
                if (words[i].length() > words[j].length()) 
                    continue;

                string rev_word_i = words[i];
                reverse(begin(rev_word_i), end(rev_word_i));
                
                if (prefixTrie.searchInTrie(words[i]) && suffixTrie.searchInTrie(rev_word_i)) {
                    ans += 1;
                }
            }
        }
        return ans;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        // return approach_1(words);    // BRUTE

        return approach_2(words);   // Using Trie
    }
};