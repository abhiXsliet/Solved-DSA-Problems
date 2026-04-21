// https://www.geeksforgeeks.org/problems/two-water-jug-problem3402/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    typedef long long ll;
    
    ll GCD(int a, int b) {
        return b == 0 ? a : GCD(b, a % b);
    }
    
    int pour (int srcCap, int destCap, int d) {
        int from = srcCap;
        int to = 0;
        int steps = 1;   // for first time filling
        
        while (from != d && to != d) {
            int temp = min(from, destCap - to);     // empty space 
            
            to += temp;
            from -= temp;
            steps += 1;
            
            if (from == d || to == d) break;
            
            if (from == 0) {
                from = srcCap;
                steps += 1;
            }
            
            if (to == destCap) {
                to = 0;
                steps += 1;
            }
        }
        return steps;
    }
  public:
    int minSteps(int m, int n, int d) {
        if (d > max(m, n)) return -1;
        
        if (d % GCD(m, n)) return -1;
        
        return min(pour(m, n, d), pour(n, m, d));
    }
};