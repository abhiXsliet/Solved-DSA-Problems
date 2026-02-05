# https://www.geeksforgeeks.org/problems/maximize-number-of-1s0905/1/




class Solution:
    def maxOnes(self, arr, k):
        n = len(arr)
        i = 0
        j = 0
        cntZero = 0
        result = 0
        while j < n:
            if arr[j] == 0:
                cntZero += 1
            while i <= j and cntZero > k:
                if arr[i] == 0:
                    cntZero -= 1
                i += 1
            result = max(result, j - i + 1)
            j += 1
        return result