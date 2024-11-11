// https://leetcode.com/problems/prime-subtraction-operation/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void sieve(vector<int>& primes) {
        primes[0] = primes[1] = 0;  // 0 and 1 is not a prime no.
        for (int i = 2; i * i < primes.size(); i ++) {
            if (primes[i]) {
                for (int j = 2 * i; j < primes.size(); j += i) {
                    primes[j] = 0;
                }
            }
        }
    }

    // TC : O(N * maxNum) Where N = 1000 at worst and maxNum = 1000 at worst
    // SC : O(N)
    bool approach_1(vector<int>& nums) {
        int n = nums.size();
        vector<int> primes(1000, 1);
        sieve(primes);

        for (int i = n - 2; i >= 0; i --) {
            if (nums[i] < nums[i + 1]) continue;
            // else nums[i] >= nums[i + 1] then decrease nums[i] at least less than nums[i + 1]

            // check prime no.s less than nums[i];
            for (int p = 2; p < nums[i]; p ++) {
                if (!primes[p]) continue;

                if (nums[i] - p < nums[i + 1]) {
                    nums[i] -= p;
                    break;
                }
            }

            if (nums[i] >= nums[i + 1]) return false;
        }

        return true;
    }
public:
    bool primeSubOperation(vector<int>& nums) {
        return approach_1(nums);
    }
};