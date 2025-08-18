// https://leetcode.com/problems/24-game/




import java.util.*;

class Solution {
    private final double epsilon = 1e-2;

    public boolean judgePoint24(int[] cards) {
        List<Double> nums = new ArrayList<>();
        for (int i = 0; i < cards.length; i ++) {
            nums.add(1.0 * cards[i]);
        }
        return solve(nums);
    }

    // TC : O(1)
    // SC : O(1)
    private boolean solve(List<Double> cards) {
        if (cards.size() == 1) {
            return Math.abs(24 - cards.get(0)) <= epsilon;
        }

        for (int i = 0; i < cards.size(); i ++) {
            for (int j = 0; j < cards.size(); j ++) {
                if (i == j) continue;

                List<Double> temp = new ArrayList<>();
                for (int k = 0; k < cards.size(); k ++) {
                    if (k != i && k != j) {
                        temp.add(cards.get(k));
                    }
                }

                double a = cards.get(i), b = cards.get(j);
                List<Double> operations = new ArrayList<>(List.of(a + b, a - b, b - a, a * b));

                if (Math.abs(b) > 0.0) {
                    operations.add(a / b);
                }

                if (Math.abs(a) > 0.0) {
                    operations.add(b / a);
                }

                for (double val : operations) {
                    temp.add(val);
                    if (solve(temp)) return true;
                    temp.remove(temp.size() - 1);
                }
            }
        }
        return false;
    }
}