// https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-i/




class Solution {
    public int earliestFinishTime(int[] landStartTime, int[] landDuration, int[] waterStartTime, int[] waterDuration) {
        int tEarliest = Integer.MAX_VALUE;
        for (int i = 0; i < landStartTime.length; i ++) {
            int duration = landStartTime[i] + landDuration[i];
            for (int j = 0; j < waterStartTime.length; j ++) {
                int temp = duration;
                if (waterStartTime[j] > temp) temp += Math.abs(waterStartTime[j] - temp);
                temp += waterDuration[j];
                tEarliest = Math.min(tEarliest, temp);
            }
        }
        for (int i = 0; i < waterStartTime.length; i ++) {
            int duration = waterStartTime[i] + waterDuration[i];
            for (int j = 0; j < landDuration.length; j ++) {
                int temp = duration;
                if (landStartTime[j] > temp) temp += Math.abs(landStartTime[j] - temp);;
                temp += landDuration[j];
                tEarliest = Math.min(tEarliest, temp);
            }
        }
        return tEarliest;
    }
}