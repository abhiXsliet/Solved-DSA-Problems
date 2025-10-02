// https://leetcode.com/problems/water-bottles/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N) Where N = numBottles
    // SC : O(1)
    int approach_1(int numBottles, int numExchange) {
        int consumed = 0;
        while (numBottles >= numExchange) {
            consumed   += numExchange;
            numBottles -= numExchange;
            numBottles += 1;  // 1 full bottle on every numExchange empty bottles
        }
        return consumed + numBottles;
    }

    // TC : O(log(numBottles) with base numExchange)
    // SC : O(1)
    int approach_2(int numBottles, int numExchange) {
        if (numBottles < numExchange) 
            return numBottles;

        int drink     = numBottles;
        int newDrink  = 0;
        int remaining = 0;

        while (numBottles / numExchange > 0) {
            remaining  += numBottles % numExchange;
            numBottles /= numExchange;
            newDrink   += numBottles;
        }
        
        while ((remaining + numBottles) / numExchange > 0) {
            remaining  = (remaining + numBottles) % numExchange;
            numBottles = (remaining + numBottles) / numExchange;
            newDrink ++;
        }
        return drink + newDrink;
    }

    // TC : O(log(numBottles) with base numExchange)
    // SC : O(1)
    int way_2(int numBottles, int numExchange) {
        int consumed     = numBottles;
        int emptyBottles = numBottles;

        while (emptyBottles >= numExchange) {
            int newFullBottles = emptyBottles / numExchange;
            int remainBottles  = emptyBottles % numExchange;

            consumed          += newFullBottles;

            // empty bottles = newFullBottles after exchange + previous unconsumed bottles
            emptyBottles       = newFullBottles + remainBottles;
        }

        return consumed;
    }

    // TC : O(1)
    // SC : O(1)
    int approach_3(int numBottles, int numExchange) {
        // Initial consumption equals the number of bottles (numBottles).
        // Each time we exchange numExchange bottles, we receive one full bottle in return.
        // This means we effectively lose only (numExchange - 1) bottles per exchange, as we gain one full bottle as a bonus.
        // Eventually, we will be left with fewer bottles than the required number for an exchange (numExchange).
        
        int effectiveExtraBottles = (numBottles - 1) / (numExchange - 1);
        return numBottles + effectiveExtraBottles;
    }
public:
    int numWaterBottles(int numBottles, int numExchange) {
        // return approach_1(numBottles, numExchange);  // BRUTE

        // return approach_2(numBottles, numExchange);  // Better

        // return way_2(numBottles, numExchange);       // Better : Different writting style

        return approach_3(numBottles, numExchange);
    }
};