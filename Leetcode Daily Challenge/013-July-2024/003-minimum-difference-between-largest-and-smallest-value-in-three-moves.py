# https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/



from collections import List 

class Solution:
    def minDifference(self, nums: List[int]) -> int:
                return self.approach_1(nums)
    
    # TC : O(N*log(N))
    # SC : O(1)
    def approach_1(self, nums):
        nums.sort()
        n = len(nums)
        if n <= 3:
            return 0
        result = float('inf')
        result = min(result, nums[n - 4] - nums[0])
        result = min(result, nums[n - 3] - nums[1])
        result = min(result, nums[n - 2] - nums[2])
        result = min(result, nums[n - 1] - nums[3])
        return result