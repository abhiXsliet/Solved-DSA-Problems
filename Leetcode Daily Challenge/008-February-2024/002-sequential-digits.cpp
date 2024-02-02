// https://leetcode.com/problems/sequential-digits/description/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(1) 
    vector<int> solve_approach_1(int low, int high) {
        queue<int> q;
        for (int i = 1; i <= 8; i++) 
            q.push(i);

        vector<int> result;

        while(!q.empty()) {
            int temp = q.front();
            q.pop();

            if (temp >= low && temp <= high) {
                result.push_back(temp);
            }

            int last_digit = temp % 10;

            if (last_digit + 1 <= 9)
                q.push((temp * 10) + (last_digit + 1));
        }

        return result;
    }

    // TC : O(1)
    // SC : O(1)
    vector<int> solve_approach_2(int low, int high) {
        vector<int> seqNums {
                                12, 23, 34, 45, 56, 67, 78, 89, 
                                123, 234, 345, 456, 567, 678, 789, 
                                1234, 2345, 3456, 4567, 5678, 6789,
                                12345, 23456, 34567, 45678, 56789, 
                                123456, 234567, 345678, 456789, 
                                1234567, 2345678, 3456789, 
                                12345678, 23456789,
                                123456789
                            };

        int n = seqNums.size();

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (seqNums[i] < low) continue;

            if (seqNums[i] > high) break;

            if (seqNums[i] >= low && seqNums[i] <= high) {
                result.push_back(seqNums[i]);
            }
        }
        return result;
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        // return solve_approach_1(low, high);

        return solve_approach_2(low, high);
    }
};