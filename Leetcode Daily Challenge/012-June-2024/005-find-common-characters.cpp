// https://leetcode.com/problems/find-common-characters/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N*M*K) Where N = Size Of Words Array & M = Max Length Of Strings of Words & K = Length Of 0-index string (words[0])
    // SC : O(1)
    vector<string> approach_1(vector<string>& words) {
        int n = words.size();
        vector<string> result;
        for (char& ch : words[0]) {
            bool missing = 0;
            for (int i = 1; i < n; i++) {
                auto pos = words[i].find(ch);
                if (pos == string::npos) {
                    missing = 1;
                    break;
                } else {
                    words[i].erase(pos, 1);
                }
            }
            if (!missing) {
                result.push_back(string(1, ch));   
            }
        }
        return result;
    }

    // TC : O(N*M) 
    // SC : O(1)
    vector<string> approach_2(vector<string>& words) {
        int n = words.size();
        vector<string> result;
       
        vector<int> freq(26, 0);    // store the resultant freq of the chars
        for (char& ch : words[0]) {
            freq[ch - 'a'] ++;
        }

        for (int i = 1; i < n; i ++) {
            vector<int> count(26, 0);
            for (char& ch : words[i]) {
                count[ch - 'a'] ++;
            }

            for (int i = 0; i < 26; i ++) {
                freq[i] = min(freq[i], count[i]);
            }
        }

        for (int i = 0; i < 26; i ++) {
            while (freq[i] > 0) {
                result.push_back(string(1, 'a' + i));
                freq[i] --;
            }
        }

        return result;
    }
public:
    vector<string> commonChars(vector<string>& words) {
        // return approach_1(words);

        return approach_2(words);
    }
};