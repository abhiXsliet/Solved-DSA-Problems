// https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;

    ll getPower(ll range) {
        return log2(range);
    }

    // TC : O(log(K))
    // SC : O(1)
    char approach_1(ll k, vector<int>& operations) {
        ll range = 1;
        while (range < k) {
            range *= 2;
        }

        int increment = 0;
        while (range > 1) {
            ll part1 = range / 2;
            ll power = getPower(range);
            ll extra = (k - part1);
            if (extra > 0) {
                if (operations[power - 1])
                    increment = (increment + 1) % 26;
                k = extra;
            }
            range /= 2;
        }
        return ('a' + increment);
    }

    // TC : O(log(K))
    // SC : O(1)
    char solve(ll k, vector<int>& operations, ll range, ll increment) {
        if (range == 1) return ('a' + increment);

        ll part1 = range / 2;
        ll power = getPower(range);
        ll extra = k - part1;

        if (extra > 0) {
            if (operations[power - 1])
                increment = (increment + 1) % 26;
            k = extra;
        }

        return solve(k, operations, part1, increment);
    }

    char approach_2(ll k, vector<int>& operations) {
        ll range = 1;
        while (range < k) {
            range *= 2;
        }
        ll increment = 0;
        return solve(k, operations, range, increment);
    }
public:
    char kthCharacter(ll k, vector<int>& operations) {
        // return approach_1(k, operations);    // Iterative

        return approach_2(k, operations);    // Recursive
    }
};