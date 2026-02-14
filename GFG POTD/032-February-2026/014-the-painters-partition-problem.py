# https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1/




class Solution:
    def minTime (self, arr, k):
        low, high = min(arr), sum(arr)
        ans = high
        while low <= high:
            mid = low + (high - low) // 2
            if (self.canPaint(arr, k, mid)):
                ans = mid
                high = mid - 1
            else:
                low = mid + 1
        return ans
        
    def canPaint(self, arr, k, tar):
        painter = total = 0
        for x in arr:
            if x > tar:
                return False
                
            total += x
            if total == tar:
                total = 0
                painter += 1
            elif total > tar:
                total = x
                painter += 1
        
        if total > 0:
            painter += 1
            
        return painter <= k