// https://www.geeksforgeeks.org/problems/minimum-sprinklers/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minMen(vector<int>& arr) {
        int n = arr.size();
        vector<int> maxReach(n, -1);
        
        for (int i = 0; i < n; i ++) {
            if (arr[i] == -1) continue;
            int L = max(0, i - arr[i]);
            int R = min(n - 1, i + arr[i]);
            maxReach[L] = max(maxReach[L], R);
        }
        
        int covered  = -1;
        int farthest = -1;
        int peoples  = 0;
        
        for (int i = 0; i < n; i ++) {
            farthest = max(farthest, maxReach[i]);

            // gap detected
            if (i > farthest) return -1;    
            
            if (i > covered) {
                covered = farthest;
                peoples += 1;
            }
            
            // covered entire working day from 0 to (n - 1)
            if (covered >= n - 1) break;
        }
        
        return peoples;
    }
}; 