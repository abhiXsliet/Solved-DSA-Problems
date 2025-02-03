// https://leetcode.com/problems/jump-game-iv/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int BFS(vector<bool>& vis, unordered_map<int, vector<int>>& mpp, vector<int>& arr) {
        int n = arr.size();
        queue<int> q;
        q.push(0);
        int minStep = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size --) {
                int fNode = q.front();
                q.pop();
                
                if (vis[fNode]) continue;
                vis[fNode] = 1;

                if (fNode - 1 >= 0) {
                    q.push(fNode - 1);
                }

                if (fNode + 1 < n) {
                    q.push(fNode + 1);
                    if (fNode + 1 == n - 1)
                        return minStep + 1;
                }

                for (auto& it : mpp[arr[fNode]]) {
                    if (it == fNode) continue;
                    if (!vis[it]) {
                        q.push(it);
                        if (it == n - 1) return minStep + 1;
                    }
                }
                mpp.erase(arr[fNode]);
            }
            minStep ++;
        }
        return minStep;
    }
public:
    // TC : O(N)
    // SC : O(N)
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;
        unordered_map<int, vector<int>> mpp;
        for (int i = 0; i < n; i ++) {
            mpp[arr[i]].push_back(i);
        }
        vector<bool> visited(n, 0);
        return BFS(visited, mpp, arr);
    }
};