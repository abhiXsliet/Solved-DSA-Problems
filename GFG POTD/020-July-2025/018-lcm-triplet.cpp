// https://www.geeksforgeeks.org/problems/lcm-triplet1501/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    using ll = long long;
    
    ll gcd(ll a, ll b) {
        return !b ? a : gcd(b, a % b);
    }
    
    ll lcm(ll a, ll b) {
        // (a * b) can overflow, but (a / gcd) * b is safer
        return (a / gcd(a, b)) * b;
    }
    
    // TC : O(N^3)
    // SC : O(1)
    int approach_1(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        ll maxLcm = 0;
        for (int i = 1; i <= n; i ++) {
            for (int j = i; j <= n; j ++) {
                for (int k = j; k <= n; k ++) {
                    if (i != j && j != k && i != k) {
                        ll val = lcm(lcm(i, j), k);
                        maxLcm  = max(maxLcm, val);
                    }
                }
            }
        }
        return (int)maxLcm;
    }
    
    // TC : O(1)
    // SC : O(1)
    int approach_2(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        ll maxLcm = 0;
        for (int i = n; i >= n - 3; i --) {
            for (int j = i; j >= n - 3; j --) {
                for (int k = j; k >= n - 3; k --) {
                    if (i != j && j != k && i != k) {
                        ll val = lcm(lcm(i, j), k);
                        maxLcm  = max(maxLcm, val);
                    }
                }
            }
        }
        return maxLcm;
    }
  public:
    int lcmTriplets(int n) {
        // return approach_1(n);   // BRUTE : TLE
        return approach_2(n);
    }
};