// https://leetcode.com/problems/rabbits-in-forest/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N)
    int approach_1(vector<int> &answers) {
        unordered_map<int, int> mpp;
        int cntRabbits = 0;
        for (int &num : answers) {
            mpp[num] ++;
        }
        for (auto &it : mpp) {
            int num  = it.first;
            int freq = mpp[it.first];

            int groupSize = num + 1;
            int groups    = (ceil)((double)freq / groupSize);
            cntRabbits += (groups * groupSize);
        }
        return cntRabbits;
    }
public:
    int numRabbits(vector<int>& answers) {
        return approach_1(answers);
    }
};