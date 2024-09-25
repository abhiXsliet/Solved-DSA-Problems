// https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/




#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[10]; // 0, 1, ..., 9
};

class Solution {
private:
    // TC : O(M + N) Where N = arr1 size & M = arr2 size
    // SC : O(N)
    int approach_1(vector<int>& arr1, vector<int>& arr2) {
        int m = arr1.size();
        int n = arr2.size();

        unordered_set<int> st;
        for (int& val : arr2) {
            string v = to_string(val);
            string num = "";
            for (int i = 0; i < v.length(); i ++) {
                num += v[i];
                st.insert(stoi(num));
            }
        }

        int lcp = 0;
        for (int& val : arr1) {
            string v = to_string(val);
            string num = "";
            for (int i = 0; i < v.length(); i++) {
                num += v[i];
                if (st.count(stoi(num))) {
                    lcp = max(lcp, (i + 1));
                }
            }
        }
        return lcp;
    }

    // TC : O(M + N) Where N = arr1 size & M = arr2 size
    // SC : O(M)
    int approach_2(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;
        for (int& val : arr2) {
            while(val && !st.count(val)) {  // !st.count() : little optimization while inserting
                cout << val << endl;
                st.insert(val);
                val /= 10;
            }
        }

        int lcp = 0;
        for (int& val : arr1) {
            int prefix = val;
            while(prefix) {
                if (st.count(prefix)) {
                    lcp = max(lcp, (int)(log10(prefix) + 1));
                }
                prefix /= 10;
            }
        }
        return lcp;
    }

    TrieNode* getTrieNode() {
        TrieNode* node = new TrieNode();
        for (int i = 0; i < 10; i ++) {
            node -> children[i] = NULL;
        }
        return node;
    }

    void insertInTrie(TrieNode* root, int num) {
        TrieNode* crawl = root;
        string numStr = to_string(num);

        for (char& ch : numStr) {
            int idx = ch - '0';
            if (!crawl -> children[idx]) {
                crawl  -> children[idx] = getTrieNode();
            }
            crawl = crawl -> children[idx];
        }
    }

    int searchInTrie(TrieNode* root, int num) {
        int len = 0;
        string numStr = to_string(num);
        TrieNode* crawl = root;

        for (char& ch : numStr) {
            int idx = ch - '0';
            if (crawl -> children[idx]) {
                len ++;
                crawl = crawl -> children[idx];
            } else {
                break;
            }
        }

        return len;
    }

    // TC : O(M*D + N*D) Where M = size of arr1  
    // SC : O(N*D)       Where N = Size of arr2 and D = No. of digits
    int approach_3(vector<int>& arr1, vector<int>& arr2) {
        TrieNode* root = getTrieNode();

        for (int& num : arr2) {     // O(M * D)
            insertInTrie(root, num);
        }

        int lcp = 0;
        for (int& num : arr1) { // O(N * D)
            lcp = max(lcp, searchInTrie(root, num));
        }
        return lcp;
    }
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        // return approach_1(arr1, arr2);       // STRING

        // return approach_2(arr1, arr2);       // Without converting into STRING

        return approach_3(arr1, arr2);       // Using Trie
    }
};