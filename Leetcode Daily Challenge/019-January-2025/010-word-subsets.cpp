// https://leetcode.com/problems/word-subsets/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(M * N * L1 * L2) Where M  = words1.size(), n = words2.size()
    // SC : O(L1)              Where L1, L2 = Avg. words1's & words2's word length 
    vector<string> approach_1(vector<string>& words1, vector<string>& words2) {
        int m = words1.size(), n = words2.size();
        vector<string> result;
        for (string& a : words1) {  // a will be universal if every b occurs in a
            bool isUniversal = true;
            string str = a;
            for (int j = 0; j < n; j ++) {
                for (int k = 0; k < words2[j].length(); k ++) {
                    int idx = str.find(words2[j][k]);   // return -1 (i.e., string::npos) if not found
                    if (idx == -1) {
                        isUniversal = false;
                        break;
                    } else {
                        if (idx >= 0 && idx < str.length())
                            str.erase(idx,1);
                    }
                }
                str = a;
            }
            if (isUniversal) {
                result.push_back(a);
            }
        }
        return result;
    }

    // TC : O(M * N)
    // SC : O(M + N)
    vector<string> approach_2(vector<string>& words1, vector<string>& words2) {
        int m = words1.size(), n = words2.size();
        vector<vector<int>> freq1(m, vector<int>(26, 0));
        vector<vector<int>> freq2(n, vector<int>(26, 0));

        for (int i = 0; i < m; i ++) {
            for (char& ch : words1[i]) {
                freq1[i][ch - 'a'] ++;
            }
        }
        for (int i = 0; i < n; i ++) {
            for (char& ch : words2[i]) {
                freq2[i][ch - 'a'] ++;
            }
        }

        vector<string> result;
        for (int i = 0; i < m; i ++) {
            bool isUniversal = true;
            for (int j = 0; j < n; j ++) {
                for (int c = 0; c < 26; c ++) {
                    if (freq2[j][c] > freq1[i][c]) {
                        isUniversal = false;
                        break;
                    }
                }
            }
            if (isUniversal) 
                result.push_back(words1[i]);
        }
        return result;
    }

    // TC : O(N * L2 + M * L1) ~= O(M + N)
    // SC : O(1)
    // Optimization : Precompute max character frequencies of words2 for efficient comparison with words1
    vector<string> approach_3(vector<string>& words1, vector<string>& words2) {
        int m = words1.size(), n = words2.size();
        // stores the max-freq of each char traversing each word of words2
        vector<int> maxFreqChar(26, 0); 
        
        for (string &b : words2) {
            vector<int> freq(26, 0);
            for (char& ch : b) {
                int idx = ch - 'a';
                freq[idx] ++;
                maxFreqChar[idx] = max(maxFreqChar[idx], freq[idx]);
            }
        }

        vector<string> result;
        for (string &a : words1) {
            vector<int> freq(26, 0);
            for (char &ch : a) {
                freq[ch - 'a'] ++;
            }
            bool isUniversal = true;
            for (int c = 0; c < 26; c ++) {
                if (maxFreqChar[c] > freq[c]) { // Not a subset if any char's max-freq in words2 > its freq in word1
                    isUniversal = false;
                    break;
                }
            }
            if (isUniversal) 
                result.push_back(a);
        }
        return result;
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        // return approach_1(words1, words2);  // BRUTE

        // return approach_2(words1, words2);   // Better

        return approach_3(words1, words2);   // Optimal
    }
};