// https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(1) -> map end up storing all 26 chars.
    bool solve_approach_1(vector<string>& words, int n) {
        unordered_map<char, int> mpp;

        for (auto& str : words) {
            for (char ch : str) {
                mpp[ch]++;
            }
        }

        for (auto& it : mpp) {
            if (it.second % n != 0) 
                return 0;
        }
        
        return true;
    }

    // TC : O(N)
    // SC : O(1)
    bool solve_approach_2(vector<string>& words, int n) {
        vector<int> freq(26, 0);

        for (auto& str : words) {
            for (char& ch : str) {
                freq[ch - 'a']++;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (freq[i] % n != 0) 
                return 0;
        }

        return 1;
    }

    // TC : O(N)
    // SC : O(1)
    bool solve_approach_3(vector<string>& words, int n) {
        int freq[26] = {0};

        for (auto& str : words) {
            for (char& ch : str) {
                freq[ch - 'a']++;
            }
        }

        auto lambda = [&](int freq) {
            return freq % n == 0;
        };

        return all_of(begin(freq), end(freq), lambda);

        return 1;
    }
public:
    bool makeEqual(vector<string>& words) {
        // return solve_approach_1(words, words.size());

        // return solve_approach_2(words, words.size());

        return solve_approach_3(words, words.size());
    }
};