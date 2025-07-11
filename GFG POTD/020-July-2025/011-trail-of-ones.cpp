// https://www.geeksforgeeks.org/problems/trail-of-ones3242/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int fib(int n, vector<int>& fibonacci) {
        if (n == 2 || n == 3) return fibonacci[n] = 1;
        return fibonacci[n] = (fib(n - 1, fibonacci) + fib(n - 2, fibonacci));
    }
    
    int solve(int n, vector<int> &fibonacci) {
        if (n == 2) return 1;
        return ( (2 * solve(n - 1, fibonacci)) + fibonacci[n] );
    }
    
    // TC : O(N + N)
    // SC : O(1)
    int approach_1(int n) {
        vector<int> fibonacci(n + 1);
        fib(n, fibonacci);
        return solve(n, fibonacci);
    }
    
    // TC : O(N)
    // SC : O(1)
    int approach_2(int n) {
        int prev1 = 0, prev2 = 1;
        int ans   = 1;
        for (int i = 3; i <= n; i ++) {
            int sum = prev1 + prev2;
            
            ans = (2 * ans) + sum;
            
            prev1 = prev2;
            prev2 = sum;
        }
        return ans;
    }
  public:
    int countConsec(int n) {
        // return approach_1(n);
        return approach_2(n);
    }
};