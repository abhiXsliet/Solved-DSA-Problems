# https://leetcode.com/problems/pass-the-pillow/




class Solution:
    def passThePillow(self, n: int, time: int) -> int:
        # return self.way_1(n, time)
        # return self.way_2(n, time)
        return self.approach_2(n, time)

    # TC : O(time)
    # SC : O(1)
    def way_1(self, n, time):
        person    = 1
        cntTime   = 1 
        # Change of Direction 
        direction = 0  
        while cntTime <= time:
            if direction == 0:
                person += 1
                if (person == n):
                    direction = 1
            else:
                person -= 1
                if (person == 1):
                    direction = 0
            cntTime += 1
        
        return person

    # TC : O(time)
    # SC : O(1)
    def way_2(self, n, time):
        person    = 1 
        direction = 1 # direction L ---> R or R ---> L
        while time > 0:
            if 1 <= person + direction <= n:
                person += direction
                time -= 1
            else:
                direction *= -1
        return person

    # TC : O(1)
    # SC : O(1)
    def approach_2(self, n, time):
        fullRnd  = time // (n - 1)
        timeLeft = time % (n - 1)

        if fullRnd % 2 == 1:  # Odd Full Round
            return n - timeLeft
        return timeLeft + 1 # Even Full Round