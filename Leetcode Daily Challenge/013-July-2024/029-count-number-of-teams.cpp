// https://leetcode.com/problems/count-number-of-teams/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(1)
    int approach_1(vector<int>& rating, int n) {
        int teams = 0;
        for (int j = 1; j < n - 1; j ++) {
            int cntSmallerLeft  = 0;
            int cntLargerRight  = 0;
            int cntSmallerRight = 0;
            int cntLargerLeft   = 0;

            // get the smallest & largest in the left
            for (int i = 0; i < j; i ++) {
                if (rating[i] > rating[j]) cntLargerLeft  ++;
                if (rating[i] < rating[j]) cntSmallerLeft ++;
            }

            // get the smallest & largest in the right
            for (int k = j + 1; k < n; k ++) {
                if (rating[k] > rating[j]) cntLargerRight  ++;
                if (rating[k] < rating[j]) cntSmallerRight ++;
            }

            teams += cntSmallerLeft  * cntLargerRight;
            teams += cntLargerLeft   * cntSmallerRight;
        }
        return teams;
    }
public:
    int numTeams(vector<int>& rating) {
        return approach_1(rating, rating.size());

        // return approach_2(rating, rating.size());   // Using Recursion : Pending???
    }
};