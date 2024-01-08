// https://leetcode.com/problems/maximum-xor-product/



#include <bits/stdc++.h>
using namespace std;

class Solution {
    int M = 1e9 + 7;
    typedef long long ll;

    // TC : O(2^n) -> OVERFLOW
    // SC : O(1)
    int solve_brute(long long a, long long b, int n) {
        int result = 0;

        for (int x = 0; x < pow(2, n); x++) {
            long long val = (a^x) * (b^x);
            result        = max<long long>(result, val);
        }

        return result;
    }

    // TC : O(N)
    // SC : O(1)
    int solve_optimal(long long a, long long b, int n) {
        ll a_xor_x = 0;
        ll b_xor_x = 0;

        // 49th bit to nth bit : a_xor_x & b_xor_x have the same bit value as 'a' & 'b'
        for (ll i = 49; i >= n; i--) {
            // get the value of ith bit of a
            int a_ith_bit = ((a >> i) & 1);
            // get the value of ith bit of b
            int b_ith_bit = ((b >> i) & 1);

            if (a_ith_bit == 1) {
                // set the ith bit of a_xor_x 
                a_xor_x = (a_xor_x ^ (1ll << i));
            }

            if (b_ith_bit == 1) {
                // set the ith bit of b_xor_x
                b_xor_x = (b_xor_x ^ (1ll << i));
            }
        }

        // (n-1)th bit to 0th bit : these bits could change the a_xor_x / b_xor_x values
        for (ll i = n - 1; i >= 0; i--) {
            
            // get the ith bit of a
            bool a_ith_bit = ((a >> i) & 1) > 0;
            // get the ith bit of b
            bool b_ith_bit = ((b >> i) & 1) > 0; // > than zero equals to 1 otherwise 0

            // if the ith bit of both a and b are same 
            // then we can set the ith bit of a_xor_x or b_xor_x by xoring with either 0 or 1
            if (a_ith_bit == b_ith_bit) { 
                // set the ith bit of a_xor_x 
                a_xor_x = (a_xor_x ^ (1ll << i));
                // set the ith bit of b_xor_x
                b_xor_x = (b_xor_x ^ (1ll << i));

                continue;
            }

            // if 'a_xor_x' is greater then set the ith bit of b_xor_x
            if (a_xor_x > b_xor_x) {
                // set ith bit of b_xor_x
                b_xor_x = (b_xor_x ^ (1ll << i));
            }
            // if 'b_xor_x' is greater then set the ith bit of a_xor_x
            else {
                // set ith bit of a_xor_x
                a_xor_x = (a_xor_x ^ (1ll << i));
            }
        }

        a_xor_x = a_xor_x % M;
        b_xor_x = b_xor_x % M;

        return (a_xor_x * b_xor_x) % M;
    }
public:
    int maximumXorProduct(long long a, long long b, int n) {
        // return solve_brute(a, b, n);

        return solve_optimal(a, b, n);
    }
};