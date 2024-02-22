// https://leetcode.com/problems/find-the-town-judge/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N * M) Where N = No. Of Peoples, M = Size Of Map At Worst
    // SC : O(K)     Where K = Size Of Map At Worst
    int solve_1(int n, vector<vector<int>>& trust) {
        if (n >= 2 && trust.size() == 0) return -1;
        
        unordered_map<int, unordered_set<int>> mpp;
        for (auto& v : trust) {
            mpp[v[0]].insert(v[1]);
        }

        int ans = -1;
        for (int i = 1; i <= n; i++) {
            if (mpp.find(i) != mpp.end()) continue;
            else ans = i;

            for (auto& it : mpp) {
                unordered_set<int> stStore = it.second;
                if (stStore.find(ans) == stStore.end()) {
                    ans = -1;
                    break;
                }
            }
        }
        return ans;
    }

    // TC : O(N)
    // SC : O(N) + O(N) ~= O(N)
    int solve_2(int n, vector<vector<int>>& trust) {
        vector<int> indegree (n + 1);
        vector<int> outdegree(n + 1);

        for (auto& vec : trust) {
            int u = vec[0];
            int v = vec[1];

            outdegree[u]++;
            indegree[v] ++;
        }

        for (int i = 1; i <= n; i++) {
            if (indegree[i] == n - 1 && outdegree[i] == 0) {
                return i;
            }
        }
        return -1;
    }

    // TC : O(N)
    // SC : O(N)
    int solve_3(int n, vector<vector<int>>& trust) {
        vector<int> count (n + 1);

        for (auto& vec : trust) {
            int u = vec[0];
            int v = vec[1];

            count[u] --;
            count[v] ++;
        }

        for (int i = 1; i <= n; i++) {
            if (count[i] == n - 1) {
                return i;
            }
        }
        return -1;
    }
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // return solve_1(n, trust);

        // return solve_2(n, trust);

        return solve_3(n, trust);
    }
};