# https://www.geeksforgeeks.org/problems/segregate-0s-and-1s5106/1




#User function Template for python3
class Solution:
    def segregate0and1(self, arr):
        n = len(arr)
        i, j = 0, n - 1
        while i < j:
            while i < j and arr[i] == 0 :
                i += 1
            while i < j and arr[j] == 1 :
                j -= 1
            arr[i], arr[j] = arr[j], arr[i]


#{ 
 # Driver Code Starts
class IntArray:

    def __init__(self) -> None:
        pass

    def Input(self, n):
        arr = [int(i) for i in input().strip().split()]  #array input
        return arr

    def Print(self, arr):
        for i in arr:
            print(i, end=" ")
        print()


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):

        arr = list(map(int, input().strip().split()))

        obj = Solution()
        obj.segregate0and1(arr)

        print(*arr)
# } Driver Code Ends