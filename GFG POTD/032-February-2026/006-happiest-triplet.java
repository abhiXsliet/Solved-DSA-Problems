// https://www.geeksforgeeks.org/problems/happiest-triplet2921/1/




import java.util.*;

class Solution {
    int[] smallestDiff(int a[], int b[], int c[]) {
        Arrays.sort(a);
        Arrays.sort(b);
        Arrays.sort(c);

        int i = 0, j = 0, k = 0;
        int bestDiff = Integer.MAX_VALUE;
        int bestSum = Integer.MAX_VALUE;

        int x = 0, y = 0, z = 0;

        while (i < a.length && j < b.length && k < c.length) {

            int mn = Math.min(a[i], Math.min(b[j], c[k]));
            int mx = Math.max(a[i], Math.max(b[j], c[k]));
            int diff = mx - mn;
            int sum = a[i] + b[j] + c[k];

            if (diff < bestDiff || (diff == bestDiff && sum < bestSum)) {
                bestDiff = diff;
                bestSum = sum;
                x = a[i];
                y = b[j];
                z = c[k];
            }

            // move pointer of minimum element
            if (mn == a[i]) i++;
            else if (mn == b[j]) j++;
            else k++;
        }

        int[] res = new int[]{x, y, z};
        Arrays.sort(res); // increasing
        // reverse to get decreasing
        return new int[]{res[2], res[1], res[0]};
    }
}