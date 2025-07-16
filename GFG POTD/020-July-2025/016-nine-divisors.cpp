// https://www.geeksforgeeks.org/problems/nine-divisors3751/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    vector<int> getAllPrimes(int n) {
        vector<int> primes(n + 1, 1);
        primes[0] = primes[1] = 0;
        for (int i = 2; i * i <= n; i ++) {
            for (int j = 2*i; j <= n; j += i) {
                if (primes[i]) {
                    primes[j] = 0;
                }
            }
        }
        vector<int> result;
        for (int i = 2; i <= n; i ++) {
            if (primes[i]) result.push_back(i);
        }
        return result;
    }
  public:
    // TC : O(sqrt(N) * log(log(sqrt(N))))
    // SC : O(sqrt(N))
    int countNumbers(int n) {
        int limit = sqrt(n);
        vector<int> primes = getAllPrimes(limit);
        
        int totalCnt = 0;
        // cnt no.s whose p^8 <= n 
        for (int i = 0; i < primes.size(); i ++) {
            long long val = pow(primes[i], 8);
            if (val <= n) totalCnt += 1;
            else break;
        }
        
        // cnt no.s such that (p^2 * q^2) <= n
        for (int i = 0; i < primes.size(); i ++) {
            for (int j = i + 1; j < primes.size(); j ++) {
                long long val = 1LL * (primes[i] * primes[i]) * (primes[j] * primes[j]);
                if (val <= n) totalCnt += 1;
                else break;
            }
        }
        return totalCnt;
    }
};