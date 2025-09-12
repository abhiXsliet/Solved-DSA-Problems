// https://leetcode.com/problems/vowels-game-in-a-string/




class Solution {
    // TC : O(N)
    // SC : O(1)
    public boolean doesAliceWin(String s) {
        int cntVowels = 0;
        for (char ch : s.toCharArray()) {
            if (isVowel(ch)) cntVowels += 1;
        }
        return cntVowels == 0 ? false : true;
    }
    private static boolean isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
}