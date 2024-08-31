// https://leetcode.com/problems/2-keys-keyboard/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int t[1001][1001];
    int solve(int currCountA, int pasteCountA, int n) {
        if(currCountA == n) {
            return 0;
        }

        if(currCountA > n) {
            return 1000;
        }


        if(t[currCountA][pasteCountA] != -1) {
            return t[currCountA][pasteCountA];
        }

        int copyPaste = 1 + 1 + solve(currCountA + currCountA, currCountA, n);

        int paste     = 1 + solve(currCountA + pasteCountA, pasteCountA, n);

        return t[currCountA][pasteCountA] = min(copyPaste, paste);
    }

    int minSteps(int n) {
        if(n == 1)
            return 0; //We already have 1 A
        
        memset(t, -1, sizeof(t));

        //We have to start with a copy, hence 1 + 
        return 1 + solve(1, 1, n);
    }
};

