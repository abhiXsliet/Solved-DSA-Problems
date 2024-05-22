// https://leetcode.com/problems/palindrome-partitioning/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isPalindrome(string path, int start, int end) {
        while (start <= end) {
            if (path[start++] != path[end--]) 
                return false;
        }
        return true;
    }

    // TC : O(2^N * N)
    // SC : O(N)
    void solve_rec(string s, vector<vector<string>>& result, vector<string>& path, int idx) {
        if (idx == s.size()) {
            result.push_back(path);
            return ;
        }

        for (int i = idx; i < s.length(); i++) {
            if (isPalindrome(s, idx, i)) {
                path.push_back(s.substr(idx, i - idx + 1));
                solve_rec(s, result, path, i+1);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        
       solve_rec(s, result, path, 0);

       return result;
    }
};