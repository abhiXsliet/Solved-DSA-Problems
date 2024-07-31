// https://leetcode.com/problems/reach-a-number/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(target)
    // SC : O(1)
    int approach_1(int target) {
        target    = abs(target);
        int steps = 0;
        int sum   = 0;
        while ((sum < target) || (target - sum) % 2 != 0) {
            steps += 1;
            sum   += steps;
        }
        return steps;
    }
public:
    int reachNumber(int target) {
        return approach_1(target);  // MATH

                                    // Explore other approaches?
    }
};