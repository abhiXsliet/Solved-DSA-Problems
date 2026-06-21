// https://leetcode.com/problems/maximum-ice-cream-bars/




class Solution {
    public int maxIceCream(int[] costs, int coins) {
        int maxCost = 0;
        for (int cost : costs)
            maxCost = Math.max(maxCost, cost);
        
        // count[c] = how many ice creams cost exactly c
        int[] count = new int[maxCost + 1];
        for (int cost : costs)
            count[cost]++;
        
        int total = 0;
        for (int cost = 1; cost <= maxCost; cost++) {
            if (count[cost] == 0)
                continue;
            
            if (coins < cost)
                break;
            
            // Jitna possible hai buy kar lo
            int buy_kiya = Math.min(count[cost], coins / cost);
            total += buy_kiya;
            coins -= (long) buy_kiya * cost > coins ? 0 : buy_kiya * cost;
        }
        
        return total;
    }
}