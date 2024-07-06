// https://leetcode.com/problems/pass-the-pillow/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(time)
    // SC : O(1)
    int way_1(int n, int time) {
        int person    = 1;
        int cntTime   = 1; 
        // Change of Direction 
        int direction = 0;  
        while (cntTime <= time) {
            if (direction == 0) {
                person += 1;
                if (person == n) {
                    direction = 1;
                }
            } else {
                person -= 1;
                if (person == 1) {
                    direction = 0;
                }
            }
            cntTime += 1;
        }
        return person;
    }

    // TC : O(time)
    // SC : O(1)
    int way_2(int n, int time) {
        int person    = 1; 
        int direction = 1; // direction L ---> R or R ---> L
        while (time > 0) {
            if (person + direction >= 1 && person + direction <= n) {
               person += direction;
               time --;
            } else {
                direction *= -1;
            }
        }
        return person;
    }

    // TC : O(1)
    // SC : O(1)
    int approach_2(int n, int time) {
        int fullRnd  = time / (n - 1);
        int timeLeft = time % (n - 1);

        if (fullRnd % 2) {  // Odd Full Round
            return n - timeLeft;
        } 
        return timeLeft + 1; // Even Full Round
    }
public:
    int passThePillow(int n, int time) {
        // return way_1(n, time);

        // return way_2(n, time);

        return approach_2(n, time);
    }
};