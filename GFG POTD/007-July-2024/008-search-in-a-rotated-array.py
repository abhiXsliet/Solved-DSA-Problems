# https://www.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1



#User function Template for python3
class Solution:
    # TC : O(log(N)) Where N = Length of array
    # SC : O(1)
    def search(self,arr,key):
        n = len(arr)
        low = 0
        high = n - 1
        while low <= high:
            mid = (low + high) >> 1
            if arr[mid] == key:
                return mid
            # check which part is sorted
            if arr[low] <= arr[mid]:  # left part is sorted
                if key >= arr[low] and key <= arr[mid]:
                    high = mid - 1
                else:
                    low  = mid + 1
            else:    # right part is sorted
                if key >= arr[mid] and key <= arr[high]:
                    low = mid + 1
                else:
                    high = mid - 1
        return -1

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())

    for _ in range(t):
        A = list(map(int, input().strip().split()))
        k = int(input())
        ob = Solution()
        print(ob.search(A, k))

# } Driver Code Ends