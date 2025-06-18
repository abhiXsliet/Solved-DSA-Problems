// https://www.geeksforgeeks.org/problems/find-all-possible-palindromic-partitions-of-a-string/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(2^n) where n is the length of the string
    // SC : O(n) for the recursion stack and O(n) for the result storage
    vector<vector<string>> palinParts(string &s) {
        vector<vector<string>> result;
        vector<string> current;
        backtrack(0, s, current, result);
        return result;
    }

  private:
    void backtrack(int start, string &s, vector<string> &current, vector<vector<string>> &result) {
        if (start == s.length()) {
            result.push_back(current);
            return;
        }

        for (int end = start; end < s.length(); ++end) {
            if (isPalindrome(s, start, end)) {
                current.push_back(s.substr(start, end - start + 1));
                backtrack(end + 1, s, current, result);
                current.pop_back(); // backtrack
            }
        }
    }

    bool isPalindrome(string &s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};