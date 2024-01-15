// https://leetcode.com/problems/find-players-with-zero-or-one-losses/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N) + (K * log(K)) Where N = No. Of Matches & K = No. Of Unique Players
    // SC : O(N) + O(N)
    vector<vector<int>> solve_approach_1(vector<vector<int>>& matches) {
        int n = matches.size();

        vector<vector<int>> ans(2, vector<int>());
        unordered_map<int, int> losers;
        unordered_map<int, int> winners;

        for (auto& it : matches) {
            winners[it[0]]++;
            losers [it[1]]++;
        }

        for (auto& win : winners) {
            if (losers.find(win.first) == losers.end()) {
                ans[0].push_back(win.first);
            }
        }

        for (auto& los : losers) {
            if (los.second == 1) {
                ans[1].push_back(los.first);
            }
        }

        for (auto& vec : ans) {
            sort(begin(vec), end(vec));
        }

        return ans;
    }

    // TC : O(N) + (K * log(K))
    // SC : O(N)
    vector<vector<int>> solve_approach_2(vector<vector<int>>& matches) {
        int n = matches.size();

        vector<vector<int>> ans(2, vector<int>());
        unordered_map<int, int> losers;

        for (auto& it : matches) {
            losers [it[1]]++;
        }

        for (auto& mat : matches) {
            if (losers.find(mat[0]) == losers.end()) {
                ans[0].push_back(mat[0]);
                losers[mat[0]] ++;
            }

            if (losers[mat[1]] == 1) {
                ans[1].push_back(mat[1]);
            }
        }

        for (auto& vec : ans) {
            sort(begin(vec), end(vec));
        }

        return ans;
    }
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        // return solve_approach_1(matches);

        return solve_approach_2(matches);
    }
};