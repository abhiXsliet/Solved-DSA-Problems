// https://leetcode.com/problems/count-elements-with-maximum-frequency/




class Solution {
    public int maxFrequencyElements(int[] nums) {
        int[] freq = new int[101];
        int maxFreq = 0;
        for (int num : nums) {
            freq[num] ++;
            maxFreq = Math.max(maxFreq, freq[num]);
        }

        int result = 0;
        for (int i = 0; i <= 100; i ++) {
            if (freq[i] == maxFreq) {
                result += freq[i];
            }
        }
        return result;
    }
}