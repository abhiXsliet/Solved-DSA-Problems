// https://www.geeksforgeeks.org/problems/sum-string3151/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    string addStrings(string &first, string &second) {
        int m = first.length(), n = second.length();
        int i = m - 1, j = n - 1, carry = 0;
        string result;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += (first[i --] - '0');
            if (j >= 0) sum += (second[j --] - '0');
            
            carry = sum / 10;
            result += ((sum % 10) + '0');
        }
        reverse(begin(result), end(result));
        return result;
    }
    
    // TC : O(N)
    // SC : O(N)
    bool isValid(string &s, int n, string &first, string &second, int start) {
        while (start != n) {
            string sum = addStrings(first, second);
            int len = sum.length();
            
            string third = s.substr(start, len);
            
            if (third != sum) return false;
            
            first  = second;
            second = third;
            start += len;
        }
        return true;
    }
    
  public:
    // TC : O(N^3)
    // SC : O(N)
    bool isSumString(string &s) {
        int n = s.length();
        for (int i = 1; i < n; i ++) {
            for (int j = 1; i + j < n; j ++) {
                string first  = s.substr(0, i);
                string second = s.substr(i, j);
                
                // check if the first char is non-zero
                if ((first.length() > 1 && first[0] == '0') || (second.length() > 1 && second[0] == '0'))
                    continue;
                    
                if (isValid(s, n, first, second, i + j)) 
                    return true;
            }
        }
        return false;
    }
};