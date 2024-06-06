// https://leetcode.com/problems/hand-of-straights/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N*log(N)) Where N = Size of Hand
    // SC : O(N)
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return 0;

        map<int, int> mpp;
        for (int& val : hand) mpp[val] ++;

        while(!mpp.empty()) {
            int start = mpp.begin() -> first;

            // creating groups of consecutive elements
            for (int i = 0; i < groupSize; i++) {
                int val = start + i;

                if (mpp.find(val) == mpp.end())
                    return 0;
                else {
                    mpp[val] --;
                    if (mpp[val] == 0) {
                        mpp.erase(val);
                    }
                }
            }
        }
        return true;
    }
};