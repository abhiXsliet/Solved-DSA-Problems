// https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(N)
    // SC = O(N) at worst
    vector<vector<int>> solve_1(vector<int>& groupSizes) {
        vector<vector<int>> result;
        map<int, vector<int>> mpp;

        for (int i = 0; i < groupSizes.size(); i++) {
            int groupSize = groupSizes[i];

            if (mpp.find(groupSize) != mpp.end())
                mpp[groupSize].push_back(i);
            else 
                mpp[groupSize] = vector<int>{i};

            if (groupSize == mpp[groupSize].size()) {
                result.push_back(mpp[groupSize]);
                mpp[groupSize] = {};
            }
        }
        return result;
    }

    // TC = O(N)
    // Sc = O(N)
    vector<vector<int>> solve_2(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>> result;
        vector<vector<int>> store(n+1);

        for (int i = 0; i < n; i++) {
            int storeLength = groupSizes[i];

            store[storeLength].push_back(i);

            if (store[storeLength].size() == storeLength) {
                result.push_back(store[storeLength]);
                store[storeLength] = {};
            }
        }
        return result;
    }
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        // return solve_1(groupSizes);

        return solve_2(groupSizes);
    }
};