# https://leetcode.com/problems/transformed-array/




from typing import List

class Solution:
    def constructTransformedArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        result = [0] * n
        for i in range(n):
            val = nums[i]
            if nums[i] > 0:
                val = nums[(i + nums[i]) % n] 
            elif nums[i] < 0:
                val = nums[(i - (abs(nums[i]) % n) + n) % n]
            result[i] = val

        return result
            
        