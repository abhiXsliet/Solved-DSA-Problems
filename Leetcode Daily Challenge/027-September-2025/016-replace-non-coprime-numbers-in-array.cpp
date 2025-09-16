// https://leetcode.com/problems/replace-non-coprime-numbers-in-array/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    using ll = long long;

    ll getLCM(ll a, ll b) {
        return (int)((a / __gcd(a, b)) * b);
    }
public:
    // TC : O(N)
    // SC : O(1)
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> result;
        
        for (int &num : nums) {
            while (!result.empty()) {
                int prev   = result.back();
                int gcdVal = __gcd(num, prev);

                if (gcdVal == 1) break;

                result.pop_back();

                int lcmVal = getLCM(num, prev);
                num = lcmVal;
            }
            result.push_back(num);
        }

        return result;
    }
};