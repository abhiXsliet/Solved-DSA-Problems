// https://leetcode.com/contest/weekly-contest-416/problems/count-substrings-that-can-be-rearranged-to-contain-a-string-i/



#include <bits/stdc++.h>    
using namespace std;

class Solution {
private:
    typedef long long ll;
    
    // TC : O(26)
    // SC : O(1)
    bool isEqual(unordered_map<char, int>& m1, unordered_map<char, int>& m2) {
        for (auto& it : m2) {
            if (!m1.count(it.first) || m1[it.first] < it.second) 
                return false;
        }
        return true;
    }

    // TC : O(26*N + M) Where M = word1.length() & N = word2.length()
    // SC : O(M)
    ll approach_1(string& word1, string& word2) {
        unordered_map<char, int> mpp2;

        for (char& ch : word2) {
            mpp2[ch]++;
        }

        unordered_map<char, int> mpp1;

        int n = word1.length();
        int m = word2.length();
        int i = 0, j = 0;
        ll res = 0;

        while (j < n) {
            mpp1[word1[j]]++;

            while (isEqual(mpp1, mpp2)) {
                res += (n - j);
                mpp1[word1[i]]--;
                if (mpp1[word1[i]] == 0) {
                    mpp1.erase(word1[i]);
                }
                
                i++; 
            }
            j++; 
        }

        return res;
    }

    // TC : O(N + M) Where M = word1.length() & N = word2.length()
    // SC : O(M)
    ll approach_2(string& word1, string& word2) {
        unordered_map<char, int> mpp2;
        for (char& ch : word2) {
            mpp2[ch]++;
        }

        unordered_map<char, int> mpp1;
        int requiredMatches = mpp2.size();
        int currentMatches  = 0;

        int n = word1.length();
        int i = 0, j = 0;
        long long res = 0;

        while (j < n) {
            mpp1[word1[j]] ++;

            // Check if this character now matches the count in mpp2
            if (mpp1[word1[j]] == mpp2[word1[j]]) {
                currentMatches++;
            }

            while (currentMatches == requiredMatches) {
                res += (n - j);  // Valid substrings end at j

                mpp1[word1[i]]--;
                
                // Check if removing this character breaks the match
                if (mpp1[word1[i]] < mpp2[word1[i]]) {
                    currentMatches --;
                }
                i++;
            }
            j++;
        }

        return res;
    }
public:
    long long validSubstringCount(string word1, string word2) {
        // return approach_1(word1, word2);
        
        return approach_2(word1, word2);    // optimized approach_1
    }
};