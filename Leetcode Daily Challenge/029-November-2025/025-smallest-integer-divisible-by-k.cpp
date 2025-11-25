// https://leetcode.com/problems/smallest-integer-divisible-by-k/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if(K == 1)
            return 1;
        if(K%2 == 0 || K%5 == 0)
            return -1;
        
        int remain = 0;
        for(int i = 1; i <= K; i ++) {
            remain = (remain*10 + 1) % K; 
            if(remain == 0)
                return i;
        }

        return -1;
    }
};