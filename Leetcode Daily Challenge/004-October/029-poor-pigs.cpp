// https://leetcode.com/problems/poor-pigs/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solve(int buckets, int minutesToDie, int minutesToTest) {
        int trials = minutesToTest / minutesToDie + 1; // +1 because we can check trials+1 rows and cols

        int pigs = 0;
        while (pow(trials, pigs) < buckets) {
            pigs++;
        }
        
        return pigs;
    }

    int solve_one_liner(int buckets, int minutesToDie, int minutesToTest) {
        // (trial+1)^pigs = no. of buckets // +1 because we can check trials+1 rows and cols
        
        // log2((trial+1) ^ pigs) = log2(buckets);
        return ceil(log2(buckets) / log2(minutesToTest / minutesToDie + 1));
    }
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        // return solve(buckets, minutesToDie, minutesToTest);

        return solve_one_liner(buckets, minutesToDie, minutesToTest);
    }
};