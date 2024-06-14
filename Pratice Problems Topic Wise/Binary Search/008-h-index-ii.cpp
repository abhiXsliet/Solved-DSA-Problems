// https://leetcode.com/problems/h-index-ii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N*log(N))
    // SC : O(1)
    int approach_1(vector<int>& citations) {
        int n = citations.size();
        sort(begin(citations), end(citations), greater<int>());
        int low = 0, high = n - 1, ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // If there are at least (mid + 1) papers with at least (mid + 1) citations
            if (citations[mid] >= mid + 1) {
                ans = mid + 1;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    // TC : O(log(N))
    // SC : O(1)
    int approach_2(vector<int>& citations) {
        int n = citations.size();
        int low = 0, high = n - 1, ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // Check if there are at least (mid + 1) papers with at least (mid + 1) citations
            if (citations[mid] >= n - mid) {
                ans  = n - mid;
                high = mid - 1;
            } else {
                low  = mid + 1;
            }
        }
        return ans;
    }
public:
    int hIndex(vector<int>& citations) {
        // return approach_1(citations);

        return approach_2(citations);
    }
};