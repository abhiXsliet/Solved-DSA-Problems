// https://www.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1



#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(2^n)
    // SC : O(n) recursive stack space
    int towerOfHanoi(int n, int from, int to, int aux) {
        if (n == 1) return 1;
        
        int cnt = 0;
        cnt += towerOfHanoi(n - 1, from, aux, to);
        
        // move one remaining disk to the dest by cnt=1
        cnt += 1;
        
        cnt += towerOfHanoi(n - 1, to, aux, from);
        
        return cnt;
    }
};