// https://leetcode.com/problems/fruit-into-baskets/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(1) only store at max 2-elements
    int approach_1(vector<int> &fruits) {
        int n = fruits.size();
        unordered_map<int, int> mpp;
        int i = 0, j = 0, maxFruit = 0;
        while (j < n) {
            mpp[fruits[j]] ++;
            while (mpp.size() > 2) {
                mpp[fruits[i]] --;
                if (!mpp[fruits[i]]) mpp.erase(fruits[i]);
                i ++;
            }
            maxFruit = max(maxFruit, j - i + 1);
            j ++;
        }
        return maxFruit;
    }
public:
    int totalFruit(vector<int>& fruits) {
        return approach_1(fruits);
    }
};