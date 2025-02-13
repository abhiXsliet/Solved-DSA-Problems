// https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:   
        // TC : O(Q)
        // SC : O(Q)
        vector<int> approach_1(int limit, vector<vector<int>>& queries) {
            int q = queries.size();
            unordered_map<int, int> ballsColored;  // to track balls and their color
            unordered_map<int, int> colorsCount;   // to track the distinct color count
            vector<int> result(q);
            for (int i = 0; i < q; i ++) {
                int x = queries[i][0], y = queries[i][1];
                if (ballsColored.count(x)) {
                    int prevColor = ballsColored[x];
                    ballsColored[x] = y;    // replace the prev color with current color for ball x
                    colorsCount[prevColor] --;
                    if (colorsCount[prevColor] == 0) 
                        colorsCount.erase(prevColor);
                }
                ballsColored[x] = y;
                colorsCount[y] ++;
                result[i] = colorsCount.size();
            }
            return result;
        }
    public:
        vector<int> queryResults(int limit, vector<vector<int>>& queries) {
            return approach_1(limit, queries);
        }
    };