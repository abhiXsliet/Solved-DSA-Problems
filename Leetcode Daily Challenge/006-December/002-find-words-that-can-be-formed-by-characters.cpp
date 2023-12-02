// https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(N*M) where N = words.size(), M = max(words[i].length())
    // SC = O(chars.length()) ~ O(26) -> constant
    int solve_approach_1(vector<string>& words, string chars) {
        unordered_map<char, int> mpp;
        for (char ch : chars) 
            mpp[ch]++;
        
        int n = words.size();
        int len = 0;

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            unordered_map<char, int> temp_mpp = mpp;
            for (int j = 0; j < words[i].length(); j++) {
                char ch = words[i][j];
                if (temp_mpp[ch] > 0) {
                    cnt ++;
                    temp_mpp[ch]--;
                }
                else {
                    cnt = 0;
                    break;
                }
            }
            len += cnt;
        }

        return len;
    }

    // TC = O(N*M) where N = words.size(), M = max(words[i].length())
    // SC = O(26) ~ constant
    int solve_approach_2(vector<string>& words, string chars) {
        // step - 1 : store the frequency of each char to the map
        vector<int> freq(26, 0);
        for (char &ch : chars) {
            freq[ch - 'a']++;
        } 

        int result = 0;
        for (string &word : words) {
            // check if the string is good 
            vector<int> new_freq(26, 0);
            for (char &ch : word) {
                new_freq[ch - 'a']++;
            }

            bool isPossible = true;
            for (int i = 0; i < 26; i++) {
                if (new_freq[i] > freq[i]) {
                    isPossible = false;
                    break;
                }
            }

            if (isPossible) {
                result += word.length();
            }
        }
        return result;
    }
public:
    int countCharacters(vector<string>& words, string chars) {
        // return solve_approach_1(words, chars);

        return solve_approach_2(words, chars);
    }
};