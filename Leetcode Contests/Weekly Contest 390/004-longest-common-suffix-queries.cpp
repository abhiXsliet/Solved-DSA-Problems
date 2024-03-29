// https://leetcode.com/problems/longest-common-suffix-queries/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    struct TrieNode {
        int idx;
        TrieNode* children[26];
    };

    TrieNode* getNode(int i) {
        TrieNode* newNode = new TrieNode(i);
        newNode -> idx = i;
        for (int i = 0; i < 26; i++) {
            newNode -> children[i] = NULL;
        }
        return newNode;
    };
    
    void insertTrie(TrieNode* root, vector<string>& wordsContainer, int i) {
        string word = wordsContainer[i];
        int n       = word.length();

        for (int j = n - 1; j >= 0; j--) {
            char ch    = word[j];
            int ch_idx = word[j] - 'a';

            if (root -> children[ch_idx] == NULL) {
                root -> children[ch_idx] = getNode(i);
            }

            root = root -> children[ch_idx];

            if (wordsContainer[root -> idx].length() > n) {
                root -> idx = i;
            }
        }
    }

    int searchTrie(TrieNode* root, string& word) {
        int result_idx = root -> idx;   // empty suffix : smallest index of string stored in root -> idx
        int n          = word.length();

        for (int i = n - 1; i >= 0; i--) {
            int ch_idx = word[i] - 'a';

            root = root -> children[ch_idx];

            if (root == NULL) {
                return result_idx;
            }
            result_idx = root -> idx;
        }
        return result_idx;
    }
public:
    // TC (insert) : O(N) Where N = Total No. of Chars in wordsContainer
    // TC (search) : O(M) Where M = Total No. of Chars in wordsQuery
    // SC          : O(N) 
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int n = wordsContainer.size();
        int m = wordsQuery.size();

        TrieNode* root = new TrieNode(0);

        for (int i = 0; i < n; i++) {
            int indx = root -> idx;
            if (wordsContainer[indx].length() > wordsContainer[i].length()) {
                root -> idx = i;
            }
            insertTrie(root, wordsContainer, i);
        }

        vector<int> result(m);

        for (int i = 0; i < m; i++) {
            result[i] = searchTrie(root, wordsQuery[i]);
        }

        return result;
    }
};