// https://www.geeksforgeeks.org/problems/insert-interval-1666733333/1




import java.util.*;

class Solution {
    public ArrayList<int[]> insertInterval(int[][] intervals, int[] newInterval) {
        // return approach_1(intervals, newInterval);
        return approach_2(intervals, newInterval);
    }
    
    // TC : O(N)
    // SC : O(N)
    private ArrayList<int[]> approach_2(int[][] intervals, int[] newIntervals) {
        int n = intervals.length;
        
        ArrayList<int[]> result = new ArrayList<>();
        int i = 0;
        
        // Step-1 : Left Part : Intervals which ends before the newIntervals start
        while (i < n && intervals[i][1] < newIntervals[0]) {
            result.add(intervals[i]);
            i ++;
        }
        
        // Step-2 : Merge Part : Merge overlapping intervals
        while (i < n && intervals[i][0] <= newIntervals[1]) {
            newIntervals[0] = Math.min(newIntervals[0], intervals[i][0]);
            newIntervals[1] = Math.max(newIntervals[1], intervals[i][1]);
            i ++;
        }
        result.add(newIntervals);
        
        // Step-3 : Right Part : Intervals which start after newInterval end
        while (i < n) {
            result.add(intervals[i]);
            i ++;
        }
        
        return result;
    }
    
    // TC : O(N * log(N))
    // SC : O(N)
    private ArrayList<int[]> approach_1(int[][] intervals, int[] newInterval) {
        ArrayList<int[]> intervalList = new ArrayList<>(Arrays.asList(intervals));
        intervalList.add(newInterval);
        
        intervalList.sort(Comparator.comparingInt(a -> a[0]));
        
        ArrayList<int[]> result = new ArrayList<>();
        
        for (int[] interval : intervalList) {
            if (result.isEmpty() || interval[0] > result.get(result.size() - 1)[1]) {
                result.add(interval);
            } else {
                result.get(result.size() - 1)[1] = Math.max(result.get(result.size() - 1)[1], interval[1]);
            }
        }
        
        return result;
    }
}