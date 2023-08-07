// https://leetcode.com/problems/sort-vowels-in-a-string/



#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isVowel(char ch) {
        ch = tolower(ch);
        return ( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' );
    }
public:
    string sortVowels(string s) {
        
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
};