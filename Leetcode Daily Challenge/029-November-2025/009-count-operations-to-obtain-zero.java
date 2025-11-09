// https://leetcode.com/problems/count-operations-to-obtain-zero/




class Solution {
    public int countOperations(int num1, int num2) {
        // return approach_1(num1, num2);
        return approach_2(num1, num2);
    }

    // TC : O(min(log(num1, num2)))
    private int approach_2(int num1, int num2) {
        int opr = 0;
        while (num1 > 0 && num2 > 0) {
            opr  += (num1 / num2);
            num1 %= num2;

            num1 = num1 ^ num2;
            num2 = num2 ^ num1;
            num1 = num1 ^ num2;
        }
        return opr;
    }

    // TC : O(max(num1, num2))
    private int approach_1(int num1, int num2) {
        int opr = 0;
        while (num1 > 0 && num2 > 0) {
            if (num1 >= num2) {
                num1 -= num2;
            } else {
                num2 -= num1;
            }
            opr += 1;
        }
        return opr;
    }
}