// https://leetcode.com/problems/interval-list-intersections/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N + M) Where N = Length of firstList & M = Length Of secondList
    // SC : O(K)     Where K = No. Of Intersections which is min(N, M)
    vector<vector<int>> solve_approach_1(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> result;

        int i = 0, j = 0;
        int n = firstList.size();
        int m = secondList.size();

        if (n == 0 || m == 0) return {};

        while (i < n && j < m) {
            int firstStart  = firstList[i][0];
            int firstEnd    = firstList[i][1];

            int secondStart  = secondList[j][0];
            int secondEnd    = secondList[j][1];

            if (firstEnd < secondEnd && secondStart <= firstEnd) {
                int val1 = max(firstStart, secondStart);
                int val2 = min(firstEnd, secondEnd);

                result.push_back({val1, val2});
                i ++;
            }
            else if (firstEnd < secondEnd && secondStart > firstEnd) i ++;

            if (firstEnd >= secondEnd && firstStart <= secondEnd) {
                int val1 = max(firstStart, secondStart);
                int val2 = min(firstEnd, secondEnd);
                
                result.push_back({val1, val2});
                j ++;
            }
            else if (firstEnd >= secondEnd && firstStart > secondEnd) j ++;
        }

        return result;
    }
    
    // TC : O(N + M) Where N = Length of firstList & M = Length Of secondList
    // SC : O(K)     Where K = No. Of Intersections which is min(N, M)
    vector<vector<int>> solve_approach_2(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> result;

        int n = firstList.size();
        int m = secondList.size();
        int i = 0, j = 0;

        while (i < n && j < m) {

            int low  = max(firstList[i][0], secondList[j][0]);
            int high = min(firstList[i][1], secondList[j][1]);

            if (high - low >= 0) {
                result.push_back({low, high});
            }

            high == firstList[i][1] ? i ++ : j ++;
        }

        return result;
    }
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        // return solve_approach_1(firstList, secondList);

        return solve_approach_2(firstList, secondList);
    }
};