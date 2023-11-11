// https://leetcode.com/contest/biweekly-contest-117/problems/distribute-candies-among-children-i/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solve_rec(int n, int limit, int child) {
        if (child == 3) {
            return n == 0;
        }
        int ways = 0;
        for (int i = 0; i <= min(n, limit); ++i) {
            ways += solve_rec(n - i, limit, child + 1);
        }
        return ways;
    }
public:
    int distributeCandies(int n, int limit) {
        return solve_rec(n, limit, 0);
    }
};