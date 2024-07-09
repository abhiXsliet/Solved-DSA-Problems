# https://www.geeksforgeeks.org/problems/three-sum-closest/1




#User function Template for python3
# arr    : list of integers denoting the elements of the array
# target : as specified in the problem statement
class Solution:
    # TC : O(N^2)
    # SC : O(1)
    def threeSumClosest(self, arr, target):
        arr.sort()
        n = len(arr)
        closest_sum = float('inf')
        min_diff = float('inf')
    
        for i in range(n - 2):
            low  = i + 1
            high = n - 1
    
            while low < high:
                current_sum = arr[i] + arr[low] + arr[high]
                current_diff = abs(current_sum - target)
    
                if current_diff < min_diff:
                    min_diff = current_diff
                    closest_sum = current_sum
                elif current_diff == min_diff:
                    closest_sum = max(closest_sum, current_sum)
    
                if current_sum < target:
                    low += 1
                else:
                    high -= 1
        return closest_sum
        
#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__':
    t = int(input())

    for _ in range(t):
        A = list(map(int, input().strip().split()))
        k = int(input())
        ob = Solution()
        print(ob.threeSumClosest(A, k))

# } Driver Code Ends