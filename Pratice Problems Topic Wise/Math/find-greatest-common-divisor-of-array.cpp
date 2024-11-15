// https://leetcode.com/problems/find-greatest-common-divisor-of-array/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(a + b)
    // SC : O(1)
    int getGCD(int a, int b) {
        if (a == 0) return b;
        if (b == 0) return a;
        while (a != b) {
            if (a > b) {
                a -= b;
            } else {
                b -= a;
            }
        }
        return a;
    }

    // TC : O(log(min(a, b)))
    // SC : O(1)
    int _getGCD(int a, int b) {
        if (b == 0) return a;
        return _getGCD(b, a % b);
    }
public:
    int findGCD(vector<int>& nums) {
        int mini = *min_element(begin(nums), end(nums));
        int maxi = *max_element(begin(nums), end(nums));
        // return getGCD(mini, maxi);  // Iterative : Less Efficient
        // return _getGCD(mini, maxi); // Recursive
        return __gcd(mini, maxi);   // C++ STL : TC = O(log(min(a, b)))
    }
};