// https://leetcode.com/problems/count-beautiful-substrings-ii/




#include <bits/stdc++.h>
using namespace std; 

class Solution {
private:
    typedef long long ll;
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

public:
    // T.C : O(n*k) where, k = avg size of mp[a-b]
    // S.C : O(n) in worst case when a-b is always a new value 
    long long beautifulSubstrings(string s, int k) {
        int n = s.length();

        ll vowel     = 0;
        ll consonant = 0;
        ll result    = 0;

        // key = diff(vowel - consonant), value = {vowel, freq(diff)}
        unordered_map<int, unordered_map<int, int>> mpp; 

        mpp[vowel - consonant][0] = 1;

        for (char& ch : s) {
            if (isVowel(ch)) {
                vowel++;
            }
            else consonant++;

            ll pSum = vowel - consonant;
            
            for (auto& [pastVowelCount, freq] : mpp[pSum]) {
                // vowel count of the current substring = vowel - pastVowelCount;

                if ((vowel - pastVowelCount%k) * (vowel - pastVowelCount%k) % k == 0) {

                    result += freq;
                }
            }

            mpp[pSum][vowel%k]++;
        }

        return result;
    }
};
