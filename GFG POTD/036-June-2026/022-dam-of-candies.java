// https://www.geeksforgeeks.org/problems/dam-of-candies--141631/1/




import java.util.*;

class Solution {
    public int maxArea(List<Integer> height) {
        int n = height.size();
        int i = 0, j = n - 1;
        int maxArea = 0;
        while (i < j) {
            int breadth = j - i - 1;
            int length = Math.min(height.get(i), height.get(j));
            int area = length * breadth;
            maxArea = Math.max(maxArea, area);
            if (height.get(i) < height.get(j)) i ++;
            else j --;
        }
        return maxArea;
    }
}