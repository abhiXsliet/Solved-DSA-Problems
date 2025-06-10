// https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/




class Solution {
    public int maxDifference(String s) {
        int n = s.length();
        
        int[] freq = new int[26];

        for (char ch : s.toCharArray()) {
            freq[ch - 'a'] ++;
        }

        int maxOdd = 0, minEven = n;

        for (int f : freq) {
            if (f == 0) continue;
            if (f % 2 == 1) {
                maxOdd = Math.max(maxOdd, f);
            } else {
                minEven = Math.min(minEven, f);
            }
        }

        return maxOdd - minEven;
    }
}