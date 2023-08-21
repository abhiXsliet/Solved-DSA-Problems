// https://leetcode.com/problems/repeated-substring-pattern/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC = O(n*√n)
    // SC = O(1)
    bool repeatedSubstringPattern(string s) {
        int n = s.length();

        for(int i = n/2; i >= 1; i--) {
            if(n % i == 0) { // (2*√n) times

                int times = n / i;
                string str = s.substr(0, i); // n 
                string newStr = "";

                while(times--) { // n times
                    newStr += str;
                }
                if(newStr == s) {
                    return true;
                }
            }
        }

        return false;
    }
};