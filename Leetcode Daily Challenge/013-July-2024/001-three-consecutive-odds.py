# https://leetcode.com/problems/three-consecutive-odds/



class Solution(object):
    # TC : O(N)
    # SC : O(1)
    def threeConsecutiveOdds(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        for i in range(len(arr) - 2):
            if arr[i] & 1 and arr[i + 1] & 1 and arr[i + 2] & 1:
                return True
        return False