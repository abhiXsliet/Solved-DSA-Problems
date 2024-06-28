// https://leetcode.com/problems/maximum-total-importance-of-roads/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;

    // TC : O(N*log(N))
    // SC : O(N)
    ll approach_1(int n, vector<vector<int>>& roads) {
        vector<int> inDegree(n, 0);
        for (vector<int>& road : roads) {
            int a = road[0];
            int b = road[1];
            inDegree[a] ++;
            inDegree[b] ++;
        }
        
        vector<pair<int, int>> store(n, {0, 0});
        for (int i = 0; i < n; i ++) {
            store[i] = {inDegree[i], i};
        }

        // sorting based on the highest indegree of roads
        sort(rbegin(store), rend(store));
        
        int values = n;
        
        // Assigning value based on highest indegree of roads
        for (int i = 0; i < n; i ++) {
            int idx       = store[i].second; // index of highest indegree of road
            inDegree[idx] = values --;
        }

        ll importance = 0;
        for (vector<int>& road : roads) {
            importance += inDegree[road[0]];
            importance += inDegree[road[1]];
        }
        return importance;
    }

    // TC : O(N*log(N))
    // SC : O(N)
    ll approach_2(int n, vector<vector<int>>& roads) {
        vector<int> inDegree(n, 0);
        for (vector<int>& road : roads) {
            int a = road[0];
            int b = road[1];
            inDegree[a] ++;
            inDegree[b] ++;
        }
       
        // sorting based on the highest indegree of roads
        sort(begin(inDegree), end(inDegree));

        ll importance = 0;
        for (int val = 1; val <= n; val ++) {
            importance += (ll)inDegree[val - 1] * val;
        }
        return importance;
    }
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        // return approach_1(n, roads);

        return approach_2(n, roads);
    }
};