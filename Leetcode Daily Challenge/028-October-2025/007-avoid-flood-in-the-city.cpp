// https://leetcode.com/problems/avoid-flood-in-the-city/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();

        vector<int> result(n, 1);
        unordered_map<int, int> mpp;
        set<int> st;

        for (int i = 0; i < n; i ++) {
            int lake = rains[i];

            if (lake == 0) st.insert(i);
            else {
                result[i] = -1;
                
                // also check if this lake already contains water, if yes then dry it 
                if (mpp.count(lake)) {

                    auto it = st.lower_bound(mpp[lake]);

                    if (it == st.end()) return {};

                    // day on which rain happened
                    int day = *it;
                    result[day] = lake;
                    st.erase(day);
                }
                
                mpp[lake] = i;
            }
        }

        return result;
    }
};