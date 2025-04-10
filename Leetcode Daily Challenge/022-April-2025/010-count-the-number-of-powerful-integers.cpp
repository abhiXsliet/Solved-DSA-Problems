// https://leetcode.com/problems/count-the-number-of-powerful-integers/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;

    ll solve(string &str, string &inputSuffix, int limit) {
        if (str.length() < inputSuffix.length())
            return 0;

        ll count = 0;
        int remLength = str.length() - inputSuffix.length();
        string trail  = str.substr(remLength);

        for (int i = 0; i < remLength; i ++) {
            int digit = str[i] - '0';
            if (digit <= limit) {
                count += digit * pow(limit + 1, remLength - i - 1);
            } else {
                count += pow(limit + 1, remLength - i);
                return count;
            }
        }

        if (trail >= inputSuffix) {
            count += 1;
        }

        return count;
    }

    // TC : O(N)
    // SC : O(N) Where N = s.length()
    ll approach_1(ll start, ll finish, int limit, string &s) {
        string after  = to_string(finish);
        string before = to_string(start - 1);

        return solve(after, s, limit) - solve(before, s, limit);
    }
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        return approach_1(start, finish, limit, s);
    }
};