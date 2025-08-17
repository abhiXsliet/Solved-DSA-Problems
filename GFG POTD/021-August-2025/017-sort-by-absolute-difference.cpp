// https://www.geeksforgeeks.org/problems/sort-by-absolute-difference-1587115621/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N * log(N))
    // SC : O(1)
    void rearrange(vector<int> &arr, int x) {
        stable_sort(begin(arr), end(arr), [&](int a, int b) {
            return abs(a - x) < abs(b - x);
        });
    }
};