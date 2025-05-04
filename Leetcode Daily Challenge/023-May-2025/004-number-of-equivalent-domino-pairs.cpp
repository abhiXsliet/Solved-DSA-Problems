// https://leetcode.com/problems/number-of-equivalent-domino-pairs/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N * log(N))
    // SC : O(N)
    int approach_1(vector<vector<int>> &dom) {
        int n = dom.size();
        map<vector<int>, int> mpp;

        int result = 0;
        for (vector<int> &d : dom) {
            if (d[0] > d[1]) swap(d[0], d[1]);
            mpp[d] ++;
            if (mpp[d] > 1) {
                result += (mpp[d] - 1);
            }
        }
        return result;
    }

    // TC : O(N)
    // SC : O(1)
    int approach_2(vector<vector<int>> &dom) {
        int n = dom.size();
        vector<int> freq(100, 0);
        int result = 0;
        for (vector<int> &d : dom) {
            if (d[0] > d[1]) swap(d[0], d[1]);
            int number = (d[0] * 10 + d[1]);
            freq[number] ++;
            if (freq[number] > 1) {
                result += (freq[number] - 1);
            }
        }
        return result;
    }
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        // return approach_1(dominoes);
        return approach_2(dominoes);     // const. space : convert each dominoes into a constant no.
    }
};