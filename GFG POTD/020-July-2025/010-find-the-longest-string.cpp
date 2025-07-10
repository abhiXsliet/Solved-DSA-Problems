// https://www.geeksforgeeks.org/problems/find-the-longest-string--170645/1




#include <bits/stdc++.h>
using namespace std;

class Trie {
        struct TrieNode {
            bool isTerminal;
            TrieNode* children[26];
        };
        
        TrieNode* getNode(char &ch) {
            TrieNode* newNode = new TrieNode();
            newNode -> isTerminal = false;
            for (int i = 0; i < 26; i ++) {
                newNode -> children[i] = NULL;
            }
            return newNode;
        }
    public:
        TrieNode* root;
        Trie() {
            char ch = '$';
            root = getNode(ch);
        }
        
        void insertInTrie(string &s) {
            TrieNode* crawler = root;
            for (char &ch : s) {
                int idx = (ch - 'a');
                if (!crawler -> children[idx]) {
                    crawler -> children[idx] = getNode(ch);
                }
                crawler = crawler -> children[idx];
            }
            crawler -> isTerminal = true;
        }
        
        bool searchInTrie(string &s) {
            TrieNode* crawler = root;
            for (char &ch : s) {
                int idx = (ch - 'a');
                if (!crawler -> children[idx] || !crawler -> children[idx] -> isTerminal)
                    return false;
                crawler = crawler -> children[idx];
            }
            return crawler -> isTerminal;
        }
};

class Solution {
  private:
    // TC : O(N * M^2)
    // SC : O(N * M)
    // 👉 If M is large (like 1000+), then O(n.M²) becomes the bottleneck.
    string approach_1(vector<string> &words) {
        int n = words.size();
        
        unordered_set<string> st;
        for (string &s : words) {
            st.insert(s);
        }
        
        string result;
        for (int i = 0; i < n; i ++) {
            string s = words[i];
            string pref;
            bool present = true;
            for (char &ch : s) {
                pref += ch;
                if (!st.count(pref)) {
                    present = false;
                    break;
                }
            }
            if (present && (result.length() < s.length() || 
                            (result.length() == s.length() && result > s))) {
                result = s;
            }
        }
        return result;
    }
    
    // TC : O(N * log(N) * M)
    // SC : O(N * M)
    string approach_2(vector<string> &words) {
        sort(begin(words), end(words));
        unordered_map<string, bool> mpp;
        
        for (string &s : words) {
            if (s.length() == 1) {
                mpp[s] = true;
            } else {
                string temp = s;
                temp.pop_back();
                
                if (mpp[temp]) 
                    mpp[s] = true;
                else 
                    mpp[s] = false;
            }
        }
        
        string result;
        for (string &s : words) {
            if (mpp[s] && s.length() > result.length())
                result = s;
        }
        return result;
    }
    
    // TC : O(N * M)
    // SC : O(N * M)
    string approach_3(vector<string> &words) {
        Trie t; // instantiate class
       
        for (string &s : words) {
            t.insertInTrie(s);
        }
        
        string result;
        for (string &s : words) {
            if (t.searchInTrie(s)) {
                if (s.length() > result.length() || (s.length() == result.length() && s < result)) {
                    result = s;
                }
            } 
        }
        return result;
    }
  public:
    string longestString(vector<string> &words) {
        // return approach_1(words);
        // return approach_2(words);    // Better 
        return approach_3(words);    // Trie
    }
};