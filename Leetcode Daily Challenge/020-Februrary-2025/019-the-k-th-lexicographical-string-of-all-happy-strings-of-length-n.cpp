// https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
/* 
    // TC : O(3 * 2^(n - 1) * n)
    - The factor 3 * 2^(n - 1) represents the branching possibilities at each step:
    - 3 possibilities for the first place.
    - 2 possibilities for the remaining places.
    - The extra 'n' accounts for the time needed to copy the 'curr' into the 'res'
    // SC: O(N) Due to the recursive call stack space.
    */
    void solve(string s, string curr, string &res, int n, int &k) {
        if (n == 0) {
            k --;
            if (k == 0) res = curr;
            return;
        }

        for (int i = 0; i < s.length(); i ++) {
            if (curr.empty() || (!curr.empty() && curr.back() != s[i])) { 
                curr.push_back(s[i]);
                solve(s, curr, res, n - 1, k);
                curr.pop_back();
            } 
        }
    }

    // TC : O(n * 2^n) 
    // SC : O(1)
    string approach_1(int n, int k) {
        string result;
        solve("abc", "", result, n, k);
        return result;
    }
public:
    string getHappyString(int n, int k) {
        return approach_1(n, k);
    }
};