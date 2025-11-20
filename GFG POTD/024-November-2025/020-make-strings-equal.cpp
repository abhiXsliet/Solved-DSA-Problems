// https://www.geeksforgeeks.org/problems/make-strings-equal--150209/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(string &s, string &t, vector<vector<char>> &transform,
                vector<int> &cost) {
        
        int n = s.size();
        if (t.size() != n) return -1;

        const long long INF = 1e15;

        // 26x26 matrix
        vector<vector<long long>> dist(26, vector<long long>(26, INF));

        for(int i = 0; i < 26; i++) dist[i][i] = 0;

        // load direct transforms
        for (int i = 0; i < transform.size(); i++) {
            int u = transform[i][0] - 'a';
            int v = transform[i][1] - 'a';
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        // Floyd Warshall
        for (int k = 0; k < 26; k++)
            for (int i = 0; i < 26; i++)
                for (int j = 0; j < 26; j++)
                    if (dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        long long answer = 0;

        for (int i = 0; i < n; i++) {
            int a = s[i] - 'a';
            int b = t[i] - 'a';

            long long best = INF;

            // try converting both to some common character x
            for (int x = 0; x < 26; x++) {
                if (dist[a][x] < INF && dist[b][x] < INF)
                    best = min(best, dist[a][x] + dist[b][x]);
            }

            if (best == INF) return -1;
            answer += best;
        }

        return answer;
    }
};