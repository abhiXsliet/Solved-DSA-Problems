// https://leetcode.com/problems/reverse-words-in-a-string-iii/


#include <bits/stdc++.h>  
using namespace std;


class Solution {
private:
    // TC = O(N), SC = O(1)
    string solve_approach_1(string s) {
        int n = s.length();

        for (int i = 0; i < n; i++) {
            
            if (s[i] != ' ') {
                
                int j = i;
                while (j < n && s[j] != ' ') j++;

                reverse(s.begin() + i, s.begin() + j);

                i = j;
            }
        }

        return s;
    }

    // TC = O(N), SC = O(1)
    string solve_approach_2(string s) {
        int n = s.length();

        stringstream ss(s);

        string token  = "";
        string result = "";

        while (ss >> token) {

            reverse(begin(token), end(token));

            result += token + " ";
        }

        return result.substr(0, result.length() - 1);
    }
public:
    string reverseWords(string s) {
        // return solve_approach_1(s);

        return solve_approach_2(s);
    }
};