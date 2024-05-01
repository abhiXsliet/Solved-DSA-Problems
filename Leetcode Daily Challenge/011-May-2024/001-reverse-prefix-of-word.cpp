// https://leetcode.com/problems/reverse-prefix-of-word/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N)
    string brute(string& word, char ch) {
        int n = word.length();
        string temp;
        int idx = -1;
        for (int i = 0; i < n; i ++) {
            if (word[i] == ch) {
                temp += word[i];
                idx = i;
                break;
            }
            temp += word[i];
        }
        
        if (idx != -1) 
            reverse(begin(temp), end(temp));
        else return word;

        for (int i = idx + 1; i < n; i ++) {
            temp += word[i];
        }
        return temp;
    }

    // TC : O(N)
    // SC : O(1)
    string better(string& word, char ch) {
        int n   = word.length();
        int i   = 0, j = word.find(ch);
        while (i <= j) {
            swap(word[i], word[j]);
            i ++;
            j --;
        }
        return word;
    }

    // TC : O(N)
    // SC : O(1)
    string optimal_1(string& word, char ch) {
        int n   = word.length();
        int idx = -1;
        for (int i = 0; i < n; i ++) {
            if (word[i] == ch) {
                idx = i;
                break;
            }
        }

        if (idx != -1) 
            reverse(word.begin(), word.begin() + idx + 1);
        
        return word;
    }

    // TC : O(N)
    // SC : O(1)
    string optimal_2(string& word, char ch) {
        reverse(begin(word), begin(word) + word.find(ch) + 1);
        return word;
    }
public:
    string reversePrefix(string word, char ch) {
        // return brute(word, ch);

        // return better(word, ch);

        // return optimal_1(word, ch);

        return optimal_2(word, ch);
    }
};