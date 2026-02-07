# https://www.geeksforgeeks.org/problems/max-sum-in-the-configuration/1/




class Solution:
    def maxSum(self, arr): 
        n = len(arr)
        
        currRotation = totalSum = 0
        
        for i in range(n):
            currRotation += (i * arr[i])
            totalSum += arr[i]
            
        maxVal = currRotation
        
        for i in range(1, n):
            nextRotation = (currRotation + totalSum - (n * arr[n - i]))
            maxVal = max(maxVal, nextRotation)
            currRotation = nextRotation
            
        return maxVal