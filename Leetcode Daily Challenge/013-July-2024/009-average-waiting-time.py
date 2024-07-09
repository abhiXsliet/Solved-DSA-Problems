# https://leetcode.com/problems/average-waiting-time/



class Solution:
    def averageWaitingTime(self, customers):
        """
        :type customers: List[List[int]]
        :rtype: float
        """
        n = len(customers)

        totalWaitTime = 0
        currTime = 0

        for vec in customers:
            arrivalTime = vec[0]
            cookTime = vec[1]

            if currTime < arrivalTime:
                currTime = arrivalTime

            waitTime = currTime + cookTime - arrivalTime
            totalWaitTime += waitTime
            currTime += cookTime

        return totalWaitTime / float(n)