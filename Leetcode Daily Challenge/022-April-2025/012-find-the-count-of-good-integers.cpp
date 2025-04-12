// https://leetcode.com/problems/find-the-count-of-good-integers/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;

    // TC : O(10^digits * nlogn)
    // SC : O(10^digits * n)
    long long countGoodIntegers(int n, int k) {
        unordered_set<string> st;
        vector<ll> factorial(11, 1);
        for (int i = 2; i <= 10; i ++) {
            factorial[i] = factorial[i - 1] * i;
        }

        int halfD = (n + 1) / 2;
        int start = pow(10, halfD - 1);
        int end   = pow(10, halfD) - 1;

        // O(pow(10, halfD) * nlogn)
        for (int val = start; val <= end; val ++) {
            string leftHalf = to_string(val);
            string total;
            
            if (n % 2 == 0) {
                string rightHalf = leftHalf;
                reverse(rightHalf.begin(), rightHalf.end());
                total = leftHalf + rightHalf;
            } else {
                string rightHalf = leftHalf.substr(0, halfD - 1);
                reverse(rightHalf.begin(), rightHalf.end());
                total = leftHalf + rightHalf;
            }

            ll number = stoll(total);
            if (number % k != 0)
                continue;
            
            sort(total.begin(), total.end());
            st.insert(total);
        }

        ll result = 0;
        for (const string &s : st) {
            vector<int> freq(10, 0);
            for (const char &ch : s) {
                freq[ch - '0'] ++;
            }

            int totalDigits   = s.length();
            int zeroDigits    = freq[0];
            int nonZeroDigits = totalDigits - zeroDigits;

            ll cntPermutation = (nonZeroDigits * factorial[totalDigits - 1]);

            // divide it factorial of digits to get the unique no. of permutations
            for (int i = 0; i < 10; i ++) {
                cntPermutation /= factorial[freq[i]];
            } 

            result += cntPermutation;
        }
        return result;
    }
};