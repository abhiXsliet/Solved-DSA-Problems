# https://leetcode.com/problems/find-the-winner-of-the-circular-game/



from collections import deque

class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        # return self.solve(n, k)          # Simulation
        # return self.solveQ(n, k)         # Simulation Using Queue
        # return self.solve_josephus(n, k) # Recursive Approach Of Simulation
        return self.solve_rec(n, k) + 1    # +1 to get the name of the person (i.e., idx + 1 == el)
    
    # TC : O(N)
    # SC : O(N) -> Recursive Depth
    def solve_rec(self, n, k):
        if n == 1:
            return 0
        
        idx = self.solve_rec(n - 1, k)
        idx = (idx + k) % n    # to get the original index of element prior deletion

        return idx

    # TC : O(N)
    # SC : O(N) + O(N) = O(N)
    def solve_josephus(self, n, k):
        arr = list(range(1, n + 1))
        return self.func(arr, k, 0)

    # TC : O(N)
    # SC : O(N) -> Recursive depth
    def func(self, arr, k, idx):
        n = len(arr)
        if n == 1:
            return arr[0]

        removeIdx = (idx + k - 1) % n
        arr.pop(removeIdx)

        return self.func(arr, k, removeIdx)

    # TC : O(N^2)
    # SC : O(N)
    def solveQ(self, n, k):
        q = deque(range(1, n + 1))

        while len(q) > 1:
            for _ in range(1, k):
                q.append(q.popleft())
            q.popleft()

        return q[0]

    # TC : O(N^2)
    # SC : O(N)
    def solve(self, n, k):
        arr = list(range(1, n + 1))

        i = 0
        while len(arr) > 1: # O(N)
            i = (i + k - 1) % len(arr)    # index to be erased
            arr.pop(i)       # erase element at index i : O(N)

        return arr[0]