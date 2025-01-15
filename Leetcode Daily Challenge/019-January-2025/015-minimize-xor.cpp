// https://leetcode.com/problems/minimize-xor/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isSet(int &num, int b) {
        return (num & (1 << b));
    }

    void setBit(int &x, int b) {
        x |= (1 << b);
    }

    void unSetBit(int &x, int b) {
        x ^= (1 << b);
    }

    int getNoOfBits(int n) {
        int cntBits = 0;
        while (n) {
            n >>= 1;
            cntBits += 1;
        }
        return cntBits == 0 ? 1 : cntBits;
    }

    int getSetBits(int num, int bitsCnt) {
        int cntSetBits = 0;
        for (int bit = 0; bit < bitsCnt; bit ++) {
            if (num & (1 << bit)) {
                cntSetBits += 1;
            }
        } 
        return cntSetBits;
    }
private:
    int approach_1(int num1, int num2) {
        int x = 0;
        int bits_in_num1     = getNoOfBits(num1);   
        int bits_in_num2     = getNoOfBits(num2);   // log2(num2) + 1
        int set_bits_in_num2 = getSetBits(num2, bits_in_num2);  //__builtin_popcount(x)

        // now set bits of x till index set_bits_in_num2 
        for (int bit = bits_in_num1 - 1; bit >= 0; bit --) {
            if (isSet(num1, bit)) {
                setBit(x, bit);
                set_bits_in_num2 -= 1;
                if (set_bits_in_num2 == 0) {
                    return x;
                }
            }
        } 

        if (set_bits_in_num2) {
            for (int bit = 0; bit < bits_in_num2; bit ++) {
                if (!isSet(num1, bit)) {
                    setBit(x, bit);
                    set_bits_in_num2 -= 1;
                    if (set_bits_in_num2 == 0) {
                        return x;
                    }
                }
            }
        }

        return x;
    }

    int approach_2(int num1, int num2) {
        int x = num1;
        int set_bits_num1 = __builtin_popcount(num1);
        int set_bits_num2 = __builtin_popcount(num2);
        int cntOfSetBits  = abs(set_bits_num1 - set_bits_num2);

        int bit = 0;
        if (set_bits_num1 > set_bits_num2) {
            while (cntOfSetBits) {
                if (isSet(num1, bit)) {
                    unSetBit(x, bit);
                    cntOfSetBits --;
                }
                bit ++;
            }
        } else if (set_bits_num1 < set_bits_num2) {
            while (cntOfSetBits) {
                if (!isSet(num1, bit)) {
                    setBit(x, bit);
                    cntOfSetBits --;
                }
                bit ++;
            }
        }
        return x;
    }

    int approach_3(int num1, int num2) {
        int x = 0;
        int bits_of_num2  = log2(num2) + 1;
        int set_bits_num2 = getSetBits(num2, bits_of_num2);   // __builtin_popcount()

        for (int b = 31; b >= 0 && set_bits_num2 > 0; b --) {
            if (isSet(num1, b)) {
                setBit(x, b);
                set_bits_num2 -= 1;
            }
        }

        for (int b = 0; b < 32 && set_bits_num2 > 0; b ++) {
            if (!isSet(num1, b)) {
                setBit(x, b);
                set_bits_num2 -= 1;
            }
        }

        return x;
    }
public:
    int minimizeXor(int num1, int num2) {
        // return approach_1(num1, num2);  // Brute : Simulating
        // return approach_2(num1, num2);  // Optimal
        return approach_3(num1, num2);  // Optimal
    }
};