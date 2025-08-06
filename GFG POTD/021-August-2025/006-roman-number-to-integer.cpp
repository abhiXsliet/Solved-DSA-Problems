// https://www.geeksforgeeks.org/problems/roman-number-to-integer3201/1https://www.geeksforgeeks.org/problems/roman-number-to-integer3201/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N)
    // SC : O(1)
    int romanToDecimal(string &s) {
        int n = s.length();
        unordered_map<char, int> mpp {
            {'I', 1}, 
            {'V', 5}, 
            {'X', 10}, 
            {'L', 50}, 
            {'C', 100}, 
            {'D', 500}, 
            {'M', 1000}
        };
        
        int result = mpp[s[n - 1]];
        for (int i = n - 2; i >= 0; i --) {
            if (mpp[s[i]] < mpp[s[i + 1]]) {
                result -= mpp[s[i]];
            } else {
                result += mpp[s[i]];
            }
        }
        return result;
    }
};