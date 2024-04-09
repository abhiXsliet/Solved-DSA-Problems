// https://leetcode.com/problems/minimize-manhattan-distances/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;
    
    // find manHattan Distance between two points
    int manHattanDist(vector<vector<int>>& points, int i, int j) {
        return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
    }

    // TC : O(N)
    // SC : O(1)
    // find maxManHattan distance in a given vector of points after removing indexToRemove point
    pair<int, int> maxManHattanDist(vector<vector<int>>& points, int indexToRemove) {
        int n = points.size();

        int maxSum  = INT_MIN;
        int minSum  = INT_MAX;
        int maxDiff = INT_MIN;
        int minDiff = INT_MAX;
        int maxSumIdx, minSumIdx, maxDiffIdx, minDiffIdx;

        for (int i = 0; i < n; i++) {
            // check for point to remove
            if (i != indexToRemove) {  
                // find sum and diff of this point
                int sum  = points[i][0] + points[i][1];
                int diff = points[i][0] - points[i][1];

                if (maxSum < sum) {
                    maxSum    = sum;
                    maxSumIdx = i;
                }
                if (minSum > sum) {
                    minSum    = sum;
                    minSumIdx = i;
                }
                if (maxDiff < diff) {
                    maxDiff    = diff;
                    maxDiffIdx = i;
                }
                if (minDiff > diff) {
                    minDiff    = diff;
                    minDiffIdx = i;
                }
            }
        }

        // Rearrange eqn: Max(|xi - xj| + |yi - yj|) = max(|si - sj| + |di - dj|)
        // Find max dist is due to sums or diffs and return to indexes accordingly
        if ((maxSum - minSum) >= (maxDiff - minDiff))
            return {maxSumIdx, minSumIdx};
        return {maxDiffIdx, minDiffIdx};
    }

    // TC : O(N*log(N)) Where N = No. of points
    // SC : O(N)    
    int approach_1(vector<vector<int>>& points) {
        // mst1, mst2 stores the sum & diff of each points respectively
        multiset<ll> mst1, mst2;
        for (auto& p : points) {
            mst1.insert(p[0] + p[1]);
            mst2.insert(p[0] - p[1]);
        }

        ll maxManHattanDist = LONG_MAX;

        // processing for every point by removing and adding each point
        for (auto& p : points) {
            int sum  = p[0] + p[1];
            int diff = p[0] - p[1];

            // remove ith points sum and diff from the mst1, mst2
            mst1.erase(mst1.lower_bound(sum));  // pass index of element to erase
            mst2.erase(mst2.lower_bound(diff));

            // find maxManHattanDistance after removing ith point
            maxManHattanDist = min(maxManHattanDist, 
                                    max((*mst1.rbegin() - *mst1.begin()), (*mst2.rbegin() - *mst2.begin())) );

            // add previous removed point back to the msts
            mst1.insert(sum);
            mst2.insert(diff);
        }

        return maxManHattanDist;
    }

    // TC : O(N) Where N = No. of points
    // SC : O(1)    
    int approach_2(vector<vector<int>>& points) {
        // get the indices of two farthest points
        auto [mi, mj]   = maxManHattanDist(points, -1);
        cout << mi << " " << mj << endl;
        // remove 1st farthest point and get indices of two new farthest point
        auto [mi1, mj1] = maxManHattanDist(points, mi); // remove mi

        // remove 2nd farthest point and get indices of two new farthest point
        auto [mi2, mj2] = maxManHattanDist(points, mj); // remove mj

        return min(manHattanDist(points, mi1, mj1), manHattanDist(points, mi2, mj2));
    }
public:
    int minimumDistance(vector<vector<int>>& points) {
        // return approach_1(points);  // MULTISET

        return approach_2(points);      // MATH
    }
};