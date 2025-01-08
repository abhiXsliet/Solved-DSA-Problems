// https://leetcode.com/problems/implement-trie-prefix-tree/



#include <bits/stdc++.h>
using namespace std;

/**
 * Overall Time Complexity for insert, search, and startsWith:
 * - Insert: O(m) where m is the length of the word.
 * - Search: O(m) where m is the length of the word.
 * - StartsWith: O(p) where p is the length of the prefix.
 * 
 * Space Complexity:
 * - The Trie requires O(N * m) space where N is the number of inserted words and m is the average length of the words.
 * - Each word can create up to m nodes, leading to this space complexity.
 */
class Trie {
public:
    struct TrieNode {
        bool isEndOfWord;
        TrieNode* children[26];
    };

    TrieNode* getTrieNode() {
        TrieNode* newNode = new TrieNode();
        newNode -> isEndOfWord = false;
        for (int i = 0; i < 26; i ++) {
            newNode -> children[i] = NULL;
        }
        return newNode;
    }

    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    // TC : O(m) where 'm' is the length of the word being inserted.
    // SC : O(m) for creating nodes for the word being inserted.
    void insert(string word) {
        TrieNode* crawler = root;   // Start from the root node
        for (char &ch : word) {
            int idx = ch - 'a';
            // If there is no node for this character, create a new node
            if (!crawler -> children[idx]) {
                crawler -> children[idx] = getTrieNode();
            }
            // Move the crawler to the next node in the Trie (following the character path)
            crawler = crawler -> children[idx];
        }
        // Mark the current node as the end of the word
        crawler -> isEndOfWord = true;
    }
    
    // TC : O(m) where 'm' is the length of the word being searched.
    // SC : O(1), as no additional space is used except for the traversal.
    bool search(string word) {
        TrieNode* crawler = root;   // Start from the root node
        for (char &ch : word) {
            int idx = ch - 'a';
            // If the node for this character does not exist, the word is not present
            if (!crawler -> children[idx]) {
                return false;
            }
            // Move the crawler to the next node in the Trie (following the character path)
            crawler = crawler -> children[idx];
        }
        // After processing all characters, check if this node marks the end of a word then return true
        return crawler -> isEndOfWord;
    }

    // TC : O(p) where 'p' is the length of the prefix being checked.
    // SC : O(1), as no additional space is used except for the traversal.
    bool startsWith(string prefix) {
        TrieNode* crawler = root;
        for (char &ch : prefix) {
            int idx = ch - 'a';
            if (!crawler -> children[idx]) {
                return false;
            }
            crawler = crawler -> children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */