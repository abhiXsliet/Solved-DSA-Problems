// https://www.geeksforgeeks.org/problems/generate-all-binary-strings/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    // TC : O(N * 2^N)
    // SC : O(N) Recursive Depth
    void solve(int n, string curr, vector<string> &res) {
        if (curr.length() == n) {
            res.push_back(curr);
            return;
        }
        
        solve(n, curr + '0', res);
        solve(n, curr + '1', res);
    }
  public:
    // TC : O(N * 2^N)
    // SC : O(N)
    vector<string> binstr(int n) {
        vector<string> result;
        string curr;
        solve(n, curr, result);
        return result;
    }
};