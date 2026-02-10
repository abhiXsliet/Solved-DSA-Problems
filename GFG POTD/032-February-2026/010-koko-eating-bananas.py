# https://www.geeksforgeeks.org/problems/koko-eating-bananas/1/




class Solution:
    def kokoEat(self, arr, k):
        low, high = 0, max(arr)
        ans = high
        while low <= high:
            mid = low + (high - low) // 2
            if self.isPossible(arr, mid, k):
                ans = mid
                high = mid - 1
            else:
                low = mid + 1
                
        return ans
        
    def isPossible(self, arr, tar, k):
        if tar == 0:
            return False
        cntHrs = 0
        for val in arr:
            cntHrs += val // tar
            if val % tar != 0:
                cntHrs += 1
        return cntHrs <= k