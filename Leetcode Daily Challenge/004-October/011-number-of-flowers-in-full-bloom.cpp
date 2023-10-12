// https://leetcode.com/problems/number-of-flowers-in-full-bloom/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(N * M)
    vector<int> solve_brute(vector<vector<int>>& flowers, vector<int>& people) {
        int m = flowers.size();
        int n = people.size();

        vector<int> result(n);

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {
                int start = flowers[j][0];
                int end   = flowers[j][1];

                if (people[i] >= start && people[i] <= end) {
                    result[i]++;
                }
            }
        }

        return result;
    }

    // TC = O((M + N) * log(N))
    // SC = O(M)
    vector<int> solve_optimal(vector<vector<int>>& flowers, vector<int>& people) {
        int m = flowers.size();
        int n = people.size();

        vector<int> start_time(m);
        vector<int> end_time(m);

        for (int i = 0; i < m; i++) {
            start_time[i] = flowers[i][0];
            end_time[i]   = flowers[i][1];
        }

        sort(begin(start_time), end(start_time));
        sort(begin(end_time), end(end_time));

        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            int time = people[i];

            int bloomed_already = upper_bound(begin(start_time), end(start_time), time) - begin(start_time);
            int died_already    = lower_bound(begin(end_time), end(end_time), time) - begin(end_time);

            result[i] = bloomed_already - died_already;
        }
        return result;
    }
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        // return solve_brute(flowers, people);

        return solve_optimal(flowers, people);
    }
};
