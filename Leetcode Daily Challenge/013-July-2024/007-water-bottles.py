# https://leetcode.com/problems/water-bottles/



class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        # return self.approach_1(numBottles, numExchange)
        # return self.approach_2(numBottles, numExchange)
        # return self.way_2(numBottles, numExchange)
        return self.approach_3(numBottles, numExchange)

    # TC : O(N) Where N = numBottles
    # SC : O(1)
    def approach_1(self, numBottles, numExchange):
        consumed = 0
        while numBottles >= numExchange:
            consumed   += numExchange
            numBottles -= numExchange
            numBottles += 1  # 1 full bottle on every numExchange empty bottles
        return consumed + numBottles

    # TC : O(log(numBottles) with base numExchange)
    # SC : O(1)
    def approach_2(self, numBottles, numExchange):
        if numBottles < numExchange:
            return numBottles

        drink     = numBottles
        newDrink  = 0
        remaining = 0

        while (numBottles // numExchange) > 0:
            remaining  += numBottles % numExchange
            numBottles  = numBottles // numExchange
            newDrink   += numBottles
        
        while ((remaining + numBottles) // numExchange) > 0:
            remaining  = (remaining + numBottles) % numExchange
            numBottles = (remaining + numBottles) // numExchange
            newDrink  += 1
        return drink + newDrink

    # TC : O(log(numBottles) with base numExchange)
    # SC : O(1)
    def way_2(self, numBottles, numExchange):
        consumed     = numBottles
        emptyBottles = numBottles

        while emptyBottles >= numExchange:
            newFullBottles = emptyBottles // numExchange
            remainBottles  = emptyBottles % numExchange
            consumed          += newFullBottles
            # empty bottles = newFullBottles after exchange + previous unconsumed bottles
            emptyBottles       = newFullBottles + remainBottles

        return consumed

    # TC : O(1)
    # SC : O(1)
    def approach_3(self, numBottles, numExchange):
        # Initial consumption equals the number of bottles (numBottles).
        # Each time we exchange numExchange bottles, we receive one full bottle in return.
        # This means we effectively lose only (numExchange - 1) bottles per exchange, as we gain one full bottle as a bonus.
        # Eventually, we will be left with fewer bottles than the required number for an exchange (numExchange).
        
        effectiveExtraBottles = (numBottles - 1) // (numExchange - 1)
        return numBottles + effectiveExtraBottles