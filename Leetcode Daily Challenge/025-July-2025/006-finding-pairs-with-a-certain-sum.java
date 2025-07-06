// https://leetcode.com/problems/finding-pairs-with-a-certain-sum/




import java.util.*;

class FindSumPairs {
    private int[] a, b;
    private Map<Integer, Integer> mpp;

    public FindSumPairs(int[] nums1, int[] nums2) {
        this.a = nums1;
        this.b = nums2;
        this.mpp = new HashMap<>();

        for (int num : nums2) {
            mpp.put(num, mpp.getOrDefault(num, 0) + 1);
        }    
    }
    
    public void add(int index, int val) {
        int original = b[index];
        b[index]    += val;
        mpp.put(original, mpp.get(original) - 1);
        mpp.put(b[index], mpp.getOrDefault(b[index], 0) + 1);
    }
    
    public int count(int tot) {
        int ans = 0;
        for (int num : a) {
            int tar = (tot - num);
            ans += mpp.getOrDefault(tar, 0);
        }
        return ans;
    }
}

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs obj = new FindSumPairs(nums1, nums2);
 * obj.add(index,val);
 * int param_2 = obj.count(tot);
 */