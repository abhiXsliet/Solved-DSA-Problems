// https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-i/



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
        int low = 0, high = m-1, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            cout << "mid: " << mid << endl;
            if (consonantsIdx[mid] > i) {
                ans = consonantsIdx[mid];
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << "ans : " << ans << endl;
        return ans;
    }
public:
    // TC : O(N * log(M)) Where N = String Length and M = No. of Consonants
    // SC : O(M)
    ll countOfSubstrings(string word, int k) {
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
};

// optimized approach in part-II