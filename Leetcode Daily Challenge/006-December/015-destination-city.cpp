// https://leetcode.com/problems/destination-city/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N)
    string solve_approach_1(vector<vector<string>>& paths) {
        unordered_map<string, int> mpp;

        for (auto& path : paths) {
            string source = path[0];
            mpp[source] = 1;
        }

        for (auto& path : paths) {
            string dest = path[1];

            if (mpp[dest] != 1) 
                return dest;
        }

        return "";
    }

    // TC : O(N)
    // SC : O(N)
    string solve_approach_2(vector<vector<string>>& paths) {
        unordered_set<string> st;

        for (auto& path : paths) {
            string source = path[0];
            // outgoing edge from this string source
            st.insert(source);
        }

        for (auto& path : paths) {
            string dest = path[1];

            // outgoing edge not present then it is destination
            if (st.find(dest) == st.end()) 
                return dest;
        }

        return "";
    }
public:
    string destCity(vector<vector<string>>& paths) {
        // return solve_approach_1(paths);

        return solve_approach_2(paths);
    }
};