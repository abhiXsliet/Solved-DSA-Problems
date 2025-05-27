// https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(1)
    int brute(int n, int m) {
        int num1 = 0, num2 = 0;
        for (int i = 1; i <= n; i ++) {
            if (i % m) num1 += i;
            else num2 += i;
        }
        return num1 - num2;
    }

    // TC : O(1)
    // SC : O(1)
    int optimal(int n, int m) {
        int sum = (n * (n + 1) / 2);
        int k = n / m;
        int num2 = (k * (k + 1) / 2) * m;
        int num1 = sum - num2;

        return num1 - num2;
    }
public:
    int differenceOfSums(int n, int m) {
        // return brute(n, m);
        return optimal(n, m);
    }
};