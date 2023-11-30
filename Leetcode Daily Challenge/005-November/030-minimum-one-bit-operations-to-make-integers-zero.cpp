// https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC = O(1)
    // SC = O(1)
    int minimumOneBitOperations(int n) {
        // No Operation
        if (n == 0) return 0;

        // Create the 'F' array
        // F[i] = No. of operations to convert a no. (having only ith bit set) to 0
        vector<long long> F(31, 0);

        // Only one operation required to change only single bit no. (1 -> 0)
        F[0] = 1;

        for (int i = 1; i < 31; i++) {
            F[i] = 2 * F[i - 1] + 1;
        }

        int result = 0;
        int sign   = 1;

        for (int i = 30; i >= 0; i--) {
            // left to right
            // to find the ith bit of n
            int ith_bit = ((1 << i) & n);  // "01001" = F[3] - F[0]

            if (ith_bit == 0) continue;

            if (sign > 0) {
                result += F[i];
            }
            else {
                result -= F[i];
            }

            sign *= -1;
        }

        return result;
    }
};