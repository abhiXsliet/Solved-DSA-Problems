// https://www.geeksforgeeks.org/problems/maximum-sum-combination/1




import java.util.*;

class Solution {
    public ArrayList<Integer> topKSumPairs(int[] a, int[] b, int k) {
        int n = a.length;
        
        Arrays.sort(a);
        Arrays.sort(b);
        
        ArrayList<Integer> result = new ArrayList<>();
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        Set<String> visited = new HashSet<>();
        
        int i = n - 1, j = n - 1;
        pq.offer(new Pair(a[i] + b[j], i, j));
        visited.add(i + "," + j);
        
        while (result.size() < k && !pq.isEmpty()) {
            Pair curr = pq.poll();
            result.add(curr.sum);
            
            i = curr.first;
            j = curr.second;
            
            if (i - 1 >= 0 && !visited.contains((i - 1) + "," + j)) {
                pq.offer(new Pair(a[i - 1] + b[j], (i - 1), j));
                visited.add((i - 1) + "," + j);
            }
            
            if (j - 1 >= 0 && !visited.contains(i + "," + (j - 1))) {
                pq.offer(new Pair(a[i] + b[j - 1], i, (j - 1)));
                visited.add(i + "," + (j - 1));
            }
        }
        
        return result;
    }
    
    static class Pair implements Comparable<Pair> {
        int sum;
        int first, second;
        Pair(int sum, int i, int j) {
            this.sum = sum;
            this.first = i;
            this.second = j;
        }
        
        @Override
        public int compareTo(Pair other) {
            return Integer.compare(other.sum, this.sum);
        }
    }
}