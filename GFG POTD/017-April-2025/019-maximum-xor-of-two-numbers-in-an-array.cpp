// https://www.geeksforgeeks.org/problems/maximum-xor-of-two-numbers-in-an-array/1




//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
// User function Template for C++

class Trie {
  public:
    struct TrieNode {
        TrieNode *left, *right;
    };

    TrieNode* root;
    Trie() {
        root = new TrieNode();
        root ->  left = NULL;
        root -> right = NULL;
    }
    
    void insertTrie(string &s) {
        TrieNode* crawl = root;
        for (char &ch : s) {
            if (ch == '0') {
                if (!crawl -> left) {
                    crawl -> left = new TrieNode();
                }
                crawl = crawl -> left;
            } else {
                if (!crawl -> right) {
                    crawl -> right = new TrieNode();   
                }
                crawl = crawl -> right;
            }
        }
    }
    
    string searchTrie(string &s) {
        TrieNode* crawl = root;
        string ans;
        for (char &ch : s) {
            if (ch == '0') {
                if (!crawl -> left) {
                    ans += '1';
                    crawl = crawl -> right;
                    continue;
                }
                ans += '0';
                crawl = crawl -> left;
            } else {
                if (!crawl -> right) {
                    ans += '0';
                    crawl = crawl -> left;
                    continue;
                }
                ans += '1';
                crawl = crawl -> right;
            }
        }
        return ans;
    }
};

class Solution {
  private:
    // TC : O(N)
    // SC : O(N)
    int approach_1(vector<int> &arr) {
        int n = arr.size();
        int max_xor = 0;
        int mask = 0;
        
        for (int i = 31; i >= 0; i --) {
            
            mask |= (1 << i);
            
            unordered_set<int> prefix;
            for (int &num : arr) {
                prefix.insert(num & mask);
            }
            
            int candidate = max_xor | (1 << i);     // setting current bit
            for (auto &p : prefix) {
                if (prefix.count(candidate ^ p)) {
                    max_xor = candidate;
                    break;
                }   
            }
        }
        return max_xor;
    }
    
    // TC : O(N)
    // SC : O(N)
    int approach_2(vector<int> &arr) {
        int n = arr.size();
        
        Trie T;
        
        int maxi = 0;
        
        // insert all no.s in 32-bits in trie 
        for (int &num : arr) {
            string binary;
            for (int i = 31; i >= 0; i --) {
                binary += ((1 << i) & num) ? '1' : '0';
            }
            maxi = max(maxi, num);
            T.insertTrie(binary);
        }
        
        int bitCnt = log2(maxi) + 1;
        int max_xor = 0;
        for (int &num : arr) {
            string negation;    // xoring num with ~num will give maximum answer
            string original;    // store all 32-bits of num
            
            for (int i = 31; i >= 0; i --) {
                if (i < bitCnt) negation += ((1 << i) & (~num)) ? '1' : '0';
                else negation += ((1 << i) & (~num)) ? '0' : '1';
                
                original += ((1 << i) & (num)) ? '1' : '0';
            }
            
            string optimal = T.searchTrie(negation);

            int value = 0;
            for (int i = 0; i < 32; i++) {
                value <<= 1;  // shift left to make room for the next bit
                
                int bit1 = original[i] - '0';  // convert '0' or '1' to 0 or 1
                int bit2 = optimal[i] - '0';
                value |= (bit1 ^ bit2);  // XOR the bits and store
            }
            max_xor = max(max_xor, value);
        }
        return max_xor;
    }
  public:
    int maxXor(vector<int> &arr) {
        // return approach_1(arr);      // Bit Manipulation
        return approach_2(arr);      // Trie
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.maxXor(arr) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends