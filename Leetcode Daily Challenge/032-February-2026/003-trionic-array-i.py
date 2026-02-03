# https://leetcode.com/problems/trionic-array-i/




from typing import List

class Solution:
    def isTrionic(self, nums: List[int]) -> bool:
        n = len(nums)
        cnt = 0
        isInc = False
        for i in range(n - 1):
            if nums[i + 1] > nums[i]:
                if not isInc:
                    cnt += 1
                    isInc = True
            elif nums[i + 1] < nums[i]:
                if isInc:
                    cnt += 1
                    isInc = False
                else:
                    if cnt == 0:
                        return False
            else:
                return False
        return cnt == 3