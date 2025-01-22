// https://leetcode.com/problems/max-chunks-to-make-sorted/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N)
    int approach_1(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefix(n, arr[0]);      // to store the max element till index i
        vector<int> suffix(n, arr[n - 1]);  // to store the min elmeent till index i

        for (int i = 1; i < n; i ++) {
            prefix[i] = max(prefix[i - 1], arr[i]);
            suffix[n - i - 1] = min(suffix[n - i], arr[n - i - 1]);
        }

        int maxChunks = 0;
        for (int i = 0; i < n; i ++) {
            int prev_max = i > 0 ? prefix[i - 1] : -1;  // phle (i - 1) ka maximum element
            int forw_min = suffix[i];                   // baad (i) ka minimum element
            if (prev_max < forw_min)
                maxChunks += 1;
        }
        return maxChunks;
    }

    // TC : O(N)
    // SC : O(N)
    int approach_2(vector<int>& arr) {
        int n = arr.size();
        vector<int> pref(n, arr[0]);
        for (int i = 1; i < n; i ++) {
            pref[i] = max(pref[i - 1], arr[i]);
        }

        int maxChunks = 0;
        for (int i = 0; i < n; i ++) {
            if (pref[i] == i) {
                maxChunks ++;
            }
        }
        return maxChunks;
    }

    // TC : O(N)
    // SC : O(1)
    int approach_3(vector<int>& arr) {
        int n = arr.size();
        int pref = arr[0];
        int maxChunks = 0;
        for (int i = 0; i < n; i ++) {
            if (i > 0) pref = max(pref, arr[i]);
            if (pref == i) {
                maxChunks ++;
            }
        }
        return maxChunks;
    }
public:
    int maxChunksToSorted(vector<int>& arr) {
        return approach_1(arr);

        // return approach_2(arr);

        // return approach_3(arr);
    }
};