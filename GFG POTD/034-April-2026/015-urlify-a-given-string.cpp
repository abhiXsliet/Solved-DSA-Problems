// https://www.geeksforgeeks.org/problems/urlify-a-given-string--141625/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string URLify(string &s) {
        string res;
        for (char &ch : s) {
            if (ch != ' ') {
                res += ch;
            } else {
                res += "%20";
            }
        }
        return res;
    }
};