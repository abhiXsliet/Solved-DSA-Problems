// https://www.geeksforgeeks.org/problems/exactly-one-swap--170637/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    // TC : O(N^2)
    // SC : O(N)
    int brute(string &s) {
        int n = s.length();
        unordered_set<string> st;
        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                string newS = s;
                swap(newS[i], newS[j]);
                st.insert(newS);
            }
        }
        return st.size();
    }
    
    // TC : O(N)
    // SC : O(1)
    int optimal(string &s) {
        int n = s.length();
        
        vector<int> freq(26, 0);
        for (char &ch : s) {
            freq[ch - 'a'] ++;
        }
        
        int totalSwaps = n * (n - 1) / 2;
        int noEffectSwaps = 0;
        
        for (int &f : freq) {
            noEffectSwaps += f * (f - 1) / 2;
        }
        
        int extraOne = (noEffectSwaps == 0) ? 0 : 1;
        return (totalSwaps - noEffectSwaps) + extraOne;
    }
  public:
    int countStrings(string &s) {
        // return brute(s);
        return optimal(s);
    }
};