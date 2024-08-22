// https://leetcode.com/problems/number-complement/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    string convertIntoBinary(int num) {
        string ans;
        while (num) {
            int d = num % 2;
            ans += (d + '0');
            num /= 2;
        }
        reverse(begin(ans), end(ans));
        return ans;
    }

    int convertIntoDecimal(string num) {
        int n = num.length();
        long pow = 1;
        int ans  = 0;
        for (int i = n - 1; i >= 0; i --) {
            int digit = num[i] - '0';
            digit    *= pow;
            pow      *= 2;
            ans      += digit;
        }
        return ans;
    }

    // TC : O(log(num))
    // SC : O(31) ~= O(1)
    int brute(int num) {
        string binary = convertIntoBinary(num);
        
        // Complementing bits
        for (char& ch : binary) {
            if (ch == '0') ch = '1';
            else ch = '0';
        }
        
        int decimal   = convertIntoDecimal(binary);
        return decimal;
    }

    // TC : O(log(num))
    // SC : O(1)
    int better_1(int num) {
        int bits_cnt = (int)(log2(num)) + 1;
        int mask = 1;
        
        for (int i = 0; i < bits_cnt; i ++) {
            num ^= (mask << i);
        }

        return num;
    }
    
    // TC : O(log(num))
    // SC : O(1)
    int better_2(int num) {
        int bits_cnt = (int)(log2(num)) + 1;

        // suppose 1 << 3 = 8 - 1 = 7 : 111
        unsigned int mask = (1U << bits_cnt) - 1; 

        return num ^ mask;
    }

    // TC : O(log(num))
    int optimal(int num) {
        int complement = 0;
        int i = 0;
        while (num) {

            if (!(num & 1)) {   // If it's a 0 then we have to flip it
                complement |= (1 << i);
            }

            i ++;
            num >>= 1;
        }

        return complement;
    }
public:
    int findComplement(int num) {
        // return brute(num);     // Convert into Binary, complement it and then convert into Decimal

        // return better_1(num);  // Create mask and process bit by bit

        // return better_2(num);  // Instead of Processing it bit by bit, create a mask of bitsCnt

        return optimal(num);
    }
};