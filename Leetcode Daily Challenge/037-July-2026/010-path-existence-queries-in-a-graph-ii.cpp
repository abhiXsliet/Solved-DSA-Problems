// https://leetcode.com/problems/path-existence-queries-in-a-graph-ii/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    int rows, cols;
    vector<vector<int>> farthestTable;
    typedef pair<int, int> P;
    int customBS(vector<P> &arr, int target) {
        int low = 0, high = arr.size() - 1;
        int ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid].first <= target) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<P> arr(n);
        for (int i = 0; i < n; i ++) {
            int val  = nums[i];
            int node = i;
            arr[i] = {val, node};
        }

        sort(begin(arr), end(arr));

        vector<int> nodeToIdx(n);
        for (int i = 0; i < n; i ++) {
            int node = arr[i].second;
            nodeToIdx[node] = i;
        }

        rows = n;
        cols = log2(n) + 1;
        farthestTable.resize(rows, vector<int>(cols));

        // fill the first col of the farthestTable
        for (int i = 0; i < n; i ++) {
            int farthestIdxOneHop = customBS(arr, arr[i].first + maxDiff);
            farthestTable[i][0] = farthestIdxOneHop;
        }

        // fill the remaining cols of the farthestTable
        for (int j = 1; j < cols; j ++) {
            for (int i = 0; i < n; i ++) {
                farthestTable[i][j] = farthestTable[farthestTable[i][j - 1]][j - 1];   
            }
        }

        vector<int> result;

        for (auto q : queries) {
            int u = q[0], v = q[1];
            int a = nodeToIdx[u];
            int b = nodeToIdx[v];
            if (a == b) {
                result.push_back(0);
                continue;
            }

            if (a > b) swap(a, b);

            int curr = a, jump = 0;

            for (int j = cols - 1; j >= 0; j --) {
                if (farthestTable[curr][j] < b) {
                    curr = farthestTable[curr][j];
                    jump += (1 << j);   
                }
            }

            if (farthestTable[curr][0] >= b) {
                result.push_back(jump + 1);
            } else {
                result.push_back(-1);
            }
        }

        return result;
    }
};