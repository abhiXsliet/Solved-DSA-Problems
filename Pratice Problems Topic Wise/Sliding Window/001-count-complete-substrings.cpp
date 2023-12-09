// https://leetcode.com/problems/count-complete-substrings/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(26*N) ~ O(N)
    // SC = O(26)
    int countSubstrings(int start, int end, int k, string& word) {
        int result = 0;

        // Counting substring based on the number of unique chars. => Unique_char * k 
        // 1*k = 1*2 = 2(window Len);   2*k = 2*2 = 4;   3*k = 3*2 = 6
        for (int unique_char = 1; unique_char <= 26 && unique_char*k <= end-start+1; unique_char++) {
            
            // Store the freq of each unique_char
            vector<int> freq(26, 0);
            // No. of unique_char equals to k
            int goodChar = 0;

            // Now Starting Sliding Window
            int i = start;
            int windowLen = unique_char*k;

            for (int j = start; j <= end; j++) {
                char ch = word[j];

                freq[ch - 'a']++;
                
                if (freq[ch - 'a'] == k) {  // we found a goodChar
                    goodChar += 1;
                }
                else if (freq[ch - 'a'] == k + 1) {
                    goodChar -= 1;
                }

                // Time to slide the window
                if (j - i + 1 > windowLen) {
                    // on sliding of window freq of char will increase
                    if (freq[word[i] - 'a'] == k) {
                        goodChar -= 1;
                    }
                    // on sliding of window freq of char will decrease
                    else if (freq[word[i] - 'a'] == k + 1) {
                        goodChar += 1;
                    }

                    freq[word[i] - 'a'] --;
                    i ++;
                }

                // if we found the required good char for the unique char
                if (goodChar == unique_char) {
                    result += 1;
                }
            }
        }

        return result;
    }
public:
    // TC = O(N * 26*N) ~ O(N^2)
    // SC = O(26)
    int countCompleteSubstrings(string word, int k) {
        int n = word.length();

        int result  = 0;
        int lastIdx = 0;

        // Step-1 : Separating with the borders
        //  "aa | ddff | kk |"
        for (int i = 1; i <= n; i++) {  

            if (i == n || abs(word[i] - word[i - 1]) > 2) { // satisfying condition-2

                result += countSubstrings(lastIdx, i - 1, k, word); // satisfying condition - 1
                lastIdx = i;
            }
        }
        return result;
    }
};