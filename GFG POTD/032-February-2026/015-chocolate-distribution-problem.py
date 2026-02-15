# https://www.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1/



class Solution:

    def findMinDiff(self, arr,M):
        result = float('Inf')
        arr.sort()
        i, j = 0, M - 1

        while j < len(arr):
            result = min(result, arr[j] - arr[i])
            i += 1
            j += 1

        return result