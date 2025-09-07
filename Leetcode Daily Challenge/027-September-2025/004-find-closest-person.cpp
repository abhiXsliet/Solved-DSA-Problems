// https://leetcode.com/problems/find-closest-person/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findClosest(int x, int y, int z) {
        int d1 = abs(z - x);
        int d2 = abs(z - y);

        return (d1 < d2) ? 1 : ((d2 < d1) ? 2 : 0);
    }
};