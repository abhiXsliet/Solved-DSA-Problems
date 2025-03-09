// https://leetcode.com/problems/closest-prime-numbers-in-range/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    // TC : O(R * log(log(R)))  // R = right range
    // SC : O(R)
    vector<int> getPrimesInRange(int left, int right) {
        vector<bool> primes(right + 1, true);
        primes[0] = primes[1] = false;
        for (int i = 2; i * i <= right; i ++) {
            if (primes[i]) {
                for (int j = 2 * i; j <= right; j += i) {
                    primes[j] = false;
                }
            }
        }
        vector<int> result;
        for (int i = 0; i < primes.size(); i ++) {
            if (primes[i] && i >= left) {
                result.push_back(i);
            }
        }
        return result;
    }

    // TC : O(R * log(log(R)))
    // SC : O(R + R/log(R))     primes can hold at max ( R/log(R) ) elements
    vector<int> approach_1(int left, int right) {
        vector<int> primes = getPrimesInRange(left, right);
        int size = primes.size();
        int first = -1, second = -1;
        int minDiff = INT_MAX;
        for (int i = 0; i < size - 1; i ++) {
            if ((primes[i + 1] - primes[i]) < minDiff) {
                minDiff = (primes[i + 1] - primes[i]);
                first   = primes[i];
                second  = primes[i + 1];
            }
        }
        return {first, second};
    }
public:
    vector<int> closestPrimes(int left, int right) {
        return approach_1(left, right);
    }
};