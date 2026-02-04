# https://www.geeksforgeeks.org/problems/last-moment-before-all-ants-fall-out-of-a-plank/1/




class Solution:
    def getLastMoment(self, n, left, right):
        mini = 0
        maxi = 0
        for i in range(n):
            if i < len(left):
                maxi = max(maxi, left[i])
            if i < len(right):
                mini = max(mini, n - right[i])
                
        return max(mini, maxi)