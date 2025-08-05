// https://www.geeksforgeeks.org/problems/string-palindromic-ignoring-spaces4723/1https://www.geeksforgeeks.org/problems/string-palindromic-ignoring-spaces4723/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N)
    // SC : O(1)
    bool isPalinSent(string &s) {
        int n = s.length();
        int i = 0, j = n - 1;
        while (i <= j) {
            while ( s[i] == ' ' || !isalnum(s[i]) ) i ++;
            while ( s[j] == ' ' || !isalnum(s[j]) ) j --;
            
            if (i >= j) break;
            
            if (tolower(s[i]) != tolower(s[j])) 
                return false;
            i ++, j --;
        }
        return true;
    }
};