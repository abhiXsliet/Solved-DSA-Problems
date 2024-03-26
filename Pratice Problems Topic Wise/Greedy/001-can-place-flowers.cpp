// https://leetcode.com/problems/can-place-flowers/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(M) Where M is the size of the flowerbed
    // SC : O(1) 
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        for (int i = 0; i < m; i++) {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == m - 1 || flowerbed[i + 1] == 0)) {
                flowerbed[i] = 1;
                n--;
            }
        }
        return n <= 0;
    }
};
