// https://leetcode.com/problems/count-number-of-balanced-permutations/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    using ll = long long;

    int n;
    const int M = 1e9 + 7;
    int totalDigitSum;
    ll totalPerm = 0;
    vector<int> freq;
    vector<ll> fact;
    vector<ll> invFact;
    vector<vector<vector<ll>>> dp;

    int solve(int digit, int evenIdxDigitCnt, int currSum) {
        if (digit == 10) {
            if (currSum == totalDigitSum/2 && evenIdxDigitCnt == (n + 1)/2)
                return totalPerm;
            return 0;
        }

        if (dp[digit][evenIdxDigitCnt][currSum] != -1)
            return dp[digit][evenIdxDigitCnt][currSum];

        ll ways = 0;

        for (int count = 0; count <= min(freq[digit], (n + 1)/2 - evenIdxDigitCnt); count ++) {
            int evenPosCnt = count;
            int oddPosCnt  = freq[digit] - count;

            ll div = (invFact[evenPosCnt] * invFact[oddPosCnt]) % M;

            ll val = solve(digit + 1, evenIdxDigitCnt + evenPosCnt, currSum + digit * count);

            ways = (ways + (val * div) % M) % M;
        }

        return dp[digit][evenIdxDigitCnt][currSum] = ways;
    }

    // TC : O(N! * N)
    // SC : O(1)
    int brute(string &num) {
        sort(begin(num), end(num));
        int cntBalanced = 0;
        do {
            int evenSum = 0, oddSum = 0;
            for (int i = 0; i < n; i ++) {
                if (i % 2) {
                    oddSum  += (num[i] - '0');
                } else {
                    evenSum += (num[i] - '0');
                }
            }
            if (oddSum == evenSum) cntBalanced += 1;
        } while (next_permutation(begin(num), end(num)));
        return cntBalanced;
    }

    // TC : O(10 * N^2 * sum)
    // SC : O(10 * N * sum)
    int optimal(string &num) {
        totalDigitSum = 0;

        freq.resize(10, 0);
        for (char &ch : num) {
            freq[ch - '0'] ++;
            totalDigitSum += (ch - '0');
        }

        if (totalDigitSum % 2) return 0;

        // precompute factorials
        fact.resize(n + 1, 1);
        for (int i = 2; i <= n; i ++) {
            fact[i] = (fact[i - 1] * i) % M;
        }  

        auto binaryExpo = [&](ll a, ll b) {
            ll res = 1;
            while (b) {
                if (b % 2) {
                    res = (res * a) % M;
                }
                a = (a * a) % M;
                b >>= 1;
            }
            return res;
        };

        // precompute inverse factorial
        invFact.resize(n + 1, 1);
        for (int i = 0; i <= n; i ++) {
            invFact[i] = binaryExpo(fact[i], M - 2) % M;
        }

        totalPerm = (1LL * fact[(n + 1) / 2] * fact[n / 2]) % M;

        int digit = 0;
        int evenIdxDigitCnt = 0;
        int currSum = 0;

        dp.resize(10, vector<vector<ll>>((n + 1)/2 + 1, vector<ll>(totalDigitSum + 1, -1)));
        return solve(digit, evenIdxDigitCnt, currSum);
    }
public:
    int countBalancedPermutations(string num) {
        n = num.size();

        // return brute(num);
        return optimal(num);
    }
};