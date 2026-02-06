# https://www.geeksforgeeks.org/problems/happiest-triplet2921/1/




class Solution:
    # TC : O(N*log(N))
    # SC : O(1)
    def smallestDiff(self,a, b, c):
        a.sort()
        b.sort()
        c.sort()
        
        i = j = k = 0 # 3-pointers
        x = y = z = 0 # 3-elements
        
        bestDiff = float('inf')
        bestSum  = float('inf')
        
        while i < len(a) and j < len(b) and k < len(c):

            mn = min(a[i], min(b[j], c[k]))
            mx = max(a[i], max(b[j], c[k]))
            
            currDiff = mx - mn
            currSum  = a[i] + b[j] + c[k]
            
            if currDiff < bestDiff or (currDiff == bestDiff and currSum < bestSum):
                bestSum  = currSum
                bestDiff = currDiff
                x, y, z = a[i], b[j], c[k]
                
            # move the pointer of minimum element
            if mn == a[i]:
                i += 1
            elif mn == b[j]:
                j += 1
            else:
                k += 1
                
        res = sorted([x, y, z])
        return [res[2], res[1], res[0]]