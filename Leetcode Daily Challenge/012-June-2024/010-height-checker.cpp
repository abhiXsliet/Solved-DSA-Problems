// https://leetcode.com/problems/height-checker/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(Nlog(N)) Where N = Size of Heights
    // SC : O(N)
    int approach_1(vector<int>& heights) {
        int n = heights.size();
        vector<int> expected = heights;
        sort(begin(expected), end(expected));
        int cnt = 0;
        for (int i = 0; i < n; i ++) {
            if (heights[i] != expected[i]) cnt ++;
        }
        return cnt;
    }

    // TC : O(N + K) Where N = Size of Heights Array
    // SC : O(N + K) Where K = Range of the elements
    int approach_2(vector<int>& heights) {
        int n = heights.size();
        int maxi = *max_element(begin(heights), end(heights));
        
        vector<int> count(maxi + 1, 0);
        
        for (int& h : heights) {
            count[h] ++;
        }

        int idx = 0, res = 0;
        for (int i = 0; i < n; i ++) {

            while (count[idx] == 0) idx ++;

            if (heights[i] != idx) {
                res ++;
                count[idx] --;
            } else {
                count[idx] --;
            }
        }
        return res;
    }
public:
    int heightChecker(vector<int>& heights) {
        // return approach_1(heights);

        return approach_2(heights); // counting sort
    }
};