// https://leetcode.com/problems/sort-vowels-in-a-string/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isVowel(char ch) {
        ch = tolower(ch);
        return ( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' );
    }

    // TC = O(N * log(N))
    // SC = O(N)
    string solve_brute(string& s) {
        vector<char>store;
        for(int i = 0; i < s.size(); i++) {
            if(isVowel(s[i]))
                store.push_back(s[i]);
        }
        
        sort(store.begin(), store.end());

        int j = 0;
        for(int i = 0; i < s.size(); i++) {
            if(isVowel(s[i])) 
                s[i] = store[j++];
        }
        return s;
    }

    // TC = O(N)
    // SC = O(N)
    // Counting Sort
    string solve_optimal(string& s) {
        int n = s.length();

        unordered_map<char, int> mpp;
        
        for (char &ch : s) {
            if (isVowel(ch)) {
                mpp[ch]++;
            }
        }

        string vowels = "AEIOUaeiou";
        int j = 0; // j is pointing to 'A'

        for (int i = 0; i < n; i++) {
            if (isVowel(s[i])) {

                // vowels are not available in mpp 
                // then move j
                while(mpp[vowels[j]] == 0) {
                    j++;
                }

                s[i] = vowels[j];
                mpp[vowels[j]]--;
            }
        }
        return s;
    }
public:
    string sortVowels(string s) {
        // return solve_brute(s);

        return solve_optimal(s);
    }
};