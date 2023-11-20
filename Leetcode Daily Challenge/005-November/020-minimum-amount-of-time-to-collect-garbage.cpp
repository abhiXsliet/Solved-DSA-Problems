// https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();

        int M_idx = -1;
        int P_idx = -1;
        int G_idx = -1;

        // Time required for picking up the garbage 
        // from different houses
        int time  = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < garbage[i].length(); j++) {
                if (garbage[i][j] == 'M') {
                    M_idx = i;
                }
                else if (garbage[i][j] == 'P') {
                    P_idx = i;
                }
                else {
                    G_idx = i;
                }
                time ++;
            }
        }

        // calculate the prefix sum of travel time
        // modified the travel array itself 
        int m = travel.size();
        for (int i = 1; i < m; i++) {
            travel[i] = travel[i - 1] + travel[i];
        }

        time += M_idx - 1 <= -1 ? 0 : travel[M_idx - 1];
        time += P_idx - 1 <= -1 ? 0 : travel[P_idx - 1];
        time += G_idx - 1 <= -1 ? 0 : travel[G_idx - 1];

        return time;
    }
};