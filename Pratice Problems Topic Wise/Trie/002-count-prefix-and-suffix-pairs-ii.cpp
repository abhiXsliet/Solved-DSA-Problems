// https://leetcode.com/problems/count-prefix-and-suffix-pairs-ii/



#include <bits/stdc++.h>
using namespace std;

class Trie {
    public:
    struct TrieNode {
        bool isTerminal;
        queue<int> indices;
        TrieNode* children[26];
    };

    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    TrieNode* getNode() {
        TrieNode* newNode = new TrieNode();
        newNode -> isTerminal = false;
        newNode -> indices = queue<int>();
        for (int i = 0; i < 26; i ++) {
            newNode -> children[i] = NULL;
        }
        return newNode;
    }

    void insert(string &word, int i) {
        TrieNode* crawl = root;
        for (char &ch : word) {
            int idx = ch - 'a';
            if (!crawl -> children[idx]) {
                crawl -> children[idx] = getNode();
            }
            crawl = crawl -> children[idx];
            crawl -> indices.push(i);
        }
        crawl -> isTerminal = true;
    }

    void deleteNodes(string &word, int j) {
        TrieNode* crawl = root;
        for (char &ch : word) {
            int idx = ch - 'a';
            if (!crawl -> children[idx]) {
                return;
            }
            crawl = crawl -> children[idx];
            crawl -> indices.pop();
        }
        crawl -> isTerminal = false;
    }

    queue<int> search(string &word) {
        TrieNode* crawl = root;
        for (char &ch : word) {
            int idx = ch - 'a';
            if (!crawl -> children[idx]) {
                return queue<int>();
            }
            crawl = crawl -> children[idx];
        }
        return crawl -> indices;
    }
};

class TrieNew {
    public:
    struct TrieNode {
        int counter;
        unordered_map<string, TrieNode*> mpp;
    };

    TrieNode* root;
    TrieNew() {
        root = new TrieNode();
        root -> counter = 0;
        root -> mpp[""] = NULL;
    }

    void insert(string &word, long long &ans) {
        int m = word.length();
        TrieNode* crawl = root;
        int i = 0, j = m - 1;
        while (i < m && j >= 0) {
            string s = to_string(word[i]) + to_string(word[j]);
            if (!crawl -> mpp.count(s)) {
                crawl -> mpp[s] = new TrieNode();
            }
            crawl = crawl -> mpp[s];
            ans += crawl -> counter;
            i ++, j --;
        }
        crawl -> counter += 1;
    }
};

class Solution {
private:
    vector<int> findInterSection(queue<int>& a, queue<int>& b) {
        vector<int> intersected;
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a.front() == b.front()) {
                intersected.push_back(a.front());
                a.pop();
                b.pop();
            } else if (a.front() > b.front()) b.pop();
            else a.pop();
        }
        return intersected;
    }

    void insertInMpp(unordered_map<int, multiset<int>>& mpp, vector<int>& intersects, int i) {
        for (int &indices : intersects) {
            mpp[i].insert(indices);
        }
    }

    // TC : O(N * (N + M))
    // SC : O(N * M)
    long long approach_1(vector<string>& words) {
        int n = words.size();

        Trie prefixTrie;
        Trie suffixTrie;

        for (int i = 0; i < n; i ++) {
            prefixTrie.insert(words[i], i);
            string rev_word_i = words[i];
            reverse(begin(rev_word_i), end(rev_word_i));
            suffixTrie.insert(rev_word_i, i);
        }

        unordered_map<int, multiset<int>> mpp;
        long long ans = 0;
        
        for (int i = 0; i < n; i ++) {
            prefixTrie.deleteNodes(words[i], i);
            string rev_word_i = words[i];
            reverse(begin(rev_word_i), end(rev_word_i));
            suffixTrie.deleteNodes(rev_word_i, i);

            queue<int>foundIndices_1 = prefixTrie.search(words[i]);     // O(N)
            queue<int>foundIndices_2 = suffixTrie.search(rev_word_i);   // O(N)

            vector<int>intersected = findInterSection(foundIndices_1, foundIndices_2);  
            insertInMpp(mpp, intersected, i);

            for (auto& it : mpp) {
                ans += it.second.size();
            }
            mpp.clear();
        }
        return ans;
    }

    // TC : O(N * M) Where N = No. of strings in words array
    // SC : O(N * M) Where M = Average length of each word
    long long approach_2(vector<string>& words) {
        int n = words.size();
        TrieNew prefSuff;
        long long ans = 0;
        for (string &word : words) {
            prefSuff.insert(word, ans); // for "aba", entries in tries => "aa", "bb", "aa"
        }
        return ans;
    }
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        // return approach_1(words);    // TLE

        return approach_2(words);
    }
};