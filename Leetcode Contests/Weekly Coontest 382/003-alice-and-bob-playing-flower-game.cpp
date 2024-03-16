// https://leetcode.com/contest/weekly-contest-382/problems/alice-and-bob-playing-flower-game/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;

    // TC : O(1)
    // SC : O(1)
    ll solve_1(int n, int m) {
        ll odd_n  = n / 2;          // odd numbers cnt from 1 to n  
        ll even_n = (n + 1) / 2;    // even numbers cnt from 1 to n

        ll odd_m  = m / 2;          // odd numbers cnt from 1 to n
        ll even_m = (m + 1) / 2;    // even numbers cnt from 1 to m

        return (odd_n * even_m) + (even_n * odd_m);
    }
public:
    long long flowerGame(int n, int m) {
        // return solve_1(n, m);

        return (static_cast<ll>(n) * (m)) / 2;
    }
};