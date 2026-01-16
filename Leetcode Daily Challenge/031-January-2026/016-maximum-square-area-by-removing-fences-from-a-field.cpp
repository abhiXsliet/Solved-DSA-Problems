// https://leetcode.com/problems/maximum-square-area-by-removing-fences-from-a-field/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int M = 1e9 + 7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        unordered_set<int> vHeights;
        for (int i = 0; i < vFences.size(); i ++) {
            for (int j = i + 1; j < vFences.size(); j ++) {
                int width = abs(vFences[i] - vFences[j]);
                vHeights.insert(width);
            }
        }

        long maxSide = 0;
        for (int i = 0; i < hFences.size(); i ++) {
            for (int j = i + 1; j < hFences.size(); j ++) {
                long length = abs(hFences[i] - hFences[j]);
                if (vHeights.count(length)) {
                    maxSide = max(maxSide, length);
                }
            }
        }

        return (int)maxSide == 0 ? -1 : (maxSide * maxSide) % M;
    }
};