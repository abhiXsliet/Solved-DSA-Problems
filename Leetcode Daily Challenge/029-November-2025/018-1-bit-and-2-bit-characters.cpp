// https://leetcode.com/problems/1-bit-and-2-bit-characters/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i = 0;

        while(i < n-1) {
            i += (bits[i] == 1) ? 2 : 1;
        }

        return i == n-1;
    }
};