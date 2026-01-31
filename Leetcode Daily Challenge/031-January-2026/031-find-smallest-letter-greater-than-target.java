// https://leetcode.com/problems/find-smallest-letter-greater-than-target/




class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int l = 0, r = letters.length - 1;
        char ans = letters[0];   // wrap-around default

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (letters[mid] > target) {
                ans = letters[mid];   // possible answer
                r = mid - 1;          // try to find smaller greater
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
}