// https://www.geeksforgeeks.org/problems/trie-insert-and-search0651/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function template for C++
class Trie {
    struct TrieNode {
        bool isEndOfWord;
        TrieNode *children[26];
    };
    
    TrieNode* getNode(char &ch) {
        TrieNode* newNode = new TrieNode();
        newNode -> isEndOfWord = false;
        for (int i = 0; i < 26; i ++) {
            newNode -> children[i] = NULL;
        }
        return newNode;
    }
  public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }

    void insert(string &word) {
        TrieNode *crawler = root;
        for (char &ch : word) {
            int idx = ch - 'a';
            if (!crawler -> children[idx]) {
                crawler -> children[idx] = getNode(ch);
            }
            crawler = crawler -> children[idx];
        }
        crawler -> isEndOfWord = true;
    }

    bool search(string &word) {
        TrieNode *crawler = root;
        for (char &ch : word) {
            int idx = ch - 'a';
            if (!crawler -> children[idx])
                return false;
            crawler = crawler -> children[idx];
        }
        return crawler -> isEndOfWord;
    }

    bool isPrefix(string &word) {
        TrieNode* crawler = root;
        for (char &ch : word) {
            int idx = ch - 'a';
            if (!crawler -> children[idx])
                return false;
            crawler = crawler -> children[idx];
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int q;
        cin >> q;
        cin.ignore();
        vector<bool> ans;
        Trie ob;
        for (int i = 0; i < q; i++) {
            int x;
            cin >> x;
            string s;
            cin >> s;
            cin.ignore();
            if (x == 1) {
                ob.insert(s);
            } else if (x == 2) {
                ans.push_back(ob.search(s));
            } else if (x == 3) {
                ans.push_back(ob.isPrefix(s));
            }
        }
        cout << boolalpha;
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends