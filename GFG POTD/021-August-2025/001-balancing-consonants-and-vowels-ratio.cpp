// https://www.geeksforgeeks.org/problems/balancing-consonants-and-vowels-ratio/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
  public:
    // TC : O(N)
    // SC : O(N)
    int countBalanced(vector<string>& arr) {
        unordered_map<int, int> freq;
        freq[0] = 1; // base case: prefix balance 0 occurred once
        int balance = 0;
        int result = 0;
    
        for (string& s : arr) {
            int v = 0, c = 0;
            for (char ch : s) {
                if (isVowel(ch)) v++;
                else c++;
            }
    
            balance += (v - c);
    
            result += freq[balance]; // add how many times this balance was seen before
            freq[balance]++;
        }
    
        return result;

    }
};