// https://leetcode.com/problems/most-beautiful-item-for-each-query/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:    
    int getMaxBeauty(int price, vector<vector<int>>& items, int m) {
        int low = 0, high = m - 1, beauty = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (items[mid][0] <= price) {
                beauty = items[mid][1];
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return beauty;
    }
public:
    // TC : O(M*log(M) + N*log(M))
    // SC : O(1)
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int m = items.size(), n = queries.size();
        sort(begin(items), end(items));
        int maxBeauty = items[0][1];
        for (int i = 1; i < m; i ++) {  // update max beauty till each index
            items[i][1] = max(maxBeauty, items[i][1]);
            maxBeauty   = max(maxBeauty, items[i][1]);
        }

        vector<int> result(n, 0);
        for (int i = 0; i < n; i ++) {
            int maxBeauty = getMaxBeauty(queries[i], items, m);
            result[i]     = maxBeauty;
        }
        return result;
    }
};