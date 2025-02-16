// https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool solve(int idx, vector<int> &res, int n, vector<bool> &visited) {
        if (idx == res.size()) return true;
        if (res[idx] != 0) {
            return solve(idx + 1, res, n, visited);
        }

        for (int i = n; i >= 1; i --) {
            if (visited[i - 1]) continue;
            visited[i - 1] = 1;
            res[idx] = i; 
            if (i == 1) {
                if (solve(idx + 1, res, n, visited))
                    return true;
            } else if (i + idx < res.size() && res[idx + i] == 0) {
                res[idx + i] = i;
                if (solve(idx + 1, res, n, visited))
                    return true;
                res[idx + i] = 0;
            }
            visited[i - 1] = 0;
            res[idx] = 0;
        }
        return false;
    }
public:
    // TC : O(N!)
    // SC : O(N)
    vector<int> constructDistancedSequence(int n) {
        int size = 1 + (2*(n - 1));
        vector<int> result(size, 0);
        vector<bool> visited(n, 0);
        solve(0, result, n, visited);
        return result;
    }
};