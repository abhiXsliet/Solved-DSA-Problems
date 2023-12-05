// https://leetcode.com/problems/count-of-matches-in-tournament/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(log(N))
    // SC = O(1)
    int solve_approach_1(int n) {
        int matches = 0;

        while(n != 1) {
            if (n % 2 != 0) {
                matches += (n - 1) / 2;
                n = n / 2 + 1;
            }
            else {
                matches += n / 2;
                n = n / 2;
            }
        }

        return matches;
    }

    // TC = O(1)
    // SC = O(1)
    int solve_approach_2(int n) {
        return (n - 1);
    }
public:
    int numberOfMatches(int n) {
        // return solve_approach_1(n);

        return solve_approach_2(n);
    }
};