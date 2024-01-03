// https://leetcode.com/problems/number-of-laser-beams-in-a-bank/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N*M) Where N = vector.size() & M = string.length()
    // SC : O(1)
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();

        int prevDeviceCount = 0;
        int totalLaserBeams = 0;

        for (int i = 0; i < n; i++) {

            int currDeviceCount = 0;
            for (char& ch : bank[i]) {
                if (ch == '1') {
                    currDeviceCount ++;
                }
            }

            totalLaserBeams += prevDeviceCount * currDeviceCount;

            if (currDeviceCount != 0)
                prevDeviceCount = currDeviceCount;
        }

        return totalLaserBeams;
    }
};