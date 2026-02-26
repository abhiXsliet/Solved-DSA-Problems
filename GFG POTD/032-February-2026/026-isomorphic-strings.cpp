// https://www.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    // TC : O(N)
    // SC : O(1)
    bool solve_approach_1(string& s, string& t) {
        if (s.length() != t.length()) return false;
        
        unordered_map<char, char> mpp(26);
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
                else {
                    return false;
                }
            }
        }
        return true;
    }
    
    // TC : O(N)
    // SC : O(1)
    bool solve_approach_2(string& s, string& t) {
        if (s.length() != t.length()) return false;
        unordered_map<char, char> mpp1(26), mpp2(26);
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
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2) {
        return solve_approach_1(str1, str2);
        
        // return solve_approach_2(str1, str2);
    }
};
