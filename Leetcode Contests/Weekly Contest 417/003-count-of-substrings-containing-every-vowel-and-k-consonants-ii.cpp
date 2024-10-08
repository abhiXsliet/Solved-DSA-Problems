// https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;

    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    int getNextConsonant(vector<int>& consonantsIdx, int i) {
        int m = consonantsIdx.size();
        if (m == 0) return -1;
        int low = 0, high = m - 1, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (consonantsIdx[mid] > i) {
                ans  = consonantsIdx[mid];
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    // TC : O(N * log(M)) Where N = Length of string & M = No. of consonants
    // SC : O(1)
    ll approach_1(string word, int k) {
        int n = word.length();

        vector<int> consonantsIdx;
        for (int i = 0; i < n; i ++) {
            if (!isVowel(word[i])) {
                consonantsIdx.push_back(i);
            }
        }

        unordered_map<char, int> mpp;   // to store vowels
        int i = 0, j = 0, consonants = 0, cntOfSubstr = 0;

        while (j < n) {
            if (isVowel(word[j])) {
                mpp[word[j]] ++;
            } else {
                consonants += 1;
            }

            while (consonants > k) {
                if (isVowel(word[i])) {
                    mpp[word[i]] --;
                    if (mpp[word[i]] == 0) {
                        mpp.erase(word[i]);
                    }
                } else {
                    consonants -= 1;
                }
                i ++;
            }

            while (consonants == k && mpp.size() == 5) {
                int idx = getNextConsonant(consonantsIdx, j);
                if (idx != -1) {
                    cntOfSubstr += (idx - j);
                } else {
                    cntOfSubstr += (n - j);
                }

                if (isVowel(word[i])) {
                    mpp[word[i]] --;
                    if (mpp[word[i]] == 0) {
                        mpp.erase(word[i]);
                    }
                } else {
                    consonants -= 1;
                }

                i ++;
            }

            j ++;
        }

        return cntOfSubstr;
    }

    // TC : O(N)
    // SC : O(1)
    // this fn calculates the cnt of substring of at least each vowels and at least k consonants
    ll approach_2(string word, int k) {
        int n = word.length();
        int i = 0, j = 0, consonant = 0;
        ll cntOfSubstr = 0;
        unordered_map<int, int> mpp;

        while (j < n) {
            if (isVowel(word[j])) {
                mpp[word[j]] ++;
            } else {
                consonant ++;
            }

            while (mpp.size() == 5 && consonant >= k) {
                cntOfSubstr += (n - j);
                if (isVowel(word[i])) {
                    mpp[word[i]] --;
                    if (mpp[word[i]] == 0) {
                        mpp.erase(word[i]);
                    }
                } else {
                    consonant --;
                }
                i ++;
            }

            j ++;
        }

        return cntOfSubstr;
    }
public:
    ll countOfSubstrings(string word, int k) {
        // return approach_1(word, k);

        return  approach_2(word, k) - approach_2(word, k + 1);
    }
};