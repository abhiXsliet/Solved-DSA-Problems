// https://www.geeksforgeeks.org/problems/case-specific-sorting-of-strings4845/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    // TC : O(N*log(N))
    // SC : O(N)
    string approach_1(string &s) {
        int n = s.length();
        vector<char> lower, upper;
        for (char &ch : s) {
            if (islower(ch)) {
                lower.push_back(ch);
            } else {
                upper.push_back(ch);
            }
        }
        
        sort(begin(lower), end(lower));
        sort(begin(upper), end(upper));
        
        string result;
        int i = 0, j = 0, idx = 0;
        while (idx < n) {
            if (islower(s[idx])) {
                result.push_back(lower[i ++]);
            } else {
                result.push_back(upper[j ++]);
            }
            idx ++;
        }
        return result;
    }
    
    // TC : O(N*log(N))
    // SC : O(1)
    string approach_2(string &s) {
        int n = s.length();
        
        vector<int> lower(26, 0), upper(26, 0);
        for (char &ch : s) {
            if (islower(ch)) {
                lower[ch - 'a'] ++;
            } else {
                upper[ch - 'A'] ++;
            }
        }
        
        string result;
        int i = 0, j = 0, idx = 0;
        
        while (idx < n) {
            if (islower(s[idx])) {
                while (!lower[i]) i ++;
                result += (i + 'a');
                lower[i] --;
            } else {
                while (!upper[j]) j ++;
                result += (j + 'A');
                upper[j] --;
            }
            idx ++;
        }
        
        return result;
    }
  public:
    string caseSort(string& s) {
        // return approach_1(s);
        return approach_2(s);
    }
};