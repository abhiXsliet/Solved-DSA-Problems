// https://leetcode.com/problems/find-the-count-of-numbers-which-are-not-special/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(sqrt(r) * sqrt(r))
    // SC : O(sqrt(r))
    vector<int> sieve(int limit) {
        vector<int> primes(limit + 1, 1);
        primes[0] = primes[1] = 0;
        for (int i = 2; i * i <= limit; i ++) {
            if (primes[i]) {
                for (int j = 2 * i; j <= limit; j += i) {
                    primes[j] = 0;
                }
            }
        }
        return primes;
    }
public:
    int nonSpecialCount(int l, int r) {
        int limit = sqrt(r);
        vector<int> primes = sieve(limit);
        int maxPossible = r - l + 1;
        int specialCnt  = 0;
        for (int i = 2; i < primes.size(); i ++) {
            if (primes[i]) {
                int val = i * i;
                if (val >= l && val <= r) 
                    specialCnt ++;
            }
        }
        return maxPossible - specialCnt;
    }
};