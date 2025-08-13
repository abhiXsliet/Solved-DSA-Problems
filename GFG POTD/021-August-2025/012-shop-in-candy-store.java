// https://www.geeksforgeeks.org/problems/shop-in-candy-store1145/1




import java.util.*;

class Solution {
    // TC : O(N*log(N))
    // SC : O(1)
    public ArrayList<Integer> minMaxCandy(int[] prices, int k) {
        int n = prices.length;
        
        Arrays.sort(prices);
        
        int minAmount = 0, maxAmount = 0;
        int i = 0, i_ = n - 1, j_ = 0, j = n - 1;
        
        while (i <= i_ || j_ <= j) {
            if (i <= i_) {
                minAmount += prices[i];
                i_ -= k;
                i ++;
            } 
            if (j_ <= j) {
                maxAmount += prices[j];
                j_ += k;
                j --;
            }
        }
        
        return new ArrayList<>(Arrays.asList(minAmount, maxAmount));
    }
}