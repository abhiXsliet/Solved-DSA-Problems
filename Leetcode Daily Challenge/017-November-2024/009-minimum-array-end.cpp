// https://leetcode.com/problems/minimum-array-end/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;

    // TC : O(N)
    // SC : O(1)
    ll approach_1(int n, int x) {
        ll ans = x; // 1st no. 
        for (int i = 1; i < n; i ++) {
            ans = (ans + 1) | x;    // get the next greater no.
        }
        return ans;
    }
public:
    ll minEnd(int n, int x) {
        return approach_1(n, x); // NGE = (prev no. + 1) | x

        // return approach_2(n, x);    // pending : split all the bits and fill it with LSB
    }
};