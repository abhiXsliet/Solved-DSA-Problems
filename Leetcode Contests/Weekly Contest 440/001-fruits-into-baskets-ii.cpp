// https://leetcode.com/problems/fruits-into-baskets-ii/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<bool> marked(n, false);
        for (int &f : fruits) {
            for (int i = 0; i < n; i ++) {
                if (!marked[i] && baskets[i] >= f) {
                    marked[i] = true;
                    break;
                }
            }
        }
        int unplaced = 0;
        for (int i = 0; i < n; i++) {
            if (!marked[i]) {
                unplaced += 1;
            }
        }
        return unplaced;
    }
};