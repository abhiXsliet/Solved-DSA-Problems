// https://leetcode.com/problems/water-bottles-ii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;
    
    // TC : O(numBottles)
    // SC : O(1)
    int approach_1(int numBottles, int numExchange) {
        int drink       = numBottles;
        ll emptyBottles = numBottles;

        while(emptyBottles) {
            emptyBottles = emptyBottles - numExchange;
            if (emptyBottles >= 0) {
                numExchange  += 1;
                drink        += 1;
                emptyBottles += 1;
            }
            else break;
        }

        return drink;
    }
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        return approach_1(numBottles, numExchange);
    }
};