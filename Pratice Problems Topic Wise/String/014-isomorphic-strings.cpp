// https://leetcode.com/problems/isomorphic-strings/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(256)   ~= O(1)
    bool solve_approach_1(string& s, string& t) {
        unordered_map<char, char> mpp(256);
        vector<int> visited(256, -1);
        for (int i = 0; i < s.length(); i++) {
            if (mpp.find(s[i]) != mpp.end()) {
                if (mpp[s[i]] != t[i]) 
                    return false;
            }
            else {
                if (visited[t[i]] == -1) {
                    mpp[s[i]]     = t[i];
                    visited[t[i]] = 1;
                }
                else return false;
            }
        }
        return true;
    }

    // TC : O(N)
    // SC : O(1)
    bool solve_approach_2(string& s, string& t) {
        unordered_map<char, char> mpp1(256), mpp2(256);
        for (int i = 0; i < s.length(); i++) {
            if (mpp1.count(s[i]) && mpp1[s[i]] != t[i]) 
                return false;
            if (mpp2.count(t[i]) && mpp2[t[i]] != s[i]) 
                return false;

            mpp1[s[i]] = t[i];
            mpp2[t[i]] = s[i];
        }
        return true;
    }
public:
    bool isIsomorphic(string s, string t) {
        // return solve_approach_1(s, t);

        return solve_approach_2(s, t);
    }
};