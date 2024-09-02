// https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long sum = accumulate(begin(chalk), end(chalk), 0LL);

        if (k % sum == 0) return 0;

        long long completeRounds = k / sum;
        k = k - (sum * completeRounds);     // remaining chalks after completeRounds

        int idx = 0;
        while (k > 0) {
            k -= chalk[idx ++];
        }

        return k < 0 ? idx - 1 : idx;
    }
};