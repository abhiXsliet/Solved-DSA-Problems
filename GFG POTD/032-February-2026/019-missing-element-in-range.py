# https://www.geeksforgeeks.org/problems/missing-element-in-range/1/




class Solution:
    # TC : O(N)
    # SC : O(N)
    def approach_1(self, arr, low, high):
        st = set(arr)
        result = []
        for num in range(low, high + 1):
            if num not in st:
                result.append(num)
        return result
        
    # TC : O(N*log(N))
    # SC : O(1)
    def approach_2(self, arr, low, high):
        n = len(arr)
        arr.sort()
        
        idx = 0
        while idx < n and arr[idx] < low:
            idx += 1
            
        i, x = idx, low
        result = []
        
        while i < n and x <= high:
            if x != arr[i]:
                result.append(x)
            else:
                i += 1
                while i < n and arr[i] == arr[i - 1]:
                    i += 1
            x += 1
            
        while x <= high:
            result.append(x)
            x += 1
            
        return result
        
    def missingRange(self, arr, low, high):
        # return self.approach_1(arr, low, high)
        return self.approach_2(arr, low, high)