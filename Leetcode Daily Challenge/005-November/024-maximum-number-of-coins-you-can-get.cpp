// https://leetcode.com/problems/maximum-number-of-coins-you-can-get/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(N * log(N))
    // SC = O(1)
    int solve_approach_1(vector<int>& piles) {
        int n = piles.size();

        sort(begin(piles), end(piles));

        int Alice_ptr = n - 1;  // always takes maximum pile
        int My_ptr    = n - 2;  // take next maximum pile
        int Bob_ptr   = 0;

        int result = 0;

        while (My_ptr > Bob_ptr) {
            result += piles[My_ptr];
            My_ptr -= 2;
            Alice_ptr -= 2;
            Bob_ptr ++;
        }

        return result;
    }

    // TC = O(N * log(N))
    // SC = O(1)
    int solve_approach_2(vector<int>& piles) {
        int n = piles.size();

        sort(begin(piles), end(piles));

        int result = 0;

        for (int my_turn = n / 3; my_turn < n; my_turn += 2) {
            result += piles[my_turn];
        }

        return result;
    }
public:
    int maxCoins(vector<int>& piles) {
        // return solve_approach_1(piles);

        return solve_approach_2(piles);
    }
};