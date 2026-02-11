# https://www.geeksforgeeks.org/problems/equalize-the-towers2804/1/




class Solution:
    def minCost(self, heights, cost):
        low, high = min(heights), max(heights)
        ans = high
        while low < high:
            mid = low + (high - low) // 2
            v1 = self.getCost(heights, cost, mid)
            v2 = self.getCost(heights, cost, mid + 1)
            if v1 <= v2:
                ans = mid
                high = mid
            else:
                low = mid + 1
        return self.getCost(heights, cost, ans)
        
    def getCost(self, heights, cost, tar):
        totalCost = 0
        for i in range(0, len(heights)):
            totalCost += abs(heights[i] - tar) * cost[i]
        return totalCost