# https://leetcode.com/problems/minimum-removals-to-balance-array/




from typing import List

class Solution:
    def minRemoval(self, nums: List[int], k: int) -> int:
        n = len(nums)
        nums.sort()
        i = 0
        j = 0
        largestBalancedLen = 0
        while j < n:
            while i < j and nums[i] * k < nums[j]:
                i += 1
            largestBalancedLen = max(largestBalancedLen, j - i + 1)
            j += 1
            
        return (n - largestBalancedLen)