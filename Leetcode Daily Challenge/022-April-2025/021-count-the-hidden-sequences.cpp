// https://leetcode.com/problems/count-the-hidden-sequences/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long sum = 0, maxi = 0, mini = 0;
        for (int &num : differences) {
            sum += num;
            mini = min(mini, sum);
            maxi = max(maxi, sum);
        }
        long val = ((upper - maxi) - (lower - mini)) + 1;
        return (int)max(0L, val);
    }
};