// https://leetcode.com/problems/number-of-wonderful-substrings/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;

    // TC : O(N)
    // SC : O(N) Where N = length of the word
    ll wonderfulSubstrings(string word) {
        unordered_map<ll, ll> mpp;

        mpp[0] = 1;     // In past, I had seen cumm_xor = 0

        int cumm_xor = 0;
        ll result    = 0;

        for (char& ch : word) {

            int shift = ch - 'a';
            // 1 << shift -> Binary rep. of ch

            cumm_xor ^= (1 << shift);

            result   += mpp[cumm_xor];  // all char are even in count

            for (char c = 'a'; c <= 'j'; c++) {
                shift = c - 'a';

                ll check_xor = (cumm_xor ^ (1 << shift));

                result += mpp[check_xor];
            }

            mpp[cumm_xor] ++;
        }

        return result;
    }
};