// https://www.geeksforgeeks.org/problems/longest-string-chain/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    int getMaxLscEndAtWord_i(unordered_set<string> &st, string &word, unordered_map<string, int> &dp) {
        int result = 1;
        if (dp[word]) return dp[word];
        for (int i = 0; i < word.length(); i ++) {
            string pred = word.substr(0, i) + word.substr(i + 1);
            if (st.count(pred)) {
                result = max(result, 1 + getMaxLscEndAtWord_i(st, pred, dp));
            }
        }
        dp[word] = result;
        return result;
    }
    
    // TC : O(M)    word.length()
    // SC : O(1)
    // Function to check if b is a predecessor of a
    bool isPredecessor(const string &a, const string &b) {
        if (a.length() != b.length() + 1)
            return false;
        int i = 0, j = 0;
        while (i < a.length() && j < b.length()) {
            if (a[i] == b[j]) {
                i ++, j ++;
            } else {
                i ++;
            }
        }
        return (j == b.length());
    }
    
    // TC : O(N * M)
    // SC : O(N)    Recursive Stack Space
    // This fn. finds the length of the longest-chain that ends with word, recursively
    int getLSC(vector<string>& words, string &word) {
        int lsc = 0;
        for (string &w : words) {
            if (isPredecessor(w, word)) {
                lsc = max(lsc, 1 + getLSC(words, w));
            }
        }
        return lsc;
    }
    
    // TC : O(N^2 * M)
    // SC : O(1)
    int approach_1(vector<string>& words) {
        int maxLSC = 0;    // longestStringChain
        for (string &word : words) {    // ending at word what will be longest string chain?
            maxLSC = max(maxLSC, 1 + getLSC(words, word));
        }
        return maxLSC;
    }
    
    // TC : O(Nlog(N) + N^2*M)
    // SC : O(N)
    int approach_2(vector<string>& words) {
        int n = words.size();
        auto cmp = [&](const string &a, const string &b) {
            return a.length() < b.length();  
        };
        sort(begin(words), end(words), cmp);
        
        vector<int> dp(n, 1);
        
        int maxLSC = 1;    // longestStringChain
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < i; j ++) {
                if (isPredecessor(words[i], words[j])) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            maxLSC = max(maxLSC, dp[i]);
        }
        return maxLSC;
    }

    // TC : O(Nlog(N) + N*M^2)
    // SC : O(N)
    int approach_3(vector<string>& words) {
        int n = words.size();

        // Create an unordered set to check the availability
        unordered_set<string> st(begin(words), end(words));
        unordered_map<string, int> dp;

        int maxLSC = 1;    // longestStringChain
        for (int i = 0; i < n; i ++) {
            maxLSC = max(maxLSC, getMaxLscEndAtWord_i(st, words[i], dp));
        }
        return maxLSC;
    }
  public:
    int longestStringChain(vector<string>& words) {
        // return approach_1(words);   // BRUTE : for each word maximize the LSC
    
        // return approach_2(words);   // LIS Variation : O(N^2)
        
        return approach_3(words);   // LIS + set
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> words;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            words.push_back(number);
        }
        Solution obj;
        cout << obj.longestStringChain(words) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends