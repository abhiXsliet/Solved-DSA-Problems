// https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;

    // TC : O(log(K))
    // SC : O(1)
    char kthCharacter(long long k, vector<int>& operations) {
        ll range = 1;
        int power = 0;
        while (range < k) {
            range *= 2;
            power += 1;
        }

        int increment = 0;
        while (range > 1) {
            ll half  = (range / 2);

            ll extra = (k - half);

            if (extra > 0) {
                increment += (operations[power - 1] == 1) ? 1 : 0;
                k = extra;
            }
            power -=1;
            range /= 2;
        }

        increment %= 26;
        return ('a' + increment);
    }
};