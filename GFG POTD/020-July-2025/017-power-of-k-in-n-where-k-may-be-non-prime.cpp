// https://www.geeksforgeeks.org/problems/power-of-k-in-n-where-k-may-be-non-prime4206/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    // TC : O(sqrt(k))
    // SC : O(sqrt(k))
    unordered_map<int, int> getPrimeFactorizationK(int k) {
        unordered_map<int, int> mpp;
        for (int i = 2; i * i <= k; i ++) {
            while (k % i == 0) {
                mpp[i] ++;
                k /= i;
            }
        }
        if (k > 1) mpp[k] ++;
        return mpp;
    }
    
    // Legendre's Formula to calculate the no. of time prime 'P' occurs in 'N'
    int primePCountInN(int n, int p) {
        int count = 0;
        while (n) {
            n /= p;
            count += n;
        }
        return count;
    }
  public:
    // TC : O(sqrt(k) + m*log(n))
    // SC : O(sqrt(k))
    int maxKPower(int n, int k) {
        unordered_map<int, int> primeFactorK = getPrimeFactorizationK(k);
        
        int result = INT_MAX;
        for (auto &it : primeFactorK) {
            int primeFactor    = it.first;
            int primeFactorCnt = it.second;
            
            int occurances = primePCountInN(n, primeFactor);
            
            result = min(result, occurances / primeFactorCnt);
        }
        return result;
    }
};