// https://leetcode.com/problems/lexicographically-smallest-equivalent-string/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    char dfsMinChar(unordered_map<char, vector<char>> &adj, vector<bool> &visited, char &currCh) {
        visited[currCh - 'a'] = 1;
        char minChar = currCh;
        for (char &nbr : adj[currCh]) {
            if (!visited[nbr - 'a']) {
                minChar = min(minChar, dfsMinChar(adj, visited, nbr));
            }
        }
        return minChar;
    }

    // TC : O(M * N)
    // SC : O(N)
    string approach_1(string s1, string s2, string baseStr) {
        int n = s1.length();
        int m = baseStr.length();

        unordered_map<char, vector<char>> adj;
        for (int i = 0; i < n; i ++) {
            adj[s1[i]].push_back(s2[i]);
            adj[s2[i]].push_back(s1[i]);
        }

        string result;
        for (int i = 0; i < m; i ++) {
            char minChar = baseStr[i];
            
            vector<bool> visited(26, 0);
            minChar = min(minChar, dfsMinChar(adj, visited, minChar));
            result += minChar;
        }
        return result;
    }
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        return approach_1(s1, s2, baseStr);
    }
};