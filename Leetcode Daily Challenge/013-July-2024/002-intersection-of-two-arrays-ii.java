// https://leetcode.com/problems/intersection-of-two-arrays-ii/



import java.util.*;

class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        // return approach_1(nums1, nums2);

        return approach_2(nums1, nums2);
    }

    // TC : O( max(N*log(N), M*log(M)) )
    // SC : O( 1 )
    private static int[] approach_2(int[] nums1, int[] nums2) {
        int m = nums1.length;
        int n = nums2.length;

        Arrays.sort(nums1);
        Arrays.sort(nums2);

        int i = 0;
        int j = 0;

        List<Integer> result = new ArrayList<>();

        while (i < m && j < n) {
            if (nums1[i] == nums2[j]) {
                result.add(nums1[i]);
                i ++;
                j ++;

            } else if (nums1[i] < nums2[j]) {
                i ++;
            } else j ++;
        }

        int[] finalResult = new int[result.size()];
        for (int k = 0; k < result.size(); k ++) {
            finalResult[k] = result.get(k);
        }

        return finalResult;
    }

    // TC : O(N)
    // SC : O(1001)
    private static int[] approach_1(int[] nums1, int[] nums2) {
        int m = nums1.length;
        int n = nums2.length;
        
        int[] freq = new int[1001];

        for (int num : nums2) freq[num] ++;

        List<Integer> result = new ArrayList<>();
        for (int num : nums1) {
            if (freq[num] > 0) {
                freq[num] --;
                result.add(num);
            }
        }

        int[] resultArray = new int[result.size()];  // convert the list into array
        for (int i = 0; i < result.size(); i ++) {
            resultArray[i] = result.get(i);
        }
        return resultArray;
    }
}