// https://leetcode.com/problems/angle-between-hands-of-a-clock/




class Solution {
    public double angleClock(int hour, int minutes) {
        double oneHrDeg  = 360 / 12;
        double oneMinDeg = 360 / 60;

        double angleByHoursPerMin = oneHrDeg / 60;  // 1 hour angle / 60 deg.

        double hourAngle = ((hour % 12) * oneHrDeg) + (minutes * angleByHoursPerMin);
        double minsAngle = minutes * oneMinDeg;
        
        double resAngle = Math.abs(hourAngle - minsAngle);
        return Math.min(360 - resAngle, resAngle);
    }
}