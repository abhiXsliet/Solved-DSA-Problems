// https://leetcode.com/problems/sum-of-digits-of-string-after-convert/




#include <bits/stdc++.h>    
using namespace std;

class Solution {
private:
    // TC : O(N) + O(K * log(sum)) ~= O(N)
    // SC : O(1)
    int approach_1(string& s, int k) {
        int n = s.length();
        int sum = 0;
        for (char& ch : s) {
            int val = (ch - 'a') + 1;
            while (val) {   // O(2) since max val = 26
                sum += val % 10;
                val /= 10;
            }
        }
        
        while (k > 1) {
            int temp = 0;
            while(sum) {
                temp += sum % 10;
                sum   /= 10;
            }
            sum = temp;
            k --;
        }

        return sum;
    }
public:
    int getLucky(string s, int k) {
        return approach_1(s, k);
    }
};