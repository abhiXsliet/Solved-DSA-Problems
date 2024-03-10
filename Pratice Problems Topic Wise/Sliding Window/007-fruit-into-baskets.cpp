// https://leetcode.com/problems/fruit-into-baskets/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        unordered_map<int, int> basket;
        int i = 0, j = 0;
        int maxFruitsCnt = 0;

        while (j < n) {
            basket[fruits[j]] ++;

            if (basket.size() > 2) {
                basket[fruits[i]] --;
                if (basket[fruits[i]] == 0)
                    basket.erase(fruits[i]);
                i ++;
            }
            int cnt = accumulate(begin(basket), end(basket), 0, [&](int sum , pair<int, int> it) {
                return sum + it.second;
            });
            maxFruitsCnt = max(maxFruitsCnt, cnt);
            j++;
        }
        return maxFruitsCnt;
    }
};