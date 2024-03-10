// https://leetcode.com/problems/maximum-number-of-balloons/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N)
    int solve_brute(string text) {
        string s = "balloon";
        unordered_map<char, int> mpp;
        for (char& ch : text) {
            mpp[ch] ++;
        }

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for (char& ch : s) {
            mini = min(mini, mpp[ch]);
            maxi = max(maxi, mpp[ch]);
        }

        for (char& ch : s) {
            if (mpp['l'] < 2 * mini || mpp['o'] < 2 * mini)
                return min(mpp['l'], mpp['o']) / 2;
        }

        if (maxi >= 2 * mini)
            return mini;
        return 0;
    }

    // TC : O(N)
    // SC : O(5) ~= O(1)
    int solve_optimal(string text) {
        unordered_map<char, int> mpp;
        for (char& ch : text) {
            if (ch == 'b' || ch == 'a' || ch == 'l' || ch == 'o' || ch == 'n')
                mpp[ch]++;
        }

        int mini = min({mpp['b'], mpp['a'], mpp['l'] / 2, mpp['o'] / 2, mpp['n']});
        return mini;
    }

public:
    int maxNumberOfBalloons(string text) {
        // return solve_brute(text);

        return solve_optimal(text);
    }
};