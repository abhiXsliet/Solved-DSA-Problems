// https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(1)
    int approach_1(string& s, int n) {
        int i = 0;
        int j = n - 1;

        while (i <= j) {

            if (i != j && s[i] == s[j]) {

                if (i + 1 != j && s[i + 1] == s[j]) {
                    i += 1;
                }
                else if (j - 1 != i && s[i] == s[j - 1]) {
                    j -= 1;
                }
                else {
                    i += 1;
                    j -= 1;
                }
            }
            else return (j - i + 1);
        }
        return 0;
    }

    // TC : O(N)
    // SC : O(1)
    int approach_2(string& s, int n) {
        int i = 0;
        int j = n - 1;

        while (i < j && s[i] == s[j]) {
            char ch = s[i];
            while (i  < j && s[i] == ch) i ++;
            while (j >= i && s[j] == ch) j --;
        }
        return j - i + 1;
    }
public:
    int minimumLength(string s) {
        // return approach_1(s, s.length());

        return approach_2(s, s.length());   
    }
};