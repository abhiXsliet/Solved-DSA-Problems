// https://www.geeksforgeeks.org/problems/palindrome-pairs/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    
    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }

public:
    // TC : O(N * K^2)
    // SC : O(N * K)
    bool palindromePair(vector<string>& arr) {

        unordered_map<string, int> mp;

        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]] = i;
        }

        for (int i = 0; i < arr.size(); i++) {

            string s = arr[i];
            int n = s.length();

            for (int cut = 0; cut <= n; cut++) {

                string left = s.substr(0, cut);
                string right = s.substr(cut);

                // LEFT palindrome
                if (isPalindrome(left, 0, left.size() - 1)) {

                    string revRight = right;
                    reverse(revRight.begin(), revRight.end());

                    if (mp.count(revRight) && mp[revRight] != i) {
                        return true;
                    }
                }

                // RIGHT palindrome
                if (cut != n &&
                    isPalindrome(right, 0, right.size() - 1)) {

                    string revLeft = left;
                    reverse(revLeft.begin(), revLeft.end());

                    if (mp.count(revLeft) && mp[revLeft] != i) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};