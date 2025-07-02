// https://www.geeksforgeeks.org/problems/lexicographically-largest-string-after-deleting-k-characters/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N)
    // SC : O(1)
    string maxSubseq(string& s, int k) {
        int n = s.length();
        string result;
        for (int i = 0; i < n; i ++) {
            if (result.empty() || result.back() > s[i]) {
                result += s[i];
            } else {
                while (k > 0 && !result.empty() && result.back() < s[i]) {
                    result.pop_back();
                    k -= 1;
                } 
                result += s[i];
            }
        }
        while (k && !result.empty()) {
            result.pop_back();
            k --;
        }
        return result;
    }
};
