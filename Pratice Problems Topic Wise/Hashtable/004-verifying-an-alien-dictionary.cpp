// https://leetcode.com/problems/verifying-an-alien-dictionary/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N*M) Where N = Size of array of words 
    // SC : O(M)   Where M = Max len of indiviual strings in words array
    bool isAlienSorted(vector<string>& words, string order) {
        int n = words.size();
        unordered_map<char, int> mpp;
        for (int i = 0; i < order.length(); i++) {
            mpp[order[i]] = i;
        }

        for (int i = 0; i < n - 1; i++) {
            string first  = words[i];
            string second = words[i + 1];

            int p1 = 0, p2 = 0;
            while(p1 < first.length() && p2 < second.length()) {
                if (mpp[first[p1]] == mpp[second[p2]]) {
                    p1 ++, p2 ++;
                }
                else if (mpp[first[p1]] > mpp[second[p2]]) {
                    return false;
                }
                else break;
            }
            // second string is of shorter len
            if (p1 != first.length() && p2 == second.length()) {   
                return false;
            }
        }
        return true;
    }
};