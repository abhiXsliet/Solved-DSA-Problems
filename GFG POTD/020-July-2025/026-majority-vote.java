// https://www.geeksforgeeks.org/problems/majority-vote/1




import java.util.*;

class Solution {
    // TC : O(N)
    // SC : O(1)
    public ArrayList<Integer> findMajority(int[] arr) {
        int n = arr.length;
        
        int ele1 = -1, ele2 = -1, cnt1 = 0, cnt2 = 0;
        
        for (int num : arr) {
            if (num == ele1) cnt1 += 1;
            else if (num == ele2) cnt2 += 1;
            else if (cnt1 == 0) {
                ele1 = num;
                cnt1 = 1;
            } else if (cnt2 == 0) {
                ele2 = num;
                cnt2 = 1;
            } else {
                cnt1 -= 1;
                cnt2 -= 1;
            }
        }
        
        cnt1 = 0;
        cnt2 = 0;
        for (int num : arr) {
            if (num == ele1) cnt1 += 1;
            if (num == ele2) cnt2 += 1;
        }
        
        ArrayList<Integer> result = new ArrayList<>();
        if (cnt1 > n/3) result.add(ele1);
        if (cnt2 > n/3) result.add(ele2);
        Collections.sort(result);
        return result;
    }
}