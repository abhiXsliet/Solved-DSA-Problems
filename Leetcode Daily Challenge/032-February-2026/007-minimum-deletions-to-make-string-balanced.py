# https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/




class Solution:
    def minimumDeletions(self, s: str) -> int:
        n = len(s)
        cntA = s.count('a')
        cntB = 0
        ans  = float('inf')

        for ch in s:
            if ch == 'a':
                cntA -= 1
            
            ans = min(ans, cntB + cntA)

            if ch == 'b':
                cntB += 1

        return ans