// https://leetcode.com/problems/eliminate-maximum-number-of-monsters/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC = O(N * log(N)) 
    // SC = O(N) -> to store the time taken by each monster to reach the city
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();

        vector<int> time(n, 0);
        for (int i = 0; i < n; i++) {
            time[i] = ceil((float)dist[i] / speed[i]);
        }

        int monstersKilled = 1;
        int time_passed    = 1;

        // sort the time so that monster with min time gets killed
        sort(begin(time), end(time));

        for (int i = 1; i < n; i++) {
            if (time[i] - time_passed <= 0) {
                return monstersKilled;
            }

            monstersKilled ++;
            time_passed += 1;     // to recharge the weapon again
        }

        return monstersKilled;
    }
};