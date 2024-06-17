// https://leetcode.com/problems/sum-of-square-numbers/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;

    // TC : O(46340 * 46340) ~= O(sqrt(c)*sqrt(c)) ~= O(c)
    // SC : O(1)
    bool brute(int c) {
        for (ll i = 0; i <= sqrt(c); i++) {
            for (ll j = 0; j <= sqrt(c); j ++) {
                if (i*i + j*j == c) {
                    return true;
                }
            }
        }
        return false;
    }

    // TC : O(sqrt(c) * log(c))
    // SC : O(1)
    bool better_1(int c) {
        for (ll a = 0; a <= sqrt(c); a++) {
            ll b = sqrt(c - a*a);   // log(sqrt(c))

            if (b*b == (c - a*a)) 
                return true;
        }
        return false;
    }

    // TC : O(sqrt(c)*log(sqrt(c))) 
    // SC : O(1)
    bool better_2(int c) {
        for (ll i = 0; i <= sqrt(c); i++) {
            int low = 0, high = sqrt(c);
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (i*i + mid*mid == c) {
                    return true;
                } else if (i*i + mid*mid < c) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return false;
    }

    // TC : O(sqrt(c))
    // SC : O(1)
    bool optimal(int c) {
        ll l = 0, r = sqrt(c);
        while (l <= r) {
            if (l*l + r*r == c) 
                return true;
            else if (l*l + r*r < c) 
                l += 1;
            else 
                r -= 1;
        }
        return false;
    }
public:
    bool judgeSquareSum(int c) {
        // return brute(c);     // Two-Loops

        // return better_1(c);  // Use Sqrt() func

        // return better_2(c);  // Use Binary Search

        return optimal(c);      // Use 2-Pointer Approach
    }
};