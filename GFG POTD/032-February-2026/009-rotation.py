# https://www.geeksforgeeks.org/problems/rotation4723/1/



class Solution:
    def findKRotation(self, arr):
        n = len(arr)
        for i in range(1, n):
            if arr[i - 1] > arr[i]:
                return i
        
        return 0