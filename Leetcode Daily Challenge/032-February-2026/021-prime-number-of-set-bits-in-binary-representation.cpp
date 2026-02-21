// https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        unordered_set<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19 };
        
        int result = 0;

        for (int num = left; num <= right; num++) {
            int setBits = __builtin_popcount(num);
            
            if(primes.count(setBits))
                result += 1;
        }

        return result;
    }
};