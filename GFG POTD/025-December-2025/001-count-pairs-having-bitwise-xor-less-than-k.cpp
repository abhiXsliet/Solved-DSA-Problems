// https://www.geeksforgeeks.org/problems/count-pairs-having-bitwise-xor-less-than-k/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  struct Trie {
      Trie* child[2];
      int cnt;
      Trie() { child[0] = child[1] = NULL; cnt = 0; }
  };

  Trie* root;
  
  void insert(int x) {
      Trie* node = root;
      for (int i = 31; i >= 0; i--) {
          int bit = (x >> i) & 1;
          if (!node->child[bit]) node->child[bit] = new Trie();
          node = node->child[bit];
          node->cnt++;
      }
  }

  int countLessXor(int x, int k) {
      Trie* node = root;
      int ans = 0;
      for (int i = 31; i >= 0 && node; i--) {
          int xb = (x >> i) & 1;
          int kb = (k >> i) & 1;
          
          if (kb == 1) {
              // XOR bit yaha 0 ho sakta: choose xb branch
              if (node->child[xb])
                  ans += node->child[xb]->cnt;
              node = node->child[xb ^ 1]; // XOR = 1 continue
          } else {
              node = node->child[xb]; // XOR must be 0
          }
      }
      return ans;
  }

public:
    int cntPairs(vector<int>& arr, int k) {
        root = new Trie();
        int ans = 0;

        for (int x : arr) {
            ans += countLessXor(x, k);
            insert(x);
        }
        return ans;
    }
};
