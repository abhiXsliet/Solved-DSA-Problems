// https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int M = 1e9 + 7;

    // TC = O(N)
    // SC = O(N)
    int numberOfWays(string corridor) {
        int n = corridor.size();

        vector<int> seat_indices;

        for (int i = 0; i < n; i++) {
            if (corridor[i] == 'S') {
                seat_indices.push_back(i);
            }
        }
        
        if (seat_indices.size() % 2 != 0 || seat_indices.size() == 0)
            return 0;

        // end index of previous 2-seats subarray
        int end_idx_prev = seat_indices[1];

        long long result = 1;

        for (int i = 2; i < seat_indices.size(); i += 2) {
            
            // start index of next 2-seats subarray after prev 2-seats subarray
            int curr_idx_next = seat_indices[i];

            // No. of dividers can be placed onto positions
            int positions = curr_idx_next - end_idx_prev;

            result = (result * positions) % M;

            end_idx_prev = seat_indices[i + 1];
        }

        return result;
    }
};