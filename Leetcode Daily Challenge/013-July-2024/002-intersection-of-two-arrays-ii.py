# https://leetcode.com/problems/intersection-of-two-arrays-ii/




class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        # return self.approach_1(nums1, nums2)

        return self.approach_2(nums1, nums2)

    # TC : O(N)
    # SC : O(N)
    def approach_1(self, nums1, nums2):
        freq = [0] * 1001
        
        for num in nums2:
            freq[num] += 1
        
        result = []
        for num in nums1:
            if freq[num] > 0:
                freq[num] -= 1
                result.append(num)

        return result

    # TC : O(max(NlogN, MlogM)
    # SC : O(1)
    def approach_2(self, nums1, nums2):
        nums1.sort()
        nums2.sort()
        result = []
        i, j, m, n = 0, 0, len(nums1), len(nums2)
        while i < m and j < n:
            if nums1[i] == nums2[j]:
                result.append(nums1[i])
                i += 1
                j += 1
            elif nums1[i] < nums2[j]:
                i += 1
            else:
                j += 1
        return result